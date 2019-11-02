$NetBSD: patch-Frontends_csound_csound_main.c,v 1.1 2019/11/02 22:25:46 mrg Exp $

Port to NetBSD and DragonFly.

--- Frontends/csound/csound_main.c.orig	2019-07-12 14:54:19.000000000 -0700
+++ Frontends/csound/csound_main.c	2019-10-29 15:16:17.231498474 -0700
@@ -73,7 +73,8 @@
 
 #if defined(ANDROID) || (!defined(LINUX) && !defined(SGI) && \
                          !defined(__HAIKU__) && !defined(__BEOS__) && \
-                         !defined(__MACH__) && !defined(__EMSCRIPTEN__))
+                         !defined(__MACH__) && !defined(__EMSCRIPTEN__) && \
+                         !defined(__NetBSD__) && !defined(__DragonFly__))
 static char *signal_to_string(int sig)
 {
     switch(sig) {
