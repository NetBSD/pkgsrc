$NetBSD: patch-op_mixer__sun.c,v 1.1 2019/02/11 10:07:37 nia Exp $

Fix build on SunOS.

--- op/mixer_sun.c.orig	2011-11-30 09:57:20.000000000 +0100
+++ op/mixer_sun.c	2012-02-15 21:12:05.691072986 +0100
@@ -55,6 +55,7 @@ static int sun_mixer_get_option(int, cha
 
 static int mixer_open(const char *dev)
 {
+#ifdef AUDIO_MIXER_DEVINFO
 	struct mixer_devinfo minf;
 	int output_class;
 
@@ -100,6 +101,7 @@ static int mixer_open(const char *dev)
 
 	if (sun_mixer_volume_delta == 0)
 		sun_mixer_volume_delta = 1;
+#endif
 
 	return 0;
 
@@ -192,6 +194,7 @@ static int sun_mixer_close(void)
 
 static int sun_mixer_set_volume(int l, int r)
 {
+#ifdef AUDIO_MIXER_DEVINFO
 	struct mixer_ctrl minf;
 	int ovall, ovalr;
 
@@ -215,12 +218,14 @@ static int sun_mixer_set_volume(int l, i
 
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
@@ -237,6 +242,7 @@ static int sun_mixer_get_volume(int *l, 
 		*l = minf.un.value.level[AUDIO_MIXER_LEVEL_LEFT];
 		*r = minf.un.value.level[AUDIO_MIXER_LEVEL_RIGHT];
 	}
+#endif
 
 	return 0;
 }
