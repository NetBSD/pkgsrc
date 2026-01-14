$NetBSD: patch-yazi-fs_src_provider_local_casefold.rs,v 1.1 2026/01/14 15:20:41 wiz Exp $

libc on NetBSD does not provide O_SYMLINK.
Workaround for
https://github.com/sxyazi/yazi/issues/3497

--- yazi-fs/src/provider/local/casefold.rs.orig	2026-01-14 15:13:02.540343017 +0000
+++ yazi-fs/src/provider/local/casefold.rs
@@ -122,10 +122,10 @@ fn final_path(path: &Path) -> io::Result<PathBuf> {
 fn final_path(path: &Path) -> io::Result<PathBuf> {
 	use std::{ffi::{CStr, CString, OsString}, os::{fd::{AsRawFd, FromRawFd, OwnedFd}, unix::ffi::{OsStrExt, OsStringExt}}};
 
-	use libc::{F_GETPATH, O_RDONLY, O_SYMLINK, PATH_MAX};
+	use libc::{F_GETPATH, O_RDONLY, PATH_MAX};
 
 	let cstr = CString::new(path.as_os_str().as_bytes())?;
-	let fd = match unsafe { libc::open(cstr.as_ptr(), O_RDONLY | O_SYMLINK) } {
+	let fd = match unsafe { libc::open(cstr.as_ptr(), O_RDONLY) } {
 		ret if ret < 0 => return Err(io::Error::last_os_error()),
 		ret => unsafe { OwnedFd::from_raw_fd(ret) },
 	};
