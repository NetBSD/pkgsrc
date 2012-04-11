$NetBSD: patch-libtiff_tiffiop.h,v 1.1.2.2 2012/04/11 10:06:48 tron Exp $

Fix for CVE-2012-1173 from upstream.

--- libtiff/tiffiop.h.orig	2011-02-19 16:26:09.000000000 +0000
+++ libtiff/tiffiop.h
@@ -250,7 +250,7 @@ struct tiff {
 #define TIFFroundup_64(x, y) (TIFFhowmany_64(x,y)*(y))
 
 /* Safe multiply which returns zero if there is an integer overflow */
-#define TIFFSafeMultiply(t,v,m) ((((t)m != (t)0) && (((t)((v*m)/m)) == (t)v)) ? (t)(v*m) : (t)0)
+#define TIFFSafeMultiply(t,v,m) ((((t)(m) != (t)0) && (((t)(((v)*(m))/(m))) == (t)(v))) ? (t)((v)*(m)) : (t)0)
 
 #define TIFFmax(A,B) ((A)>(B)?(A):(B))
 #define TIFFmin(A,B) ((A)<(B)?(A):(B))
