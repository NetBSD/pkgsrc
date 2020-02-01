$NetBSD: patch-src_third__party_mozjs-60_platform_x86__64_netbsd_build_js-confdefs.h,v 1.1 2020/02/01 20:00:08 adam Exp $

--- src/third_party/mozjs-60/platform/x86_64/netbsd/build/js-confdefs.h.orig	2020-01-29 20:09:04.581823530 +0000
+++ src/third_party/mozjs-60/platform/x86_64/netbsd/build/js-confdefs.h
@@ -31,7 +31,6 @@
 #define HAVE_POSIX_FALLOCATE 1
 #define HAVE_POSIX_MEMALIGN 1
 #define HAVE_RES_NINIT 1
-#define HAVE_SINCOS 1
 #define HAVE_SSIZE_T 1
 #define HAVE_STDINT_H 1
 #define HAVE_STRNDUP 1
@@ -54,7 +53,7 @@
 #define JS_POSIX_NSPR 1
 #define JS_PUNBOX64 1
 #define JS_STANDALONE 1
-#define MALLOC_H <malloc_np.h>
+#define MALLOC_H <stdlib.h>
 #define MALLOC_USABLE_SIZE_CONST_PTR const
 #define MOZILLA_UAVERSION "60.0"
 #define MOZILLA_VERSION "60.3.0"
