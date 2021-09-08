$NetBSD: patch-common_JackAudioAdapterFactory.cpp,v 1.1 2021/09/08 19:19:20 nia Exp $

Add NetBSD support.

--- common/JackAudioAdapterFactory.cpp.orig	2021-07-15 06:18:26.000000000 +0000
+++ common/JackAudioAdapterFactory.cpp
@@ -35,6 +35,11 @@ Foundation, Inc., 675 Mass Ave, Cambridg
 #define JackPlatformAdapter JackAlsaAdapter
 #endif
 
+#ifdef __NetBSD__
+#include "JackSunAdapter.h"
+#define JackPlatformAdapter JackSunAdapter
+#endif
+
 #if defined(__sun__) || defined(sun)
 #include "JackOSSAdapter.h"
 #define JackPlatformAdapter JackOSSAdapter
