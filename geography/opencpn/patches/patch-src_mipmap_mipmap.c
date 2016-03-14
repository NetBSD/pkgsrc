$NetBSD: patch-src_mipmap_mipmap.c,v 1.1 2016/03/14 11:01:06 bouyer Exp $

be consistent with #if where the function is defined

--- src/mipmap/mipmap.c.orig	2016-02-10 16:22:54.000000000 +0100
+++ src/mipmap/mipmap.c	2016-02-10 16:23:26.000000000 +0100
@@ -184,7 +184,7 @@
             MipMap_24 = MipMap_24_ssse3;
     }
     
-#if (GCC_VERSION > 40800) || defined(__MSVC__)
+#if defined(__AVX2__) || (defined(__MSVC__) &&  (_MSC_VER >= 1700))
     if (nIds >= 0x00000007) {
         cpuid(info,0x00000007);
 
