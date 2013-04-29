$NetBSD: patch-base_thread.h,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- base/thread.h.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/thread.h
@@ -55,7 +55,8 @@
 
 // Andorid NDK and NaCl don't support TLS.
 #if defined(OS_LINUX) && !defined(OS_ANDROID) && \
-    !defined(__native_client__) && (defined(__GNUC__) || defined(__clang__))
+    !defined(__native_client__) && (defined(__GNUC__) || defined(__clang__)) \
+    || defined(OS_NETBSD)
 // GCC and Clang support TLS.
 #define TLS_KEYWORD __thread
 #define HAVE_TLS 1
