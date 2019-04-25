$NetBSD: patch-unix_unix.cpp,v 1.3 2019/04/25 13:06:58 nia Exp $

Avoid colliding with libc functions.

--- unix/unix.cpp.orig	2019-04-23 18:57:18.000000000 +0000
+++ unix/unix.cpp
@@ -156,7 +156,7 @@ bool S9xDisplayPollButton (uint32, bool 
 bool S9xDisplayPollAxis (uint32, int16 *);
 bool S9xDisplayPollPointer (uint32, int16 *, int16 *);
 
-static long log2 (long);
+static long log2_l (long);
 static void SoundTrigger (void);
 static void InitTimer (void);
 static void NSRTControllerSetup (void);
@@ -230,7 +230,7 @@ void _makepath (char *path, const char *
 	}
 }
 
-static long log2 (long num)
+static long log2_l (long num)
 {
 	long	n = 0;
 
@@ -1356,7 +1356,7 @@ bool8 S9xOpenSoundDevice (void)
 		return (FALSE);
 	}
 
-	J = log2(unixSettings.SoundFragmentSize) | (4 << 16);
+	J = log2_l(unixSettings.SoundFragmentSize) | (4 << 16);
 	if (ioctl(so.sound_fd, SNDCTL_DSP_SETFRAGMENT, &J) == -1)
 		return (FALSE);
 
