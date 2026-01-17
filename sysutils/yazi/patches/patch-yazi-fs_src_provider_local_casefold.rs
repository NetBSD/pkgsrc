$NetBSD: patch-yazi-fs_src_provider_local_casefold.rs,v 1.2 2026/01/17 07:37:52 wiz Exp $

fix build on NetBSD
https://github.com/sxyazi/yazi/pull/3506

--- yazi-fs/src/provider/local/casefold.rs.orig	2026-01-04 04:35:06.000000000 +0000
+++ yazi-fs/src/provider/local/casefold.rs
@@ -10,13 +10,7 @@ pub(super) async fn casefold(path: impl AsRef<Path>) -
 	tokio::task::spawn_blocking(move || casefold_impl(path)).await?
 }
 
-#[cfg(any(
-	target_os = "macos",
-	target_os = "netbsd",
-	target_os = "openbsd",
-	target_os = "freebsd",
-	target_os = "windows"
-))]
+#[cfg(any(target_os = "macos", target_os = "windows", target_os = "freebsd"))]
 fn casefold_impl(path: PathBuf) -> io::Result<PathBuf> {
 	let mut it = path.components();
 	let mut parts = vec![];
@@ -47,7 +41,6 @@ fn casefold_impl(path: PathBuf) -> io::Result<PathBuf>
 }
 
 #[cfg(any(target_os = "linux", target_os = "android"))]
-#[allow(irrefutable_let_patterns)]
 fn casefold_impl(path: PathBuf) -> io::Result<PathBuf> {
 	use std::{ffi::{CString, OsStr, OsString}, fs::File, os::{fd::{AsRawFd, FromRawFd}, unix::{ffi::{OsStrExt, OsStringExt}, fs::MetadataExt}}};
 
@@ -65,14 +58,8 @@ fn casefold_impl(path: PathBuf) -> io::Result<PathBuf>
 	};
 
 	// Fast path: if the `/proc/self/fd/N` matches
-	if let Ok(p) = std::fs::read_link(format!("/proc/self/fd/{}", file.as_raw_fd()))
-		&& let path = path.as_os_str()
-		&& let Some(b) = p.as_os_str().as_bytes().get(..path.len())
-		&& b.eq_ignore_ascii_case(path.as_bytes())
-	{
-		let mut b = p.into_os_string().into_vec();
-		b.truncate(path.len());
-		return Ok(PathBuf::from(OsString::from_vec(b)));
+	if let Some(p) = try_from_fd(file.as_raw_fd(), path) {
+		return Ok(p);
 	}
 
 	// Fast path: if the file isn't a symlink
@@ -113,12 +100,64 @@ fn casefold_impl(path: PathBuf) -> io::Result<PathBuf>
 	}
 }
 
-#[cfg(any(
-	target_os = "macos",
-	target_os = "netbsd",
-	target_os = "openbsd",
-	target_os = "freebsd"
-))]
+#[cfg(any(target_os = "netbsd", target_os = "openbsd"))]
+#[allow(irrefutable_let_patterns)]
+fn casefold_impl(path: PathBuf) -> io::Result<PathBuf> {
+	use std::{ffi::{CString, OsStr, OsString}, fs::File, os::{fd::{AsRawFd, FromRawFd}, unix::{ffi::{OsStrExt, OsStringExt}, fs::MetadataExt}}};
+
+	use libc::{O_NOFOLLOW, O_RDONLY};
+
+	let cstr = CString::new(path.into_os_string().into_vec())?;
+	let path = Path::new(OsStr::from_bytes(cstr.as_bytes()));
+	let Some((parent, name)) = path.parent().zip(path.file_name()) else {
+		return Ok(PathBuf::from(OsString::from_vec(cstr.into_bytes())));
+	};
+
+	// Fast path: if it's not a symlink
+	if let fd = unsafe { libc::open(cstr.as_ptr(), O_RDONLY | O_NOFOLLOW) }
+		&& fd >= 0
+		&& let file = unsafe { File::from_raw_fd(fd) }
+	{
+		if let Some(p) = try_from_fd(file.as_raw_fd(), path) {
+			return Ok(p);
+		} else if let Some(n) = path.canonicalize()?.file_name() {
+			return Ok(parent.join(n));
+		} else {
+			return Err(io::Error::other("Cannot get filename"));
+		}
+	};
+
+	// Fallback: scan the directory for matching inodes
+	let (meta, mut names) = (std::fs::symlink_metadata(path)?, vec![]);
+	for entry in std::fs::read_dir(parent)? {
+		let entry = entry?;
+		let n = entry.file_name(); // TODO: use `file_name_ref()` when stabilized
+
+		if n == name {
+			return Ok(PathBuf::from(OsString::from_vec(cstr.into_bytes())));
+		} else if let m = entry.metadata()?
+			&& m.ino() == meta.ino()
+			&& m.dev() == meta.dev()
+		{
+			names.push(n);
+		}
+	}
+
+	if names.len() == 1 {
+		// No hardlink that shares the same inode
+		Ok(parent.join(&names[0]))
+	} else if let mut it = names.iter().enumerate().filter(|&(_, n)| n.eq_ignore_ascii_case(name))
+		&& let Some((i, _)) = it.next()
+		&& it.next().is_none()
+	{
+		// Case-insensitive match
+		Ok(parent.join(&names[i]))
+	} else {
+		Err(io::Error::from(io::ErrorKind::NotFound))
+	}
+}
+
+#[cfg(any(target_os = "macos", target_os = "freebsd"))]
 fn final_path(path: &Path) -> io::Result<PathBuf> {
 	use std::{ffi::{CStr, CString, OsString}, os::{fd::{AsRawFd, FromRawFd, OwnedFd}, unix::ffi::{OsStrExt, OsStringExt}}};
 
@@ -177,4 +216,33 @@ fn final_path(path: &Path) -> io::Result<PathBuf> {
 		Either::Right(len) => inner(&file, &mut vec![0u16; len as usize])?
 			.left_or_err(|| io::Error::new(io::ErrorKind::InvalidData, "path too long")),
 	}
+}
+
+#[cfg(any(
+	target_os = "linux",
+	target_os = "android",
+	target_os = "netbsd",
+	target_os = "openbsd"
+))]
+fn try_from_fd(fd: std::os::fd::RawFd, needle: &Path) -> Option<PathBuf> {
+	use std::{ffi::OsString, os::unix::ffi::{OsStrExt, OsStringExt}};
+
+	#[cfg(any(target_os = "linux", target_os = "android"))]
+	let cand = format!("/proc/self/fd/{fd}");
+	#[cfg(target_os = "netbsd")]
+	let cand = format!("/proc/curproc/fd/{fd}");
+	#[cfg(target_os = "openbsd")]
+	let cand = format!("/dev/fd/{fd}");
+
+	if let Ok(p) = std::fs::read_link(cand)
+		&& let needle = needle.as_os_str()
+		&& let Some(b) = p.as_os_str().as_bytes().get(..needle.len())
+		&& b.eq_ignore_ascii_case(needle.as_bytes())
+	{
+		let mut b = p.into_os_string().into_vec();
+		b.truncate(needle.len());
+		return Some(PathBuf::from(OsString::from_vec(b)));
+	}
+
+	None
 }
