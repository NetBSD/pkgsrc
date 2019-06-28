$NetBSD: patch-src_third__party_mozjs-38_platform_x86__64_netbsd_include_js-config.h,v 1.1 2019/06/28 16:30:56 gdt Exp $

--- src/third_party/mozjs-45/platform/x86_64/netbsd/include/js-config.h.orig	2016-02-11 12:24:33.328723425 +0000
+++ src/third_party/mozjs-45/platform/x86_64/netbsd/include/js-config.h
@@ -36,7 +36,7 @@
 
 /* Define to 1 if the <endian.h> header is present and
    useable.  See jscpucfg.h.  */
-#define JS_HAVE_ENDIAN_H 1
+/* #undef JS_HAVE_ENDIAN_H */
 
 /* Define to 1 if the <machine/endian.h> header is present and
    useable.  See jscpucfg.h.  */
