$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_system__wrappers_source_spreadsortlib_spreadsort.hpp,v 1.4 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp.orig	2016-04-07 21:33:24.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp
@@ -14,6 +14,13 @@ Cygwin fix provided by:
 Scott McMurray
 */
 
+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version < 900506
+#  define getchar boost_getchar
+# endif
+#endif
+
 #ifndef BOOST_SPREAD_SORT_H
 #define BOOST_SPREAD_SORT_H
 #include <algorithm>
@@ -21,10 +28,24 @@ Scott McMurray
 #include <vector>
 #include "webrtc/system_wrappers/source/spreadsortlib/constants.hpp"
 
+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version < 900506
+#  define getchar boost_getchar
+# endif
+#endif
+
 #ifdef getchar
 #undef getchar
 #endif
 
+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version < 900506
+#  define getchar boost_getchar
+# endif
+#endif
+
 namespace boost {
   namespace detail {
   	//This only works on unsigned data types
