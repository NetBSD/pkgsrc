$NetBSD: patch-src_persdljoy.c,v 1.1 2016/10/16 10:10:02 bsiegert Exp $

--- src/persdljoy.c.orig	2014-11-12 17:48:47.000000000 +0000
+++ src/persdljoy.c
@@ -24,11 +24,7 @@
 */
 
 #ifdef HAVE_LIBSDL
-#ifdef __APPLE__
-	#include <SDL/SDL.h>
-#else
-	#include "SDL.h"
-#endif
+#include "SDL.h"
 
 #include "debug.h"
 #include "persdljoy.h"
