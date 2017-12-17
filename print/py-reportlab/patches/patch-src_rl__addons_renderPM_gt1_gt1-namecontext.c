$NetBSD: patch-src_rl__addons_renderPM_gt1_gt1-namecontext.c,v 1.2 2017/12/17 16:47:54 adam Exp $

memcpy() and co are found in <string.h> on POSIX systems.

--- src/rl_addons/renderPM/gt1/gt1-namecontext.c.orig	2013-03-14 11:30:09.000000000 +0000
+++ src/rl_addons/renderPM/gt1/gt1-namecontext.c
@@ -3,9 +3,7 @@
 #include "gt1-misc.h"
 
 #include "gt1-namecontext.h"
-#if defined(_WIN32) || defined(macintosh)
-#	include <string.h>
-#endif
+#include <string.h>
 
 /* btw, I do not know who wrote the following comment. I modified this
    file somewhat from gimp's app/procedural_db.c hash function. */
