$NetBSD: patch-audio_out_ao__alsa.c,v 1.1 2019/06/01 01:15:54 tsutsui Exp $

- pull a compat definition of ESTRPIPE for non-Linux OSes
  from alsa-lib-1.1.4.1/include/type_compat.h

--- audio/out/ao_alsa.c.orig	2018-10-02 19:03:41.000000000 +0000
+++ audio/out/ao_alsa.c
@@ -49,6 +49,10 @@
 #define HAVE_CHMAP_API 0
 #endif
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
+
 #include "ao.h"
 #include "internal.h"
 #include "audio/format.h"
