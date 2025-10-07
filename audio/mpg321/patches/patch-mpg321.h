$NetBSD: patch-mpg321.h,v 1.1 2025/10/07 03:56:02 mrg Exp $

Add / uncomment missing prototypes for GCC 14.


--- mpg321.h.orig	2012-03-25 05:27:49.000000000 -0700
+++ mpg321.h	2025-09-29 14:04:56.946748517 -0700
@@ -242,7 +242,7 @@
 } fft_state;
 
 typedef short int sound_sample;
-//void fft_perform(const sound_sample *input, double *output, fft_state *state);
+void fft_perform(const sound_sample *input, double *output, fft_state *state);
 
 fft_state *fft_init(void);
 
@@ -303,4 +303,9 @@
 /* Get the next encoding/decoding place in the frame buffer */
 int getnext_place(int position);
 
+int calc_http_length(buffer *buf);
+void do_basicauth(void);
+ao_device *open_ao_playdevice_buffer(struct mad_header const *header);
+int check_default_play_device_buffer(void);
+
 #endif /* _MPG321_H_ */
