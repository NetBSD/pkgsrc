$NetBSD: patch-src_Unix_prefs__unix.cpp,v 1.2 2023/07/21 01:07:06 charlotte Exp $

Use correct audio device on NetBSD.

--- src/Unix/prefs_unix.cpp.orig	2019-04-05 05:12:49.000000000 +0000
+++ src/Unix/prefs_unix.cpp
@@ -131,6 +131,9 @@ void AddPlatformPrefsDefaults(void)
 	} else {
 		PrefsReplaceString("mixer", "/dev/mixer");
 	}
+#elif defined (__NetBSD__)
+	PrefsReplaceString("dsp", "/dev/audio");
+	PrefsReplaceString("mixer", "/dev/mixer");
 #else
 	PrefsReplaceString("dsp", "/dev/dsp");
 	PrefsReplaceString("mixer", "/dev/mixer");
