$NetBSD: patch-libtiff_tiffiop.h,v 1.3 2017/05/07 21:32:30 he Exp $

CVE-2016-10266
http://bugzilla.maptools.org/show_bug.cgi?id=2596
https://github.com/vadz/libtiff/commit/438274f938e046d33cb0e1230b41da32ffe223e1

--- libtiff/tiffiop.h.orig	2016-01-24 15:39:51.000000000 +0000
+++ libtiff/tiffiop.h
@@ -250,6 +250,10 @@ struct tiff {
 #define TIFFhowmany_32(x, y) (((uint32)x < (0xffffffff - (uint32)(y-1))) ? \
 			   ((((uint32)(x))+(((uint32)(y))-1))/((uint32)(y))) : \
 			   0U)
+/* Variant of TIFFhowmany_32() that doesn't return 0 if x close to MAXUINT. */
+/* Caution: TIFFhowmany_32_maxuint_compat(x,y)*y might overflow */
+#define TIFFhowmany_32_maxuint_compat(x, y) \
+			   (((uint32)(x) / (uint32)(y)) + ((((uint32)(x) % (uint32)(y)) != 0) ? 1 : 0))
 #define TIFFhowmany8_32(x) (((x)&0x07)?((uint32)(x)>>3)+1:(uint32)(x)>>3)
 #define TIFFroundup_32(x, y) (TIFFhowmany_32(x,y)*(y))
 #define TIFFhowmany_64(x, y) ((((uint64)(x))+(((uint64)(y))-1))/((uint64)(y)))
