$NetBSD: patch-src_sndsdl.c,v 1.1 2016/10/16 10:10:02 bsiegert Exp $

--- src/sndsdl.c.orig	2014-11-12 17:48:48.000000000 +0000
+++ src/sndsdl.c
@@ -25,7 +25,7 @@
 
 #include <stdlib.h>
 
-#if defined(__APPLE__) || defined(GEKKO)
+#if defined(GEKKO)
  #include <SDL/SDL.h>
 #else
  #include "SDL.h"
