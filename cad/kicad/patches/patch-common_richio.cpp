$NetBSD: patch-common_richio.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $

Fix non-portable use of setvbuf()
Reported upstream as bug id 1280897

--- common/richio.cpp.orig	2014-02-15 20:22:32.000000000 +0100
+++ common/richio.cpp	2014-02-15 20:23:12.000000000 +0100
@@ -157,7 +157,7 @@
 {
     if( doOwn && ftell( aFile ) == 0L )
     {
-#ifndef __WXMAC__
+#if !defined(__WXMAC__) && !defined(__NetBSD__)
         setvbuf( fp, NULL, _IOFBF, BUFSIZ * 8 );
 #endif
     }
