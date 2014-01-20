$NetBSD: patch-filter_source_graphicfilter_ipcx_ipcx.cxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- filter/source/graphicfilter/ipcx/ipcx.cxx.orig	2014-01-18 01:07:26.000000000 +0000
+++ filter/source/graphicfilter/ipcx/ipcx.cxx
@@ -100,7 +100,7 @@ sal_Bool PCXReader::ReadPCX(Graphic & rG
     if ( nStatus )
     {
         aBmp = Bitmap( Size( nWidth, nHeight ), nDestBitsPerPixel );
-        if ( ( pAcc = aBmp.AcquireWriteAccess() ) == sal_False )
+        if ( ( pAcc = aBmp.AcquireWriteAccess() ) == NULL )
             return sal_False;
 
         if ( nDestBitsPerPixel <= 8 )
