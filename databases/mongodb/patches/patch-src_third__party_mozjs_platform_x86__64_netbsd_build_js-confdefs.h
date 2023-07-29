$NetBSD: patch-src_third__party_mozjs_platform_x86__64_netbsd_build_js-confdefs.h,v 1.1 2023/07/29 11:45:43 adam Exp $

On NetBSD, malloc() is defined in stdlib.h.

--- src/third_party/mozjs/platform/x86_64/netbsd/build/js-confdefs.h.orig	2023-07-28 17:26:23.000000000 +0000
+++ src/third_party/mozjs/platform/x86_64/netbsd/build/js-confdefs.h
@@ -60,7 +60,7 @@
 #define JS_PUNBOX64 1
 #define JS_STANDALONE 1
 #define JS_WITHOUT_NSPR 1
-#define MALLOC_H <malloc.h>
+#define MALLOC_H <stdlib.h>
 #define MALLOC_USABLE_SIZE_CONST_PTR const
 #define MOZILLA_UAVERSION "91.0"
 #define MOZILLA_VERSION "91.3.0"
