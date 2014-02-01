$NetBSD: patch-appFrame_appFontConfig.c,v 1.1 2014/02/01 03:46:49 markd Exp $

Build with freetype 2.5.x

--- appFrame/appFontConfig.c.orig	2009-10-16 15:20:57.000000000 +0000
+++ appFrame/appFontConfig.c
@@ -903,7 +903,7 @@ const char * appFtErrorStr( int e )
 
     static const n2s xftn2s[]=
     {
-#   include <freetype/fterrdef.h>
+#   include FT_ERROR_DEFINITIONS_H
     };
 
     for ( i= 0; i < sizeof(xftn2s)/sizeof(n2s); i++ )
