$NetBSD: patch-libheif_error.cc,v 1.1 2025/07/06 09:29:13 wiz Exp $

C++17 compat
https://github.com/strukturag/libheif/commit/b610000ebc488d40a1ea8cc9ea89b25aef736004

--- libheif/error.cc.orig	2025-07-02 13:05:31.000000000 +0000
+++ libheif/error.cc
@@ -48,6 +48,15 @@ Error::Error(heif_error_code c,
 }
 
 
+// Replacement for C++20 std::string::starts_with()
+static bool starts_with(const std::string& str, const std::string& prefix) {
+    if (str.length() < prefix.length()) {
+        return false;
+    }
+    return str.rfind(prefix, 0) == 0;
+}
+
+
 Error Error::from_heif_error(const heif_error& c_error)
 {
   // unpack the concatenated error message and extract the last part only
@@ -56,17 +65,17 @@ Error Error::from_heif_error(const heif_
   const char* sub_err_string = get_error_string(c_error.subcode);
 
   std::string msg = c_error.message;
-  if (msg.starts_with(err_string)) {
+  if (starts_with(msg, err_string)) {
     msg = msg.substr(strlen(err_string));
 
-    if (msg.starts_with(": ")) {
+    if (starts_with(msg, ": ")) {
       msg = msg.substr(2);
     }
 
-    if (msg.starts_with(sub_err_string)) {
+    if (starts_with(msg, sub_err_string)) {
       msg = msg.substr(strlen(sub_err_string));
 
-      if (msg.starts_with(": ")) {
+      if (starts_with(msg, ": ")) {
         msg = msg.substr(2);
       }
     }
