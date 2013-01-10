$NetBSD: patch-content_media_nsAudioStream.cpp,v 1.1 2013/01/10 16:17:10 ryoon Exp $

* Bug 685258 - Pulse audio backend does not check provided playback and crashes

--- content/media/nsAudioStream.cpp.orig	2012-11-13 14:56:39.000000000 +0000
+++ content/media/nsAudioStream.cpp
@@ -298,7 +298,11 @@ static int PrefChanged(const char* aPref
       gVolumeScale = NS_MAX<double>(0, PR_strtod(utf8.get(), nullptr));
     }
   } else if (strcmp(aPref, PREF_USE_CUBEB) == 0) {
+#if defined(__FreeBSD__) && __FreeBSD_version < 800097
+    bool value = Preferences::GetBool(aPref, false);
+#else
     bool value = Preferences::GetBool(aPref, true);
+#endif
     mozilla::MutexAutoLock lock(*gAudioPrefsLock);
     gUseCubeb = value;
   } else if (strcmp(aPref, PREF_CUBEB_LATENCY) == 0) {
