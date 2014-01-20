$NetBSD: patch-filter_source_graphicfilter_ipcd_ipcd.cxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- filter/source/graphicfilter/ipcd/ipcd.cxx.orig	2014-01-18 01:28:01.000000000 +0000
+++ filter/source/graphicfilter/ipcd/ipcd.cxx
@@ -151,7 +151,7 @@ sal_Bool PCDReader::ReadPCD( Graphic & r
             nBMPHeight = nWidth;
         }
         aBmp = Bitmap( Size( nBMPWidth, nBMPHeight ), 24 );
-        if ( ( mpAcc = aBmp.AcquireWriteAccess() ) == sal_False )
+        if ( ( mpAcc = aBmp.AcquireWriteAccess() ) == NULL )
             return sal_False;
 
         ReadImage( 5 ,65 );
