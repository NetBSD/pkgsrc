$NetBSD: patch-src_yabause.c,v 1.1 2016/10/16 10:10:02 bsiegert Exp $

--- src/yabause.c.orig	2014-11-12 17:48:48.000000000 +0000
+++ src/yabause.c
@@ -48,7 +48,7 @@
 #include "movie.h"
 #include "osdcore.h"
 #ifdef HAVE_LIBSDL
- #if defined(__APPLE__) || defined(GEKKO)
+ #if defined(GEKKO)
   #include <SDL/SDL.h>
  #else
   #include "SDL.h"
