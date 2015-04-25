$NetBSD: patch-imagewin_manip.h,v 1.1 2015/04/25 00:56:04 joerg Exp $

Reference to member of base class must be explicit.

--- imagewin/manip.h.orig	2015-04-25 00:01:37.000000000 +0000
+++ imagewin/manip.h
@@ -319,7 +319,7 @@ public:
 	static uintD copy(uintS src)
 	{
 		unsigned int r, g, b;
-		split_source(src,r,g,b);
+		ManipBaseSrc<color_s,color_d>::split_source(src,r,g,b);
 		return ManipBaseDest<color_d>::rgb(r,g,b);
 	}
 	static void copy(uintD& dest, uintS src)
