$NetBSD: patch-sdl-gui_sdl.c,v 1.1 2016/03/23 14:21:03 hauke Exp $

Fix #include path

--- sdl-gui/sdl.c.orig	2015-09-14 02:11:18.000000000 +0000
+++ sdl-gui/sdl.c
@@ -220,7 +220,7 @@ struct {
 #if !((defined WIN32) || (defined _WIN64))
 #include <sys/types.h>
 #include <pwd.h>
-#include <uuid/uuid.h>
+#include <uuid.h>
 #endif
 
 static char* _get_home_dir (const char *terminal_element)
