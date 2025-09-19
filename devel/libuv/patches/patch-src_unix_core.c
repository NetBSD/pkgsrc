$NetBSD: patch-src_unix_core.c,v 1.4 2025/09/19 07:06:49 mrg Exp $

Apply MacPorts patch-libuv-unix-core-close-nocancel.diff for
- older gcc versions to not error on pragmas
- 32bit code to link correctly
- Tiger to work around not having a non-cancellable close function

Also fix NetBSD cpuset handling.

--- src/unix/core.c.orig	2025-04-25 02:50:27.000000000 -0700
+++ src/unix/core.c	2025-09-19 00:00:12.596197154 -0700
@@ -597,18 +597,31 @@
  * will unwind the thread when it's in the cancel state. Work around that
  * by making the system call directly. Musl libc is unaffected.
  */
+
+#if defined(__GNUC__)
+# define GCC_VERSION \
+	(__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
+#endif
+#if defined(__clang__) || (defined(GCC_VERSION) && (GCC_VERSION >= 40500))
+/* gcc diagnostic pragmas available */
+# define GCC_DIAGNOSTIC_AVAILABLE
+#endif
 int uv__close_nocancel(int fd) {
-#if defined(__APPLE__)
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdollar-in-identifier-extension"
-#if defined(__LP64__) || TARGET_OS_IPHONE
+#if defined(__APPLE__) && (MAC_OS_X_VERSION_MAX_ALLOWED >= 1050)
+# if defined(GCC_DIAGNOSTIC_AVAILABLE)
+#  pragma GCC diagnostic push
+#  pragma GCC diagnostic ignored "-Wdollar-in-identifier-extension"
+# endif
+# if defined(__LP64__) || __LP64__ || (defined(TARGET_OS_IPHONE) && (TARGET_OS_IPHONE > 0))
   extern int close$NOCANCEL(int);
   return close$NOCANCEL(fd);
-#else
+# else
   extern int close$NOCANCEL$UNIX2003(int);
   return close$NOCANCEL$UNIX2003(fd);
-#endif
-#pragma GCC diagnostic pop
+# endif
+# if defined(GCC_DIAGNOSTIC_AVAILABLE)
+#  pragma GCC diagnostic pop
+# endif
 #elif defined(__linux__) && defined(__SANITIZE_THREAD__) && defined(__clang__)
   long rc;
   __sanitizer_syscall_pre_close(fd);
@@ -1998,8 +2011,8 @@
 #elif defined(__NetBSD__)
   cpuset_t* set = cpuset_create();
   if (set != NULL) {
-    if (0 == sched_getaffinity_np(getpid(), sizeof(set), &set))
-      rc = uv__cpu_count(&set);
+    if (0 == sched_getaffinity_np(getpid(), cpuset_size(set), set))
+      rc = uv__cpu_count(set);
     cpuset_destroy(set);
   }
 #elif defined(__APPLE__)
