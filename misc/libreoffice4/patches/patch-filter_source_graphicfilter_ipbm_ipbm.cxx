$NetBSD: patch-filter_source_graphicfilter_ipbm_ipbm.cxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- filter/source/graphicfilter/ipbm/ipbm.cxx.orig	2014-01-18 01:03:34.000000000 +0000
+++ filter/source/graphicfilter/ipbm/ipbm.cxx
@@ -102,7 +102,7 @@ sal_Bool PBMReader::ReadPBM(Graphic & rG
     {
         case 0 :
             maBmp = Bitmap( Size( mnWidth, mnHeight ), 1 );
-            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == sal_False )
+            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == NULL )
                 return sal_False;
             mpAcc->SetPaletteEntryCount( 2 );
             mpAcc->SetPaletteColor( 0, BitmapColor( 0xff, 0xff, 0xff ) );
@@ -117,7 +117,7 @@ sal_Bool PBMReader::ReadPBM(Graphic & rG
             else
                 maBmp = Bitmap( Size( mnWidth, mnHeight ), 8);
 
-            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == sal_False )
+            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == NULL )
                 return sal_False;
             mnCol = (sal_uInt16)mnMaxVal + 1;
             if ( mnCol > 256 )
@@ -132,7 +132,7 @@ sal_Bool PBMReader::ReadPBM(Graphic & rG
             break;
         case 2 :
             maBmp = Bitmap( Size( mnWidth, mnHeight ), 24 );
-            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == sal_False )
+            if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == NULL )
                 return sal_False;
             break;
     }
