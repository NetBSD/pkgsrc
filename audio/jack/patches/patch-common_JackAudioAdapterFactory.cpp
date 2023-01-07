$NetBSD: patch-common_JackAudioAdapterFactory.cpp,v 1.2 2023/01/07 21:20:19 triaxx Exp $

Add NetBSD support.

--- common/JackAudioAdapterFactory.cpp.orig	2022-04-15 19:14:06.000000000 +0000
+++ common/JackAudioAdapterFactory.cpp
@@ -35,6 +35,11 @@ Foundation, Inc., 675 Mass Ave, Cambridg
 #define JackPlatformAdapter JackAlsaAdapter
 #endif
 
+#ifdef __NetBSD__
+#include "JackSunAdapter.h"
+#define JackPlatformAdapter JackSunAdapter
+#endif
+
 #if defined(__sun__) || defined(sun) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include "JackOSSAdapter.h"
 #define JackPlatformAdapter JackOSSAdapter
