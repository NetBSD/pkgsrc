$NetBSD: patch-Makefile.PL,v 1.1 2014/01/27 06:07:59 obache Exp $

* get freetype2 configuration with "freetype-config" command.

--- Makefile.PL.orig	2004-09-10 00:43:29.000000000 +0000
+++ Makefile.PL
@@ -5,8 +5,8 @@ WriteMakefile(
     NAME            => 'Font::FreeType',
     AUTHOR          => 'Geoff Richards <qef@laxan.com>',
     VERSION_FROM    => 'lib/Font/FreeType.pm',
-    LIBS            => [ '-lfreetype' ],
-    INC             => '-I/usr/include/freetype2',
+    LIBS            => `freetype-config --libs`,
+    INC             => `freetype-config --cflags`,
     NO_META         => 1,
 );
 
