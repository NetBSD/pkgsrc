$NetBSD: patch-src_unix_core.c,v 1.2 2024/09/30 17:05:46 adam Exp $

Apply MacPorts patch-libuv-unix-core-close-nocancel.diff for
- older gcc versions to not error on pragmas
- 32bit code to link correctly
- Tiger to work around not having a non-cancellable close function

Fix build on NetBSD: https://github.com/libuv/libuv/issues/4552

--- src/unix/core.c.orig	2024-09-25 08:17:20.000000000 +0000
+++ src/unix/core.c
@@ -595,18 +595,31 @@ int uv__accept(int sockfd) {
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
@@ -1882,13 +1895,13 @@ int uv__search_path(const char* prog, ch
 #if defined(__linux__) || defined (__FreeBSD__)
 # define uv__cpu_count(cpuset) CPU_COUNT(cpuset)
 #elif defined(__NetBSD__)
-static int uv__cpu_count(cpuset_t *cpuset) {
+static int uv__cpu_count(cpuset_t *set) {
   int rc;
   cpuid_t i;
 
   rc = 0;
   for (i = 0;; i++) {
-    int r = cpuset_isset(cpu, set);
+    int r = cpuset_isset(i, set);
     if (r < 0)
       break;
     if (r)
