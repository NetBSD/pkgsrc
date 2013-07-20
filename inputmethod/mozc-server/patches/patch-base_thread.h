$NetBSD: patch-base_thread.h,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- base/thread.h.orig	2013-07-17 02:38:04.000000000 +0000
+++ base/thread.h
@@ -55,11 +55,11 @@
 
 // Andorid NDK and NaCl don't support TLS.
 #if defined(OS_LINUX) && !defined(OS_ANDROID) && \
-    !defined(__native_client__) && (defined(__GNUC__) || defined(__clang__))
+    !defined(__native_client__) && (defined(__GNUC__) || defined(__clang__)) || defined(OS_NETBSD)
 // GCC and Clang support TLS.
 #define TLS_KEYWORD __thread
 #define HAVE_TLS 1
-#endif  // OS_LINUX && !OS_ANDROID && (__GNUC__ || __clang__)
+#endif  // OS_LINUX && !OS_ANDROID && (__GNUC__ || __clang__) || OS_NETBSD
 
 
 #if defined(OS_MACOSX) && MOZC_GCC_VERSION_GE(4, 5)
