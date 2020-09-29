$NetBSD: patch-plugins_dfsound_cfg.c,v 1.1 2020/09/29 12:23:03 nia Exp $

waitpid code is compiled unconditionally.

--- plugins/dfsound/cfg.c.orig	2019-03-06 11:37:17.000000000 +0000
+++ plugins/dfsound/cfg.c
@@ -26,10 +26,8 @@
 ////////////////////////////////////////////////////////////////////////
 
 #include <unistd.h>
-#if defined(__linux__)
 #include <sys/types.h>
 #include <sys/wait.h>
-#endif
 
 ////////////////////////////////////////////////////////////////////////
 // START EXTERNAL CFG TOOL
