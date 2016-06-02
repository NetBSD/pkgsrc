$NetBSD: patch-ao.c,v 1.1 2016/06/02 09:18:19 jperkin Exp $

Ensure structs are zero'd before use.

--- ao.c.orig	2012-03-25 12:27:49.000000000 +0000
+++ ao.c
@@ -299,6 +299,7 @@ void open_ao_playdevice(struct mad_heade
            and restore it afterwards */
         signal(SIGINT, SIG_DFL);
         
+        memset(&format, 0, sizeof(format));
         format.bits = 16;
         format.rate = header->samplerate;
         format.channels = (options.opt & MPG321_FORCE_STEREO) ? 2 : MAD_NCHANNELS(header);
