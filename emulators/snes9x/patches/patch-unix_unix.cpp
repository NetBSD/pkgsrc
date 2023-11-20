$NetBSD: patch-unix_unix.cpp,v 1.5 2023/11/20 10:19:00 nia Exp $

Avoid colliding with libc functions.
https://github.com/snes9xgit/snes9x/pull/887

--- unix/unix.cpp.orig	2022-03-03 16:41:25.000000000 +0000
+++ unix/unix.cpp
@@ -164,7 +164,7 @@ static bool8 ReadJoysticks (void);
 void S9xLatchJSEvent();
 #endif
 
-static long log2 (long num)
+static long snes9x_log2 (long num)
 {
 	long	n = 0;
 
@@ -1467,7 +1467,7 @@ bool8 S9xOpenSoundDevice (void)
 		bool(unixSettings.ThreadSound)
 	);
 
-	J = log2(unixSettings.SoundFragmentSize) | (4 << 16);
+	J = snes9x_log2(unixSettings.SoundFragmentSize) | (4 << 16);
 	if (ioctl(so.sound_fd, SNDCTL_DSP_SETFRAGMENT, &J) == -1)
 		return (FALSE);
 
