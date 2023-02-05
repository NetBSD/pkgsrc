$NetBSD: patch-third__party_rust_authenticator_src_netbsd_fd.rs,v 1.1 2023/02/05 08:32:24 he Exp $

--- third_party/rust/authenticator/src/netbsd/fd.rs.orig	2020-09-02 20:55:30.875594185 +0000
+++ third_party/rust/authenticator/src/netbsd/fd.rs
@@ -0,0 +1,47 @@
+/* This Source Code Form is subject to the terms of the Mozilla Public
+ * License, v. 2.0. If a copy of the MPL was not distributed with this
+ * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
+
+extern crate libc;
+
+use std::ffi::CString;
+use std::io;
+use std::mem;
+use std::os::raw::c_int;
+use std::os::unix::io::RawFd;
+
+#[derive(Debug)]
+pub struct Fd {
+    pub fileno: RawFd,
+}
+
+impl Fd {
+    pub fn open(path: &str, flags: c_int) -> io::Result<Fd> {
+        let cpath = CString::new(path.as_bytes())?;
+        let rv = unsafe { libc::open(cpath.as_ptr(), flags) };
+        if rv == -1 {
+            return Err(io::Error::last_os_error());
+        }
+        Ok(Fd { fileno: rv })
+    }
+}
+
+impl Drop for Fd {
+    fn drop(&mut self) {
+        unsafe { libc::close(self.fileno) };
+    }
+}
+
+impl PartialEq for Fd {
+    fn eq(&self, other: &Fd) -> bool {
+        let mut st: libc::stat = unsafe { mem::zeroed() };
+        let mut sto: libc::stat = unsafe { mem::zeroed() };
+        if unsafe { libc::fstat(self.fileno, &mut st) } == -1 {
+            return false;
+        }
+        if unsafe { libc::fstat(other.fileno, &mut sto) } == -1 {
+            return false;
+        }
+        (st.st_dev == sto.st_dev) & (st.st_ino == sto.st_ino)
+    }
+}
