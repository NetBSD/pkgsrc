$NetBSD: patch-cmd_ossplay_ossplay.c,v 1.1 2021/05/09 09:06:59 nia Exp $

Missing features in libossaudio...

--- cmd/ossplay/ossplay.c.orig	2021-05-09 08:59:30.843013379 +0000
+++ cmd/ossplay/ossplay.c
@@ -448,6 +448,7 @@ select_playtgt (dspdev_t * dsp)
   int i, src;
   oss_mixer_enuminfo ei;
 
+#ifdef SNDCTL_DSP_GET_PLAYTGT_NAMES
   if (ioctl (dsp->fd, SNDCTL_DSP_GET_PLAYTGT_NAMES, &ei) == -1)
     {
       perror_msg ("SNDCTL_DSP_GET_PLAYTGT_NAMES");
@@ -491,6 +492,7 @@ select_playtgt (dspdev_t * dsp)
 	  return;
 	}
     }
+#endif
 
   print_msg (ERRORM,
 	     "Unknown playback target name '%s' - use -o? to get the list\n",
@@ -509,6 +511,7 @@ select_recsrc (dspdev_t * dsp)
   int i, src;
   oss_mixer_enuminfo ei;
 
+#ifdef SNDCTL_DSP_GET_RECSRC_NAMES
   if (ioctl (dsp->fd, SNDCTL_DSP_GET_RECSRC_NAMES, &ei) == -1)
     {
       perror_msg ("SNDCTL_DSP_GET_RECSRC_NAMES");
@@ -551,6 +554,7 @@ select_recsrc (dspdev_t * dsp)
 	  return;
 	}
     }
+#endif
 
   print_msg (ERRORM,
 	     "Unknown recording source name '%s' - use -i? to get the list\n",
@@ -1048,6 +1052,7 @@ int
 play (dspdev_t * dsp, int fd, big_t * datamark, big_t bsize, double total_time,
       double constant, readfunc_t * readf, decoders_queue_t * dec, seekfunc_t * seekf)
 {
+#ifdef SNDCTL_DSP_HALT_OUTPUT
 #define EXITPLAY(code) \
   do { \
     ossplay_free (buf); \
@@ -1057,6 +1062,16 @@ play (dspdev_t * dsp, int fd, big_t * da
     errno = 0; \
     return (code); \
   } while (0)
+#else
+#define EXITPLAY(code) \
+  do { \
+    ossplay_free (buf); \
+    ossplay_free (verbose_meta); \
+    clear_update (); \
+    errno = 0; \
+    return (code); \
+  } while (0)
+#endif
 
   big_t rsize = bsize;
   big_t filesize = *datamark;
@@ -1151,6 +1166,7 @@ int
 record (dspdev_t * dsp, FILE * wave_fp, const char * filename, double constant,
         double datatime, big_t * data_size, decoders_queue_t * dec)
 {
+#ifdef SNDCTL_DSP_HALT_INPUT
 #define EXITREC(code) \
   do { \
     ossplay_free (buf); \
@@ -1161,6 +1177,17 @@ record (dspdev_t * dsp, FILE * wave_fp, 
     ioctl (dsp->fd, SNDCTL_DSP_HALT_INPUT, NULL); \
     return (code); \
   } while(0)
+#else
+#define EXITREC(code) \
+  do { \
+    ossplay_free (buf); \
+    ossplay_free (verbose_meta); \
+    clear_update (); \
+    if ((eflag) && (verbose)) \
+      print_msg (VERBOSEM, "\nStopped (%d).\n", eflag-128); \
+    return (code); \
+  } while(0)
+#endif
 
   unsigned char * buf, * obuf;
   ssize_t l, outl;
