$NetBSD: patch-plugins_dfinput_pad.c,v 1.1 2020/09/29 12:23:03 nia Exp $

Make the code more generic.

--- plugins/dfinput/pad.c.orig	2019-03-06 11:37:17.000000000 +0000
+++ plugins/dfinput/pad.c
@@ -17,10 +17,10 @@
  */
 
 #include "pad.h"
-#if defined(__linux__)
+#if defined(__unix__)
 #include <sys/types.h>
 #include <sys/wait.h>
-#if !SDL_VERSION_ATLEAST(2,0,0)
+#if !SDL_VERSION_ATLEAST(2,0,0) && defined(__linux__)
 #include <linux/input.h>
 #include <sys/file.h>
 #include <time.h>
