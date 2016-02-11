$NetBSD: patch-xmloff_source_draw_ximp3dscene.cxx,v 1.1 2016/02/11 09:45:27 ryoon Exp $

--- xmloff/source/draw/ximp3dscene.cxx.orig	2016-01-27 00:58:25.000000000 +0000
+++ xmloff/source/draw/ximp3dscene.cxx
@@ -31,6 +31,7 @@
 
 using namespace ::com::sun::star;
 using namespace ::xmloff::token;
+using namespace std;
 
 // dr3d:3dlight context
 
