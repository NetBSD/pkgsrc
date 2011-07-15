$NetBSD: patch-util_szap_szap.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- util/szap/szap.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ util/szap/szap.c
@@ -44,9 +44,13 @@
 #include <stdint.h>
 #include <sys/time.h>
 
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/frontend.h>
 #include <linux/dvb/dmx.h>
 #include <linux/dvb/audio.h>
+#endif
 #include "lnb.h"
 #include "util.h"
 
@@ -304,8 +308,10 @@ int zap_to(unsigned int adapter, unsigne
    if (diseqc(fefd, sat_no, pol, hiband))
       if (do_tune(fefd, ifreq, sr))
 	 if (set_pesfilter(dmxfdv, vpid, DMX_PES_VIDEO, dvr))
+#ifdef AUDIO_SET_BYPASS_MODE
 	    if (audiofd >= 0)
 	       (void)ioctl(audiofd, AUDIO_SET_BYPASS_MODE, bypass);
+#endif
 	    if (set_pesfilter(dmxfda, apid, DMX_PES_AUDIO, dvr)) {
 	       if (rec_psi) {
 	          pmtpid = get_pmt_pid(dmxdev, sid);
