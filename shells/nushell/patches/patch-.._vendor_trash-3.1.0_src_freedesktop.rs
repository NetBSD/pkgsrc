$NetBSD: patch-.._vendor_trash-3.1.0_src_freedesktop.rs,v 1.1 2023/10/18 07:22:43 pin Exp $

Fix build on Free/OpenBSD,
https://github.com/Byron/trash-rs/pull/87

--- ../vendor/trash-3.1.0/src/freedesktop.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/trash-3.1.0/src/freedesktop.rs
@@ -678,7 +678,7 @@ fn get_mount_points() -> Result<Vec<Moun
     Ok(result)
 }
 
-#[cfg(any(target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"))]
+#[cfg(any(target_os = "freebsd", target_os = "openbsd"))]
 fn get_mount_points() -> Result<Vec<MountPoint>, Error> {
     use once_cell::sync::Lazy;
     use std::sync::Mutex;
@@ -702,6 +702,61 @@ fn get_mount_points() -> Result<Vec<Moun
             std::str::from_utf8(buf).ok()
         }
     }
+    let mut fs_infos: *mut libc::statfs = std::ptr::null_mut();
+    let count = unsafe { libc::getmntinfo(&mut fs_infos, libc::MNT_WAIT) };
+    if count < 1 {
+        return Ok(Vec::new());
+    }
+    let fs_infos: &[libc::statfs] = unsafe { std::slice::from_raw_parts(fs_infos as _, count as _) };
+
+    let mut result = Vec::new();
+    for fs_info in fs_infos {
+        if fs_info.f_mntfromname[0] == 0 || fs_info.f_mntonname[0] == 0 {
+            // If we have missing information, no need to look any further...
+            continue;
+        }
+        let fs_type = c_buf_to_str(&fs_info.f_fstypename).unwrap_or_default();
+        let mount_to = match c_buf_to_str(&fs_info.f_mntonname) {
+            Some(m) => m,
+            None => {
+                debug!("Cannot get disk mount point, ignoring it.");
+                continue;
+            }
+        };
+        let mount_from = c_buf_to_str(&fs_info.f_mntfromname).unwrap_or_default();
+
+        let mount_point =
+            MountPoint { mnt_dir: mount_to.into(), _mnt_fsname: mount_from.into(), _mnt_type: fs_type.into() };
+        result.push(mount_point);
+    }
+    Ok(result)
+}
+
+#[cfg(target_os = "netbsd")]
+fn get_mount_points() -> Result<Vec<MountPoint>, Error> {
+    use once_cell::sync::Lazy;
+    use std::sync::Mutex;
+
+    // The getmntinfo() function writes the array of structures to an internal
+    // static object and returns a pointer to that object.  Subsequent calls to
+    // getmntinfo() will modify the same object. This means that the function is
+    // not threadsafe. To help prevent multiple threads using it concurrently
+    // via get_mount_points a Mutex is used.
+    // We understand that threads can still call `libc::getmntinfo(…)` directly
+    // to bypass the lock and trigger UB.
+    // NetBSD does not support statfs since 2005, so we need to use statvfs instead.
+    static LOCK: Lazy<Mutex<()>> = Lazy::new(|| Mutex::new(()));
+    let _lock = LOCK.lock().unwrap();
+
+    fn c_buf_to_str(buf: &[libc::c_char]) -> Option<&str> {
+        let buf: &[u8] = unsafe { std::slice::from_raw_parts(buf.as_ptr() as _, buf.len()) };
+        if let Some(pos) = buf.iter().position(|x| *x == 0) {
+            // Shrink buffer to omit the null bytes
+            std::str::from_utf8(&buf[..pos]).ok()
+        } else {
+            std::str::from_utf8(buf).ok()
+        }
+    }
     let mut fs_infos: *mut libc::statvfs = std::ptr::null_mut();
     let count = unsafe { libc::getmntinfo(&mut fs_infos, libc::MNT_WAIT) };
     if count < 1 {
@@ -1040,3 +1095,4 @@ mod tests {
 fn fsys_err_to_unknown<P: AsRef<Path>>(path: P, orig: std::io::Error) -> Error {
     Error::FileSystem { path: path.as_ref().to_owned(), kind: orig.kind() }
 }
+
