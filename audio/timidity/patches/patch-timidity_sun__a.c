$NetBSD: patch-timidity_sun__a.c,v 1.1 2017/03/30 18:44:13 nat Exp $

Ensure to set the channel for the audioctl device.
This is required due to the virtual channels in audio.

--- timidity/sun_a.c.orig	2009-12-23 11:57:03.000000000 +0000
+++ timidity/sun_a.c
@@ -204,6 +204,12 @@ static int open_output(void)
 	return -1;
     }
 
+#ifdef AUDIO_GETCHAN
+    int chan;
+    if (ioctl(dpm.fd, AUDIO_GETCHAN, &chan) >= 0)
+	ioctl(audioctl_fd, AUDIO_SETCHAN, &chan);
+#endif
+
     if(stat(dpm.name, &sb) < 0)
     {
 	ctl->cmsg(CMSG_ERROR, VERB_NORMAL,
