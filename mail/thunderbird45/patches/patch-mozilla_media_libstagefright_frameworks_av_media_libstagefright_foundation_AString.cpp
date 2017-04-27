$NetBSD: patch-mozilla_media_libstagefright_frameworks_av_media_libstagefright_foundation_AString.cpp,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp.orig	2016-04-07 21:33:21.000000000 +0000
+++ mozilla/media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp
@@ -23,6 +23,17 @@
 #include "ADebug.h"
 #include "AString.h"
 
+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version < 900506
+#  undef tolower
+# endif
+#endif
+
+#if defined(__NetBSD__) && defined(tolower)
+#undef tolower
+#endif
+
 namespace stagefright {
 
 // static
