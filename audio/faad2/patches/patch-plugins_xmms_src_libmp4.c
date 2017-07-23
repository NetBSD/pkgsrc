$NetBSD: patch-plugins_xmms_src_libmp4.c,v 1.1 2017/07/23 16:09:17 adam Exp $

Use external include, as this will be build from audio/xmms-faad.

--- plugins/xmms/src/libmp4.c.orig	2007-06-05 21:00:18.000000000 +0200
+++ plugins/xmms/src/libmp4.c
@@ -23,7 +23,7 @@
 #include <xmms/titlestring.h>
 #endif /*HAVE_BMP*/
 
-#include "neaacdec.h"
+#include <neaacdec.h>
 #include "mp4ff.h"
 
 #define MP4_DESCRIPTION	"MP4 & MPEG2/4-AAC audio player - 1.2.x"
