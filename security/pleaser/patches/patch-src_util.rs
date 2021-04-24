$NetBSD: patch-src_util.rs,v 1.1 2021/04/24 18:52:59 pin Exp $

NetBSD fixes by Ed Neville

--- src/util.rs.orig	2021-04-24 10:42:56.777765681 +0000
+++ src/util.rs
@@ -839,6 +839,31 @@ pub fn get_editor() -> String {
     editor.to_string()
 }
 
+/// handler.authenticate without the root privs part for linux
+#[cfg(target_os = "linux")]
+pub fn handler_shim<T: pam::Converse>(
+    _ro: &RunOptions,
+    handler: &mut Authenticator<T>,
+) -> Result<(), pam::PamError> {
+    handler.authenticate()
+}
+
+/// handler.authenticate needs esc_privs on netbsd
+#[cfg(not(target_os = "linux"))]
+pub fn handler_shim<T: pam::Converse>(
+    ro: &RunOptions,
+    handler: &mut Authenticator<T>,
+) -> Result<(), pam::PamError> {
+    if !esc_privs() {
+        std::process::exit(1);
+    }
+    let auth = handler.authenticate();
+    if !drop_privs(&ro) {
+        std::process::exit(1);
+    }
+    auth
+}
+
 /// read password of user via rpassword
 /// should pam require a password, and it is successful, then we set a token
 pub fn challenge_password(ro: &RunOptions, entry: EnvOptions, service: &str) -> bool {
@@ -876,7 +901,7 @@ pub fn challenge_password(ro: &RunOption
         let mut handler = Authenticator::with_handler(service, convo).expect("Cannot init PAM");
 
         loop {
-            let auth = handler.authenticate();
+            let auth = handler_shim(&ro, &mut handler);
 
             if auth.is_ok() {
                 if handler.get_handler().passwd.is_some() {
@@ -1231,6 +1256,7 @@ pub fn create_token_dir() -> bool {
     true
 }
 
+#[cfg(target_os = "linux")]
 pub fn boot_secs() -> libc::timespec {
     let mut tp = libc::timespec {
         tv_sec: 0 as i64,
@@ -1240,6 +1266,16 @@ pub fn boot_secs() -> libc::timespec {
     tp
 }
 
+#[cfg(not(target_os = "linux"))]
+pub fn boot_secs() -> libc::timespec {
+    let mut tp = libc::timespec {
+        tv_sec: 0 as i64,
+        tv_nsec: 0,
+    };
+    unsafe { libc::clock_gettime(libc::CLOCK_MONOTONIC, &mut tp) };
+    tp
+}
+
 /// does the user have a valid token
 /// return false if time stamp is in the future
 /// return true if token was set within 600 seconds of wall and boot time
