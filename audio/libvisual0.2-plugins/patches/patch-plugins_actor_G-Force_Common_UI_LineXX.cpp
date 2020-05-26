$NetBSD: patch-plugins_actor_G-Force_Common_UI_LineXX.cpp,v 1.1 2020/05/26 11:25:34 joerg Exp $

--- plugins/actor/G-Force/Common/UI/LineXX.cpp.orig	2020-05-26 00:26:16.970444766 +0000
+++ plugins/actor/G-Force/Common/UI/LineXX.cpp
@@ -74,13 +74,13 @@
 
 		
 	#if CLR_INTERP && P_SZ != 1
-	long len = sqrt( dx * dx + dy * dy ) + 1;
+	long len = sqrt( double(dx * dx + dy * dy) ) + 1;
 	dR /= len;
 	dG /= len;
 	dB /= len;
 	color = __Clr( R, G, B );
 	#elif CLR_INTERP && P_SZ == 1
-	long len = sqrt( dx * dx + dy * dy ) + 1;
+	long len = sqrt( double(dx * dx + dy * dy) ) + 1;
 	dR /= len;
 	color = __Clr( R, G, B );
 	#endif
@@ -154,7 +154,7 @@
 		
 			for ( j = 0; j < tw; j++ ) {
 				long tmp = j - halfW;
-				c_x = halfW - ( ( long ) sqrt( halfW * halfW - tmp * tmp ) );
+				c_x = halfW - ( ( long ) sqrt(double( halfW * halfW - tmp * tmp )) );
 				center = basePtr + (j-halfW) * mBytesPerRow;
 				for ( int k = c_x; k < tw - c_x; k++ ){
 					((PIXTYPE*) center)[k-halfW] = color;
