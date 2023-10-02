$NetBSD: patch-utils_pxattr.cpp,v 1.1 2023/10/02 06:05:12 wiz Exp $

Fix build on NetBSD, from upstream.

--- utils/pxattr.cpp.orig	2023-05-12 08:19:26.000000000 +0000
+++ utils/pxattr.cpp
@@ -27,14 +27,6 @@
     \brief Portable External Attributes API
 */
 
-// PXALINUX: platforms like kfreebsd which aren't linux but use the
-// same xattr interface
-#if defined(__linux__) ||                                               \
-    (defined(__FreeBSD_kernel__)&&defined(__GLIBC__)&&!defined(__FreeBSD__)) || \
-    defined(__CYGWIN__)
-#define PXALINUX
-#endif
-
 // If the platform is not known yet, let this file be empty instead of
 // breaking the compile, this will let the build work if the rest of
 // the software is not actually calling us. If it does call us, this
@@ -44,6 +36,20 @@
 // just let the methods return errors (like they would on a non-xattr
 // fs on e.g. linux)
 
+
+// PXALINUX: platforms like kfreebsd which aren't linux but use the
+// same xattr interface
+#if defined(__linux__) ||                                               \
+    (defined(__FreeBSD_kernel__)&&defined(__GLIBC__)&&!defined(__FreeBSD__)) || \
+    defined(__CYGWIN__)
+#define PXALINUX
+#endif
+
+// FreeBSD and NetBSD use the same interface. Let's call this PXAFREEBSD
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#define PXAFREEBSD
+#endif // __FreeBSD__ or __NetBSD__
+
 // Not exactly true for win32, but makes my life easier by avoiding ifdefs in recoll (the calls just
 // fail, which is expected)
 #if defined(__DragonFly__) || defined(__OpenBSD__) || defined(_WIN32)
@@ -55,7 +61,7 @@
 #endif
 
 
-#if defined(__FreeBSD__) || defined(PXALINUX) || defined(__APPLE__) || defined(HAS_NO_XATTR)
+#if defined(PXAFREEBSD) || defined(PXALINUX) || defined(__APPLE__) || defined(HAS_NO_XATTR)
 
 
 #ifndef TEST_PXATTR
@@ -64,7 +70,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 
-#if defined(__FreeBSD__)
+#if defined(PXAFREEBSD)
 #include <sys/extattr.h>
 #include <sys/uio.h>
 #elif defined(PXALINUX)
@@ -112,7 +118,7 @@ get(int fd, const string& path, const st
 
     ssize_t ret = -1;
     AutoBuf buf;
-#if defined(__FreeBSD__)
+#if defined(PXAFREEBSD)
     if (fd < 0) {
         if (flags & PXATTR_NOFOLLOW) {
             ret = extattr_get_link(path.c_str(), EXTATTR_NAMESPACE_USER, 
@@ -209,7 +215,7 @@ set(int fd, const string& path, const st
 
     ssize_t ret = -1;
 
-#if defined(__FreeBSD__)
+#if defined(PXAFREEBSD)
     
     if (flags & (PXATTR_CREATE|PXATTR_REPLACE)) {
         // Need to test existence
@@ -306,7 +312,7 @@ del(int fd, const string& path, const st
 
     int ret = -1;
 
-#if defined(__FreeBSD__)
+#if defined(PXAFREEBSD)
     if (fd < 0) {
         if (flags & PXATTR_NOFOLLOW) {
             ret = extattr_delete_link(path.c_str(), EXTATTR_NAMESPACE_USER,
@@ -353,7 +359,7 @@ list(int fd, const string& path, vector<
     ssize_t ret = -1;
     AutoBuf buf;
 
-#if defined(__FreeBSD__)
+#if defined(PXAFREEBSD)
     if (fd < 0) {
         if (flags & PXATTR_NOFOLLOW) {
             ret = extattr_list_link(path.c_str(), EXTATTR_NAMESPACE_USER, 0, 0);
@@ -438,9 +444,9 @@ list(int fd, const string& path, vector<
 
     char *bufstart = buf.buf;
 
-    // All systems return a 0-separated string list except FreeBSD
+    // All systems return a 0-separated string list except FreeBSD/NetBSD
     // which has length, value pairs, length is a byte. 
-#if defined(__FreeBSD__)
+#if defined(PXAFREEBSD)
     char *cp = buf.buf;
     unsigned int len;
     while (cp < buf.buf + ret + 1) {
