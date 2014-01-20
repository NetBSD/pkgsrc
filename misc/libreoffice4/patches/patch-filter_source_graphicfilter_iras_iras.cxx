$NetBSD: patch-filter_source_graphicfilter_iras_iras.cxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- filter/source/graphicfilter/iras/iras.cxx.orig	2014-01-18 01:06:39.000000000 +0000
+++ filter/source/graphicfilter/iras/iras.cxx
@@ -98,7 +98,7 @@ sal_Bool RASReader::ReadRAS(Graphic & rG
         return sal_False;
 
     maBmp = Bitmap( Size( mnWidth, mnHeight ), mnDstBitsPerPix );
-    if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == sal_False )
+    if ( ( mpAcc = maBmp.AcquireWriteAccess() ) == NULL )
         return sal_False;
 
     if ( mnDstBitsPerPix <= 8 )     // paletten bildchen
