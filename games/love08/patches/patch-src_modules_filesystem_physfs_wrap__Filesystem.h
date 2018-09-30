$NetBSD: patch-src_modules_filesystem_physfs_wrap__Filesystem.h,v 1.1 2018/09/30 19:12:48 maya Exp $

Match include path for SDL<2

--- src/modules/filesystem/physfs/wrap_Filesystem.h.orig	2012-04-06 18:15:01.000000000 +0000
+++ src/modules/filesystem/physfs/wrap_Filesystem.h
@@ -27,7 +27,7 @@
 #include "wrap_FileData.h"
 
 // SDL
-#include <SDL_loadso.h>
+#include <SDL/SDL_loadso.h>
 
 namespace love
 {
