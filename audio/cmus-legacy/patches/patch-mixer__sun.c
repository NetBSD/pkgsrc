$NetBSD: patch-mixer__sun.c,v 1.1 2024/03/16 17:53:11 nia Exp $

Fix building on SunOS.

--- mixer_sun.c.orig	2015-06-29 09:56:08.000000000 +0000
+++ mixer_sun.c
@@ -54,6 +54,7 @@ static int sun_mixer_get_option(int, cha
 
 static int mixer_open(const char *dev)
 {
+#ifdef AUDIO_MIXER_DEVINFO
 	struct mixer_devinfo minf;
 	int output_class;
 
@@ -99,6 +100,7 @@ static int mixer_open(const char *dev)
 
 	if (sun_mixer_volume_delta == 0)
 		sun_mixer_volume_delta = 1;
+#endif
 
 	return 0;
 
@@ -191,6 +193,7 @@ static int sun_mixer_close(void)
 
 static int sun_mixer_set_volume(int l, int r)
 {
+#ifdef AUDIO_MIXER_DEVINFO
 	struct mixer_ctrl minf;
 	int ovall, ovalr;
 
@@ -214,12 +217,14 @@ static int sun_mixer_set_volume(int l, i
 
 	if (ioctl(mixer_fd, AUDIO_MIXER_WRITE, &minf) == -1)
 		return -1;
+#endif
 
 	return 0;
 }
 
 static int sun_mixer_get_volume(int *l, int *r)
 {
+#ifdef AUDIO_MIXER_DEVINFO
 	struct mixer_ctrl minf;
 
 	minf.dev = sun_mixer_device_id;
@@ -236,6 +241,7 @@ static int sun_mixer_get_volume(int *l, 
 		*l = minf.un.value.level[AUDIO_MIXER_LEVEL_LEFT];
 		*r = minf.un.value.level[AUDIO_MIXER_LEVEL_RIGHT];
 	}
+#endif
 
 	return 0;
 }
