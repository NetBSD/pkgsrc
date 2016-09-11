$NetBSD: patch-src_rl__addons_renderPM_gt1_gt1-namecontext.c,v 1.1 2016/09/11 15:53:51 richard Exp $
memcpy() and co are found in <string.h> on POSIX systems.

--- src/rl_addons/renderPM/gt1/gt1-namecontext.c.orig	2013-03-14 11:30:09.000000000 +0000
+++ src/rl_addons/renderPM/gt1/gt1-namecontext.c
@@ -3,7 +3,7 @@
 #include "gt1-misc.h"
 
 #include "gt1-namecontext.h"
-#if defined(_WIN32) || defined(macintosh)
+#if 1
 #	include <string.h>
 #endif
 
