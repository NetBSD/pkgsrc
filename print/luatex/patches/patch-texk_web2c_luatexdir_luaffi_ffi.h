$NetBSD: patch-texk_web2c_luatexdir_luaffi_ffi.h,v 1.1 2017/12/31 00:36:04 markd Exp $
gcc-7 fix - Dr. Werner Fink <werner@suse.de> 

--- texk/web2c/luatexdir/luaffi/ffi.h.orig	2017-03-11 01:04:06.000000000 +0000
+++ texk/web2c/luatexdir/luaffi/ffi.h
@@ -370,7 +370,7 @@ __declspec(align(16))
 #endif
 struct cdata {
     const struct ctype type
-#ifdef __GNUC__
+#if 0 /* def __GNUC__ */
       __attribute__ ((aligned(16)))
 #endif
       ;
