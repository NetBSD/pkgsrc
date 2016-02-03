$NetBSD: patch-common_richio.cpp,v 1.2 2016/02/03 19:34:33 bouyer Exp $

Fix non-portable use of setvbuf()
Reported upstream as bug id 1280897

--- common/richio.cpp.orig	2015-12-11 17:40:20.000000000 +0100
+++ common/richio.cpp	2015-12-11 17:39:05.000000000 +0100
@@ -215,7 +215,7 @@
 {
     if( doOwn && ftell( aFile ) == 0L )
     {
-#ifndef __WXMAC__
+#if !defined(__WXMAC__) && !defined(__NetBSD__)
         setvbuf( fp, NULL, _IOFBF, BUFSIZ * 8 );
 #endif
     }
