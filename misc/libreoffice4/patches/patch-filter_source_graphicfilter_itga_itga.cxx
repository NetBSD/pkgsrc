$NetBSD: patch-filter_source_graphicfilter_itga_itga.cxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- filter/source/graphicfilter/itga/itga.cxx.orig	2014-01-18 01:07:38.000000000 +0000
+++ filter/source/graphicfilter/itga/itga.cxx
@@ -732,7 +732,7 @@ sal_Bool TGAReader::ImplReadPalette()
             mpFileHeader->nColorMapEntrySize = 0x3f;    // patch for the following switch routine
         }
         mpColorMap = new sal_uInt32[ nColors ];     // we will always index dwords
-        if ( mpColorMap == sal_False )
+        if ( mpColorMap == NULL )
             return sal_False;                       // out of memory %&!$&/!"�$
 
         switch( mpFileHeader->nColorMapEntrySize )
