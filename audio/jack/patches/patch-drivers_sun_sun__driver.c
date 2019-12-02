$NetBSD: patch-drivers_sun_sun__driver.c,v 1.1 2019/12/02 11:46:08 nia Exp $

NetBSD support changes:

- Don't try to poll() /dev/audio
- Don't write silence to "prime" the driver
- Block size does not relate to period
- AUDIO_SETFD is deprecated

--- drivers/sun/sun_driver.c.orig	2016-02-23 15:13:53.000000000 +0000
+++ drivers/sun/sun_driver.c
@@ -383,7 +383,12 @@ sun_driver_run_cycle (sun_driver_t *driv
 	int wait_status;
 	float iodelay;
 
+#ifdef __NetBSD__
+	wait_status = 0;
+	nframes = driver->period_size;
+#else
 	nframes = sun_driver_wait (driver, &wait_status, &iodelay);
+#endif
 
 	if (wait_status < 0) {
 		switch (wait_status) {
@@ -650,8 +655,10 @@ sun_driver_start (sun_driver_t *driver)
 		 * be available to read before we can write.  also helps to
 		 * keep constant latency from the beginning.
 		 */
+#ifndef __NetBSD__
 		sun_driver_write_silence (driver,
 					  driver->nperiods * driver->period_size);
+#endif
 	}
 
 	if (driver->infd >= 0) {
@@ -732,7 +739,7 @@ sun_driver_set_parameters (sun_driver_t 
 				    __FILE__, __LINE__);
 			return -1;
 		}
-#if defined(AUDIO_SETFD)
+#if defined(AUDIO_SETFD) && !defined(__NetBSD__)
 		if (ioctl (infd, AUDIO_SETFD, &s) < 0) {
 			jack_error ("sun_driver: failed to enable full duplex: "
 				    "%s: %s@%i", strerror (errno),
@@ -797,15 +804,6 @@ sun_driver_set_parameters (sun_driver_t 
 		audio_if_out.play.block_size = driver->playback_channels *
 					       driver->period_size * driver->sample_bytes;
 	}
-#else
-	if (driver->infd >= 0) {
-		audio_if_in.blocksize = driver->capture_channels *
-					driver->period_size * driver->sample_bytes;
-	}
-	if (driver->outfd >= 0) {
-		audio_if_out.blocksize =  driver->playback_channels *
-					 driver->period_size * driver->sample_bytes;
-	}
 #endif
 	if (infd == outfd) {
 		audio_if_in.play = audio_if_out.play;
@@ -871,9 +869,6 @@ sun_driver_set_parameters (sun_driver_t 
 #if defined(__OpenBSD__)
 		cap_period = audio_if_in.record.block_size /
 			     driver->capture_channels / driver->sample_bytes;
-#elif defined(__NetBSD__)
-		cap_period = audio_if_in.blocksize /
-			     driver->capture_channels / driver->sample_bytes;
 #else
 		/* how is this done on Solaris? */
 		cap_period = driver->period_size;
@@ -903,9 +898,6 @@ sun_driver_set_parameters (sun_driver_t 
 #if defined(__OpenBSD__)
 		play_period = audio_if_out.play.block_size /
 			      driver->playback_channels / driver->sample_bytes;
-#elif defined(__NetBSD__)
-		play_period = audio_if_out.blocksize /
-			      driver->playback_channels / driver->sample_bytes;
 #else
 		/* how is this done on Solaris? */
 		play_period = driver->period_size;
