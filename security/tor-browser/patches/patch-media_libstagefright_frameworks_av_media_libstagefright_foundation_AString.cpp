$NetBSD: patch-media_libstagefright_frameworks_av_media_libstagefright_foundation_AString.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp.orig	2015-02-23 07:39:35.000000000 +0000
+++ media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp
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
