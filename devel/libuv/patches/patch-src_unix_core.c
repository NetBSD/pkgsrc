$NetBSD: patch-src_unix_core.c,v 1.1 2022/01/28 21:13:10 schmonz Exp $

Apply MacPorts patch-libuv-unix-core-close-nocancel.diff for
- older gcc versions to not error on pragmas
- 32bit code to link correctly
- Tiger to work around not having a non-cancellable close function

--- src/unix/core.c.orig	2022-01-04 14:18:00.000000000 +0000
+++ src/unix/core.c
@@ -531,18 +531,31 @@ int uv__accept(int sockfd) {
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
