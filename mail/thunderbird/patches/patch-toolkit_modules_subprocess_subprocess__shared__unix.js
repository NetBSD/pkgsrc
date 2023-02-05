$NetBSD: patch-toolkit_modules_subprocess_subprocess__shared__unix.js,v 1.3 2023/02/05 09:05:29 he Exp $

--- toolkit/modules/subprocess/subprocess_shared_unix.js.orig	2020-08-28 21:34:00.000000000 +0000
+++ toolkit/modules/subprocess/subprocess_shared_unix.js
@@ -13,7 +13,16 @@
 
 var LIBC = OS.Constants.libc;
 
-const LIBC_CHOICES = ["libc.so", "libSystem.B.dylib", "a.out"];
+// const LIBC_CHOICES = ["libc.so", "libSystem.B.dylib", "a.out"];
+/* libc.so isn't meant to be dlopen'ed. On Linux it's usually an ld
+ * script so one cannot dlopen it. On NetBSD (and possibly other
+ * BSDs too) dlopen'ing libc.so will succeed, but some global symbols,
+ * especially environ(7), are pointing to unused memory regions
+ * because they are meant to be overridden by the main executable.
+ * So the most portable way to access libc symbols is to do it through
+ * the NULL handle, i.e. the one which NSPR calls "a.out".
+ */
+const LIBC_CHOICES = ["a.out"];
 
 const unix = {
   pid_t: ctypes.int32_t,
