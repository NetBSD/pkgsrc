$NetBSD: patch-src_filesystem_cocoa_SDL__sysfilesystem.m,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/filesystem/cocoa/SDL_sysfilesystem.m.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/filesystem/cocoa/SDL_sysfilesystem.m
@@ -25,6 +25,12 @@
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 /* System dependent filesystem routines                                */
 
+#if defined(__ALTIVEC__) && !defined(MAC_OS_X_VERSION_10_5)
+/* to cricumvent a bug in Mac OS X 10.4 SDK */
+#define vector __vector
+#include <CoreServices/CoreServices.h>
+#undef vector
+#endif
 #include <Foundation/Foundation.h>
 #include <sys/stat.h>
 #include <sys/types.h>
