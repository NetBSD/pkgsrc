$NetBSD: patch-src_zmf.cpp,v 1.4 2022/09/27 01:20:39 gdt Exp $

\todo Explain

--- src/zmf.cpp.orig	2019-02-22 15:38:47.000000000 +0000
+++ src/zmf.cpp
@@ -331,7 +331,7 @@ int main( int argc, char *argv[] )
     Debug( 1, "Got image, writing to %s", path );
 
     FILE *fd = 0;
-    if ( (fd = fopen( path, "w" )) < 0 )
+    if ( (fd = fopen( path, "w" )) == 0 )
     {
       Error( "Can't fopen '%s': %s", path, strerror(errno) );
       exit( -1 );
