# $NetBSD: patch-.._vendor_uucore-0.6.0_src_lib_features_safe__traversal.rs,v 1.1 2026/03/02 15:32:26 pin Exp $

Fix build on NetBSD

--- ../vendor/uucore-0.6.0/src/lib/features/safe_traversal.rs.orig	2006-07-24 03:21:28.000000000 +0200
+++ ../vendor/uucore-0.6.0/src/lib/features/safe_traversal.rs	2026-03-02 15:38:09.721008601 +0100
@@ -9,26 +9,58 @@
 // Available on Unix
 //
 // spell-checker:ignore CLOEXEC RDONLY TOCTOU closedir dirp fdopendir fstatat openat REMOVEDIR unlinkat smallfile
-// spell-checker:ignore RAII dirfd fchownat fchown FchmodatFlags fchmodat fchmod
+// spell-checker:ignore RAII dirfd fchownat fchown FchmodatFlags fchmodat fchmod mkdirat CREAT WRONLY ELOOP ENOTDIR
 
 #[cfg(test)]
 use std::os::unix::ffi::OsStringExt;
 
 use std::ffi::{CString, OsStr, OsString};
+use std::fs;
 use std::io;
 use std::os::unix::ffi::OsStrExt;
-use std::os::unix::io::{AsFd, AsRawFd, BorrowedFd, FromRawFd, OwnedFd, RawFd};
+use std::os::unix::io::{AsFd, AsRawFd, BorrowedFd, FromRawFd, IntoRawFd, OwnedFd, RawFd};
 use std::path::{Path, PathBuf};
 
 use nix::dir::Dir;
-use nix::fcntl::{OFlag, openat};
+use nix::fcntl::{openat, OFlag};
 use nix::libc;
-use nix::sys::stat::{FchmodatFlags, FileStat, Mode, fchmodat, fstatat};
-use nix::unistd::{Gid, Uid, UnlinkatFlags, fchown, fchownat, unlinkat};
+use nix::sys::stat::{fchmodat, fstatat, mkdirat, FchmodatFlags, FileStat, Mode};
+use nix::unistd::{fchown, fchownat, unlinkat, Gid, Uid, UnlinkatFlags};
 use os_display::Quotable;
 
 use crate::translate;
 
+/// Enum to specify symlink following behavior.
+///
+/// This replaces boolean `follow_symlinks` parameters for better readability
+/// at call sites. Instead of `open(path, true)`, use `open(path, SymlinkBehavior::Follow)`.
+#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
+pub enum SymlinkBehavior {
+    /// Follow symlinks (resolve to their target)
+    #[default]
+    Follow,
+    /// Do not follow symlinks (operate on the symlink itself)
+    NoFollow,
+}
+
+impl SymlinkBehavior {
+    /// Returns `true` if symlinks should be followed
+    #[inline]
+    pub fn should_follow(self) -> bool {
+        matches!(self, Self::Follow)
+    }
+}
+
+impl From<bool> for SymlinkBehavior {
+    fn from(follow: bool) -> Self {
+        if follow {
+            Self::Follow
+        } else {
+            Self::NoFollow
+        }
+    }
+}
+
 // Custom error types for better error reporting
 #[derive(thiserror::Error, Debug)]
 pub enum SafeTraversalError {
@@ -105,8 +137,15 @@
 
 impl DirFd {
     /// Open a directory and return a file descriptor
-    pub fn open(path: &Path) -> io::Result<Self> {
-        let flags = OFlag::O_RDONLY | OFlag::O_DIRECTORY | OFlag::O_CLOEXEC;
+    ///
+    /// # Arguments
+    /// * `path` - The path to the directory to open
+    /// * `symlink_behavior` - Whether to follow symlinks when opening
+    pub fn open(path: &Path, symlink_behavior: SymlinkBehavior) -> io::Result<Self> {
+        let mut flags = OFlag::O_RDONLY | OFlag::O_DIRECTORY | OFlag::O_CLOEXEC;
+        if !symlink_behavior.should_follow() {
+            flags |= OFlag::O_NOFOLLOW;
+        }
         let fd = nix::fcntl::open(path, flags, Mode::empty()).map_err(|e| {
             SafeTraversalError::OpenFailed {
                 path: path.into(),
@@ -117,10 +156,17 @@
     }
 
     /// Open a subdirectory relative to this directory
-    pub fn open_subdir(&self, name: &OsStr) -> io::Result<Self> {
+    ///
+    /// # Arguments
+    /// * `name` - The name of the subdirectory to open
+    /// * `symlink_behavior` - Whether to follow symlinks when opening
+    pub fn open_subdir(&self, name: &OsStr, symlink_behavior: SymlinkBehavior) -> io::Result<Self> {
         let name_cstr =
             CString::new(name.as_bytes()).map_err(|_| SafeTraversalError::PathContainsNull)?;
-        let flags = OFlag::O_RDONLY | OFlag::O_DIRECTORY | OFlag::O_CLOEXEC;
+        let mut flags = OFlag::O_RDONLY | OFlag::O_DIRECTORY | OFlag::O_CLOEXEC;
+        if !symlink_behavior.should_follow() {
+            flags |= OFlag::O_NOFOLLOW;
+        }
         let fd = openat(&self.fd, name_cstr.as_c_str(), flags, Mode::empty()).map_err(|e| {
             SafeTraversalError::OpenFailed {
                 path: name.into(),
@@ -131,11 +177,11 @@
     }
 
     /// Get raw stat data for a file relative to this directory
-    pub fn stat_at(&self, name: &OsStr, follow_symlinks: bool) -> io::Result<FileStat> {
+    pub fn stat_at(&self, name: &OsStr, symlink_behavior: SymlinkBehavior) -> io::Result<FileStat> {
         let name_cstr =
             CString::new(name.as_bytes()).map_err(|_| SafeTraversalError::PathContainsNull)?;
 
-        let flags = if follow_symlinks {
+        let flags = if symlink_behavior.should_follow() {
             nix::fcntl::AtFlags::empty()
         } else {
             nix::fcntl::AtFlags::AT_SYMLINK_NOFOLLOW
@@ -152,8 +198,13 @@
     }
 
     /// Get metadata for a file relative to this directory
-    pub fn metadata_at(&self, name: &OsStr, follow_symlinks: bool) -> io::Result<Metadata> {
-        self.stat_at(name, follow_symlinks).map(Metadata::from_stat)
+    pub fn metadata_at(
+        &self,
+        name: &OsStr,
+        symlink_behavior: SymlinkBehavior,
+    ) -> io::Result<Metadata> {
+        self.stat_at(name, symlink_behavior)
+            .map(Metadata::from_stat)
     }
 
     /// Get metadata for this directory
@@ -208,12 +259,12 @@
         name: &OsStr,
         uid: Option<u32>,
         gid: Option<u32>,
-        follow_symlinks: bool,
+        symlink_behavior: SymlinkBehavior,
     ) -> io::Result<()> {
         let name_cstr =
             CString::new(name.as_bytes()).map_err(|_| SafeTraversalError::PathContainsNull)?;
 
-        let flags = if follow_symlinks {
+        let flags = if symlink_behavior.should_follow() {
             nix::fcntl::AtFlags::empty()
         } else {
             nix::fcntl::AtFlags::AT_SYMLINK_NOFOLLOW
@@ -239,8 +290,13 @@
     }
 
     /// Change mode of a file relative to this directory
-    pub fn chmod_at(&self, name: &OsStr, mode: u32, follow_symlinks: bool) -> io::Result<()> {
-        let flags = if follow_symlinks {
+    pub fn chmod_at(
+        &self,
+        name: &OsStr,
+        mode: u32,
+        symlink_behavior: SymlinkBehavior,
+    ) -> io::Result<()> {
+        let flags = if symlink_behavior.should_follow() {
             FchmodatFlags::FollowSymlink
         } else {
             FchmodatFlags::NoFollowSymlink
@@ -267,6 +323,39 @@
         Ok(())
     }
 
+    /// Create a directory relative to this directory
+    pub fn mkdir_at(&self, name: &OsStr, mode: u32) -> io::Result<()> {
+        let name_cstr =
+            CString::new(name.as_bytes()).map_err(|_| SafeTraversalError::PathContainsNull)?;
+        let mode = Mode::from_bits_truncate(mode as libc::mode_t);
+
+        if let Err(e) = mkdirat(self.fd.as_fd(), name_cstr.as_c_str(), mode) {
+            let err = io::Error::from_raw_os_error(e as i32);
+            return Err(SafeTraversalError::OpenFailed {
+                path: name.into(),
+                source: err,
+            }
+            .into());
+        }
+        Ok(())
+    }
+
+    /// Open a file for writing relative to this directory
+    /// Creates the file if it doesn't exist, truncates if it does
+    pub fn open_file_at(&self, name: &OsStr) -> io::Result<fs::File> {
+        let name_cstr =
+            CString::new(name.as_bytes()).map_err(|_| SafeTraversalError::PathContainsNull)?;
+        let flags = OFlag::O_CREAT | OFlag::O_WRONLY | OFlag::O_TRUNC | OFlag::O_CLOEXEC;
+        let mode = Mode::from_bits_truncate(0o666); // Default file permissions
+
+        let fd: OwnedFd = openat(self.fd.as_fd(), name_cstr.as_c_str(), flags, mode)
+            .map_err(|e| io::Error::from_raw_os_error(e as i32))?;
+
+        // Convert OwnedFd to raw fd and create File
+        let raw_fd = fd.into_raw_fd();
+        Ok(unsafe { fs::File::from_raw_fd(raw_fd) })
+    }
+
     /// Create a DirFd from an existing file descriptor (takes ownership)
     pub fn from_raw_fd(fd: RawFd) -> io::Result<Self> {
         if fd < 0 {
@@ -281,6 +370,152 @@
     }
 }
 
+/// Find the deepest existing real directory ancestor for a path.
+///
+/// Returns the existing ancestor path and a list of components that need to be created.
+/// Uses `symlink_metadata` to detect symlinks - symlinks are NOT followed and are
+/// treated as components that need to be created/replaced.
+fn find_existing_ancestor(path: &Path) -> io::Result<(PathBuf, Vec<OsString>)> {
+    let mut current = path.to_path_buf();
+    let mut components: Vec<OsString> = Vec::new();
+
+    loop {
+        // Use symlink_metadata to NOT follow symlinks
+        match fs::symlink_metadata(&current) {
+            Ok(meta) => {
+                if meta.is_dir() && !meta.file_type().is_symlink() {
+                    // Found a real directory (not a symlink to a directory)
+                    components.reverse();
+                    return Ok((current, components));
+                }
+                // It's a symlink, file, or other non-directory - treat as needing creation
+                // This ensures symlinks get replaced by open_or_create_subdir
+                if let Some(file_name) = current.file_name() {
+                    components.push(file_name.to_os_string());
+                }
+                if let Some(parent) = current.parent() {
+                    if parent.as_os_str().is_empty() {
+                        // Reached empty parent (for relative paths), use "."
+                        components.reverse();
+                        return Ok((PathBuf::from("."), components));
+                    }
+                    current = parent.to_path_buf();
+                } else {
+                    // Reached filesystem root
+                    let root = if path.is_absolute() {
+                        PathBuf::from("/")
+                    } else {
+                        PathBuf::from(".")
+                    };
+                    components.reverse();
+                    return Ok((root, components));
+                }
+            }
+            Err(e) if e.kind() == io::ErrorKind::NotFound => {
+                // Doesn't exist, record component and move up to parent
+                if let Some(file_name) = current.file_name() {
+                    components.push(file_name.to_os_string());
+                }
+                if let Some(parent) = current.parent() {
+                    if parent.as_os_str().is_empty() {
+                        // Reached empty parent (for relative paths), use "."
+                        components.reverse();
+                        return Ok((PathBuf::from("."), components));
+                    }
+                    current = parent.to_path_buf();
+                } else {
+                    // Reached filesystem root
+                    let root = if path.is_absolute() {
+                        PathBuf::from("/")
+                    } else {
+                        PathBuf::from(".")
+                    };
+                    components.reverse();
+                    return Ok((root, components));
+                }
+            }
+            Err(e) => return Err(e),
+        }
+    }
+}
+
+/// Open or create a subdirectory using fd-based operations only.
+///
+/// This is a helper function for `create_dir_all_safe` that handles a single
+/// path component. If a symlink exists where a directory should be, it is
+/// removed and replaced with a real directory.
+///
+/// # Arguments
+/// * `parent_fd` - The parent directory file descriptor
+/// * `name` - The name of the subdirectory to open or create
+/// * `mode` - The mode to use when creating a new directory
+///
+/// # Returns
+/// A DirFd for the subdirectory
+fn open_or_create_subdir(parent_fd: &DirFd, name: &OsStr, mode: u32) -> io::Result<DirFd> {
+    match parent_fd.stat_at(name, SymlinkBehavior::NoFollow) {
+        Ok(stat) => {
+            let file_type = (stat.st_mode as libc::mode_t) & libc::S_IFMT;
+            match file_type {
+                libc::S_IFDIR => parent_fd.open_subdir(name, SymlinkBehavior::NoFollow),
+                libc::S_IFLNK => {
+                    parent_fd.unlink_at(name, false)?;
+                    parent_fd.mkdir_at(name, mode)?;
+                    parent_fd.open_subdir(name, SymlinkBehavior::NoFollow)
+                }
+                _ => Err(io::Error::new(
+                    io::ErrorKind::AlreadyExists,
+                    format!(
+                        "path component exists but is not a directory: {}",
+                        name.display()
+                    ),
+                )),
+            }
+        }
+        Err(e) if e.kind() == io::ErrorKind::NotFound => {
+            parent_fd.mkdir_at(name, mode)?;
+            parent_fd.open_subdir(name, SymlinkBehavior::NoFollow)
+        }
+        Err(e) => Err(e),
+    }
+}
+
+/// Safely create all parent directories for a path using directory file descriptors.
+/// This prevents symlink race conditions by anchoring all operations to directory fds.
+///
+/// # Security
+/// This function prevents TOCTOU race conditions by:
+/// 1. Finding the deepest existing ancestor directory (path-based, but safe since it exists)
+/// 2. Opening that ancestor with a file descriptor
+/// 3. Creating all new directories using fd-based operations (mkdirat, openat with O_NOFOLLOW)
+///
+/// Once we have a fd for an existing ancestor, all subsequent operations use that fd
+/// as the anchor. If an attacker replaces a newly-created directory with a symlink,
+/// our openat with O_NOFOLLOW will fail, preventing the attack.
+///
+/// Existing symlinks in the path (like /var -> /private/var on macOS) are followed
+/// when finding the ancestor, which is safe since they already exist.
+///
+/// # Arguments
+/// * `path` - The path to create directories for
+/// * `mode` - The mode to use when creating new directories (e.g., 0o755). The actual
+///   mode will be modified by the process umask.
+///
+/// # Returns
+/// A DirFd for the final created directory, or the first existing parent if
+/// all directories already exist.
+#[cfg(unix)]
+pub fn create_dir_all_safe(path: &Path, mode: u32) -> io::Result<DirFd> {
+    let (existing_ancestor, components_to_create) = find_existing_ancestor(path)?;
+    let mut dir_fd = DirFd::open(&existing_ancestor, SymlinkBehavior::Follow)?;
+
+    for component in &components_to_create {
+        dir_fd = open_or_create_subdir(&dir_fd, component.as_os_str(), mode)?;
+    }
+
+    Ok(dir_fd)
+}
+
 impl AsRawFd for DirFd {
     fn as_raw_fd(&self) -> RawFd {
         self.fd.as_raw_fd()
@@ -345,15 +580,15 @@
         }
     }
 
-    pub fn is_directory(&self) -> bool {
+    pub fn is_directory(self) -> bool {
         matches!(self, Self::Directory)
     }
 
-    pub fn is_regular_file(&self) -> bool {
+    pub fn is_regular_file(self) -> bool {
         matches!(self, Self::RegularFile)
     }
 
-    pub fn is_symlink(&self) -> bool {
+    pub fn is_symlink(self) -> bool {
         matches!(self, Self::Symlink)
     }
 }
@@ -473,13 +708,21 @@
     }
 
     fn atime_nsec(&self) -> i64 {
-        #[cfg(target_pointer_width = "32")]
+        #[cfg(target_os = "netbsd")]
         {
-            self.stat.st_atime_nsec.into()
+            self.stat.st_atimensec as i64
         }
-        #[cfg(not(target_pointer_width = "32"))]
+
+        #[cfg(not(target_os = "netbsd"))]
         {
-            self.stat.st_atime_nsec
+            #[cfg(target_pointer_width = "32")]
+            {
+                self.stat.st_atime_nsec.into()
+            }
+            #[cfg(not(target_pointer_width = "32"))]
+            {
+                self.stat.st_atime_nsec
+            }
         }
     }
 
@@ -495,13 +738,21 @@
     }
 
     fn mtime_nsec(&self) -> i64 {
-        #[cfg(target_pointer_width = "32")]
+        #[cfg(target_os = "netbsd")]
         {
-            self.stat.st_mtime_nsec.into()
+            self.stat.st_mtimensec as i64
         }
-        #[cfg(not(target_pointer_width = "32"))]
+
+        #[cfg(not(target_os = "netbsd"))]
         {
-            self.stat.st_mtime_nsec
+            #[cfg(target_pointer_width = "32")]
+            {
+                self.stat.st_mtime_nsec.into()
+            }
+            #[cfg(not(target_pointer_width = "32"))]
+            {
+                self.stat.st_mtime_nsec
+            }
         }
     }
 
@@ -517,13 +768,21 @@
     }
 
     fn ctime_nsec(&self) -> i64 {
-        #[cfg(target_pointer_width = "32")]
+        #[cfg(target_os = "netbsd")]
         {
-            self.stat.st_ctime_nsec.into()
+            self.stat.st_ctimensec as i64
         }
-        #[cfg(not(target_pointer_width = "32"))]
+
+        #[cfg(not(target_os = "netbsd"))]
         {
-            self.stat.st_ctime_nsec
+            #[cfg(target_pointer_width = "32")]
+            {
+                self.stat.st_ctime_nsec.into()
+            }
+            #[cfg(not(target_pointer_width = "32"))]
+            {
+                self.stat.st_ctime_nsec
+            }
         }
     }
 
@@ -551,13 +810,13 @@
     #[test]
     fn test_dirfd_open_valid_directory() {
         let temp_dir = TempDir::new().unwrap();
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
         assert!(dir_fd.as_raw_fd() >= 0);
     }
 
     #[test]
     fn test_dirfd_open_nonexistent_directory() {
-        let result = DirFd::open("/nonexistent/path".as_ref());
+        let result = DirFd::open("/nonexistent/path".as_ref(), SymlinkBehavior::Follow);
         assert!(result.is_err());
         if let Err(e) = result {
             // The error should be the underlying io::Error
@@ -573,7 +832,7 @@
         let file_path = temp_dir.path().join("test_file");
         fs::write(&file_path, "test content").unwrap();
 
-        let result = DirFd::open(&file_path);
+        let result = DirFd::open(&file_path, SymlinkBehavior::Follow);
         assert!(result.is_err());
     }
 
@@ -583,17 +842,19 @@
         let subdir = temp_dir.path().join("subdir");
         fs::create_dir(&subdir).unwrap();
 
-        let parent_fd = DirFd::open(temp_dir.path()).unwrap();
-        let subdir_fd = parent_fd.open_subdir(OsStr::new("subdir")).unwrap();
+        let parent_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
+        let subdir_fd = parent_fd
+            .open_subdir(OsStr::new("subdir"), SymlinkBehavior::Follow)
+            .unwrap();
         assert!(subdir_fd.as_raw_fd() >= 0);
     }
 
     #[test]
     fn test_dirfd_open_nonexistent_subdir() {
         let temp_dir = TempDir::new().unwrap();
-        let parent_fd = DirFd::open(temp_dir.path()).unwrap();
+        let parent_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
 
-        let result = parent_fd.open_subdir(OsStr::new("nonexistent"));
+        let result = parent_fd.open_subdir(OsStr::new("nonexistent"), SymlinkBehavior::Follow);
         assert!(result.is_err());
     }
 
@@ -603,8 +864,10 @@
         let file_path = temp_dir.path().join("test_file");
         fs::write(&file_path, "test content").unwrap();
 
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
-        let stat = dir_fd.stat_at(OsStr::new("test_file"), true).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
+        let stat = dir_fd
+            .stat_at(OsStr::new("test_file"), SymlinkBehavior::Follow)
+            .unwrap();
 
         assert!(stat.st_size > 0);
         assert_eq!(stat.st_mode & libc::S_IFMT, libc::S_IFREG);
@@ -619,21 +882,25 @@
         fs::write(&target_file, "target content").unwrap();
         symlink(&target_file, &symlink_file).unwrap();
 
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
 
         // Follow symlinks
-        let stat_follow = dir_fd.stat_at(OsStr::new("link"), true).unwrap();
+        let stat_follow = dir_fd
+            .stat_at(OsStr::new("link"), SymlinkBehavior::Follow)
+            .unwrap();
         assert_eq!(stat_follow.st_mode & libc::S_IFMT, libc::S_IFREG);
 
         // Don't follow symlinks
-        let stat_nofollow = dir_fd.stat_at(OsStr::new("link"), false).unwrap();
+        let stat_nofollow = dir_fd
+            .stat_at(OsStr::new("link"), SymlinkBehavior::NoFollow)
+            .unwrap();
         assert_eq!(stat_nofollow.st_mode & libc::S_IFMT, libc::S_IFLNK);
     }
 
     #[test]
     fn test_dirfd_fstat() {
         let temp_dir = TempDir::new().unwrap();
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
         let stat = dir_fd.fstat().unwrap();
 
         assert_eq!(stat.st_mode & libc::S_IFMT, libc::S_IFDIR);
@@ -648,7 +915,7 @@
         fs::write(&file1, "content1").unwrap();
         fs::write(&file2, "content2").unwrap();
 
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
         let entries = dir_fd.read_dir().unwrap();
 
         assert_eq!(entries.len(), 2);
@@ -662,7 +929,7 @@
         let file_path = temp_dir.path().join("test_file");
         fs::write(&file_path, "test content").unwrap();
 
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
         dir_fd.unlink_at(OsStr::new("test_file"), false).unwrap();
 
         assert!(!file_path.exists());
@@ -674,7 +941,7 @@
         let subdir = temp_dir.path().join("empty_dir");
         fs::create_dir(&subdir).unwrap();
 
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
         dir_fd.unlink_at(OsStr::new("empty_dir"), true).unwrap();
 
         assert!(!subdir.exists());
@@ -683,7 +950,7 @@
     #[test]
     fn test_from_raw_fd() {
         let temp_dir = TempDir::new().unwrap();
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
 
         // Duplicate the fd first so we don't have ownership conflicts
         let dup_fd = nix::unistd::dup(&dir_fd).unwrap();
@@ -709,8 +976,10 @@
         let file_path = temp_dir.path().join("test_file");
         fs::write(&file_path, "test content").unwrap();
 
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
-        let stat = dir_fd.stat_at(OsStr::new("test_file"), true).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
+        let stat = dir_fd
+            .stat_at(OsStr::new("test_file"), SymlinkBehavior::Follow)
+            .unwrap();
         let file_info = FileInfo::from_stat(&stat);
         assert_eq!(file_info.device(), stat.st_dev as u64);
         assert_eq!(file_info.inode(), stat.st_ino as u64);
@@ -757,8 +1026,10 @@
         let file_path = temp_dir.path().join("test_file");
         fs::write(&file_path, "test content with some length").unwrap();
 
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
-        let metadata = dir_fd.metadata_at(OsStr::new("test_file"), true).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
+        let metadata = dir_fd
+            .metadata_at(OsStr::new("test_file"), SymlinkBehavior::Follow)
+            .unwrap();
 
         assert_eq!(metadata.file_type(), FileType::RegularFile);
         assert!(metadata.size() > 0);
@@ -771,7 +1042,7 @@
     #[test]
     fn test_metadata_directory() {
         let temp_dir = TempDir::new().unwrap();
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
         let metadata = dir_fd.metadata().unwrap();
 
         assert_eq!(metadata.file_type(), FileType::Directory);
@@ -780,11 +1051,11 @@
 
     #[test]
     fn test_path_with_null_byte() {
-        let path_with_null = std::ffi::OsString::from_vec(b"test\0file".to_vec());
+        let path_with_null = OsString::from_vec(b"test\0file".to_vec());
         let temp_dir = TempDir::new().unwrap();
-        let dir_fd = DirFd::open(temp_dir.path()).unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
 
-        let result = dir_fd.open_subdir(&path_with_null);
+        let result = dir_fd.open_subdir(&path_with_null, SymlinkBehavior::Follow);
         assert!(result.is_err());
         if let Err(e) = result {
             // Should be InvalidInput for null byte error
@@ -794,7 +1065,10 @@
 
     #[test]
     fn test_error_chain() {
-        let result = DirFd::open("/nonexistent/deeply/nested/path".as_ref());
+        let result = DirFd::open(
+            "/nonexistent/deeply/nested/path".as_ref(),
+            SymlinkBehavior::Follow,
+        );
         assert!(result.is_err());
 
         if let Err(e) = result {
@@ -805,5 +1079,172 @@
                     || io_err.kind() == io::ErrorKind::PermissionDenied
             );
         }
+    }
+
+    #[test]
+    fn test_mkdir_at_creates_directory() {
+        let temp_dir = TempDir::new().unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
+
+        dir_fd.mkdir_at(OsStr::new("new_subdir"), 0o755).unwrap();
+
+        assert!(temp_dir.path().join("new_subdir").is_dir());
+    }
+
+    #[test]
+    fn test_mkdir_at_fails_if_exists() {
+        let temp_dir = TempDir::new().unwrap();
+        let subdir = temp_dir.path().join("existing");
+        fs::create_dir(&subdir).unwrap();
+
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
+        let result = dir_fd.mkdir_at(OsStr::new("existing"), 0o755);
+
+        assert!(result.is_err());
+    }
+
+    #[test]
+    fn test_open_file_at_creates_file() {
+        let temp_dir = TempDir::new().unwrap();
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
+
+        let mut file = dir_fd.open_file_at(OsStr::new("new_file.txt")).unwrap();
+        use std::io::Write;
+        file.write_all(b"test content").unwrap();
+
+        let content = fs::read_to_string(temp_dir.path().join("new_file.txt")).unwrap();
+        assert_eq!(content, "test content");
+    }
+
+    #[test]
+    fn test_open_file_at_truncates_existing() {
+        let temp_dir = TempDir::new().unwrap();
+        let file_path = temp_dir.path().join("existing.txt");
+        fs::write(&file_path, "old content that is longer").unwrap();
+
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
+        let mut file = dir_fd.open_file_at(OsStr::new("existing.txt")).unwrap();
+        use std::io::Write;
+        file.write_all(b"new").unwrap();
+        drop(file);
+
+        let content = fs::read_to_string(&file_path).unwrap();
+        assert_eq!(content, "new");
+    }
+
+    #[test]
+    fn test_create_dir_all_safe_creates_nested_dirs() {
+        let temp_dir = TempDir::new().unwrap();
+        let nested_path = temp_dir.path().join("a/b/c");
+
+        let dir_fd = create_dir_all_safe(&nested_path, 0o755).unwrap();
+        assert!(dir_fd.as_raw_fd() >= 0);
+        assert!(nested_path.is_dir());
+    }
+
+    #[test]
+    fn test_create_dir_all_safe_existing_path() {
+        let temp_dir = TempDir::new().unwrap();
+        let existing_path = temp_dir.path().join("existing");
+        fs::create_dir(&existing_path).unwrap();
+
+        let dir_fd = create_dir_all_safe(&existing_path, 0o755).unwrap();
+        assert!(dir_fd.as_raw_fd() >= 0);
+    }
+
+    #[test]
+    fn test_create_dir_all_safe_replaces_symlink() {
+        let temp_dir = TempDir::new().unwrap();
+        let target_dir = temp_dir.path().join("target");
+        fs::create_dir(&target_dir).unwrap();
+
+        // Create a symlink where we want to create a directory
+        let symlink_path = temp_dir.path().join("link_to_replace");
+        symlink(&target_dir, &symlink_path).unwrap();
+        assert!(symlink_path.is_symlink());
+
+        // create_dir_all_safe should replace the symlink with a real directory
+        let dir_fd = create_dir_all_safe(&symlink_path, 0o755).unwrap();
+        assert!(dir_fd.as_raw_fd() >= 0);
+
+        // Verify the symlink was replaced with a real directory
+        assert!(symlink_path.is_dir());
+        assert!(!symlink_path.is_symlink());
+    }
+
+    #[test]
+    fn test_create_dir_all_safe_fails_on_file() {
+        let temp_dir = TempDir::new().unwrap();
+        let file_path = temp_dir.path().join("file");
+        fs::write(&file_path, "content").unwrap();
+
+        let result = create_dir_all_safe(&file_path, 0o755);
+        assert!(result.is_err());
+    }
+
+    #[test]
+    fn test_create_dir_all_safe_nested_symlink_in_path() {
+        let temp_dir = TempDir::new().unwrap();
+
+        // Create: parent/symlink -> target
+        // Then try to create: parent/symlink/subdir
+        let parent = temp_dir.path().join("parent");
+        let target = temp_dir.path().join("target");
+        fs::create_dir(&parent).unwrap();
+        fs::create_dir(&target).unwrap();
+
+        let symlink_in_path = parent.join("link");
+        symlink(&target, &symlink_in_path).unwrap();
+
+        // Try to create parent/link/subdir - the symlink should be replaced
+        let nested_path = symlink_in_path.join("subdir");
+        let dir_fd = create_dir_all_safe(&nested_path, 0o755).unwrap();
+        assert!(dir_fd.as_raw_fd() >= 0);
+
+        // The symlink should have been replaced with a real directory
+        assert!(!symlink_in_path.is_symlink());
+        assert!(symlink_in_path.is_dir());
+        assert!(nested_path.is_dir());
+
+        // Target directory should not contain subdir (race attack prevented)
+        assert!(!target.join("subdir").exists());
+    }
+
+    #[test]
+    fn test_open_subdir_nofollow_fails_on_symlink() {
+        let temp_dir = TempDir::new().unwrap();
+        let target = temp_dir.path().join("target");
+        fs::create_dir(&target).unwrap();
+
+        let link = temp_dir.path().join("link");
+        symlink(&target, &link).unwrap();
+
+        let dir_fd = DirFd::open(temp_dir.path(), SymlinkBehavior::Follow).unwrap();
+
+        // With follow_symlinks=true, should succeed
+        let result_follow = dir_fd.open_subdir(OsStr::new("link"), SymlinkBehavior::Follow);
+        assert!(result_follow.is_ok());
+
+        // With follow_symlinks=false, should fail (ELOOP or ENOTDIR)
+        let result_nofollow = dir_fd.open_subdir(OsStr::new("link"), SymlinkBehavior::NoFollow);
+        assert!(result_nofollow.is_err());
+    }
+
+    #[test]
+    fn test_open_nofollow_fails_on_symlink() {
+        let temp_dir = TempDir::new().unwrap();
+        let target = temp_dir.path().join("target");
+        fs::create_dir(&target).unwrap();
+
+        let link = temp_dir.path().join("link");
+        symlink(&target, &link).unwrap();
+
+        // With follow_symlinks=true, should succeed
+        let result_follow = DirFd::open(&link, SymlinkBehavior::Follow);
+        assert!(result_follow.is_ok());
+
+        // With follow_symlinks=false, should fail
+        let result_nofollow = DirFd::open(&link, SymlinkBehavior::NoFollow);
+        assert!(result_nofollow.is_err());
     }
 }
