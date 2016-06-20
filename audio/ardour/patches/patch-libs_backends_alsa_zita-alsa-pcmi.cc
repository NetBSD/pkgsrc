$NetBSD: patch-libs_backends_alsa_zita-alsa-pcmi.cc,v 1.1 2016/06/20 08:17:43 kamil Exp $

Add support for NetBSD:
- ppoll() on Linux is close to pollts(2) on NetBSD
- NetBSD ships with <sys/endian.h>, not <endian.h>

--- libs/backends/alsa/zita-alsa-pcmi.cc.orig	2016-02-19 01:28:56.000000000 +0000
+++ libs/backends/alsa/zita-alsa-pcmi.cc
@@ -18,7 +18,11 @@
 // ----------------------------------------------------------------------------
 
 
+#if defined(__NetBSD__)
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 #include <sys/time.h>
 #include "zita-alsa-pcmi.h"
 
@@ -175,7 +179,11 @@ snd_pcm_sframes_t Alsa_pcmi::pcm_wait (v
 		timespec timeout;
 		timeout.tv_sec = 1;
 		timeout.tv_nsec = 0;
+#if defined(__NetBSD__)
+		r = pollts (_poll_fd, n2, &timeout, NULL);
+#else
 		r = ppoll (_poll_fd, n2, &timeout, NULL);
+#endif
 
 		if (r < 0)
 		{
