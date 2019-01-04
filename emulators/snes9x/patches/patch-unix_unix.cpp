$NetBSD: patch-unix_unix.cpp,v 1.2 2019/01/04 23:34:36 nia Exp $

Avoid colliding with libc functions.

--- unix/unix.cpp.orig	2018-12-16 17:04:59.000000000 +0000
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
 
@@ -1324,7 +1324,7 @@ bool8 S9xOpenSoundDevice (void)
 		return (FALSE);
 	}
 
-	J = log2(unixSettings.SoundFragmentSize) | (3 << 16);
+	J = log2_l(unixSettings.SoundFragmentSize) | (3 << 16);
 	if (ioctl(so.sound_fd, SNDCTL_DSP_SETFRAGMENT, &J) == -1)
 		return (FALSE);
 
