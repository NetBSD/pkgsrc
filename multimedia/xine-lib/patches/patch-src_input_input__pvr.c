$NetBSD: patch-src_input_input__pvr.c,v 1.1 2020/12/20 12:53:58 nia Exp $

Use standard type. Fixes build on NetBSD.

--- src/input/input_pvr.c.orig	2020-11-19 10:30:37.000000000 +0000
+++ src/input/input_pvr.c
@@ -1046,7 +1046,7 @@ static void pvr_event_handler (pvr_input
 
         vf.tuner = 0;
         vf.type = vt.type;
-        vf.frequency = (__u32)(freq * fac);
+        vf.frequency = (uint32_t)(freq * fac);
 
         if (ioctl(this->dev_fd, VIDIOC_S_FREQUENCY, &vf) == 0) {
           lprintf("Tuner Frequency set to %d (%f.3 MHz)\n", vf.frequency, vf.frequency / fac);
