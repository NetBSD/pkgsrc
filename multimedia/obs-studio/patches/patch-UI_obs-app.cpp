$NetBSD: patch-UI_obs-app.cpp,v 1.1 2019/06/30 21:01:24 nia Exp $

Support NetBSD.

--- UI/obs-app.cpp.orig	2019-06-14 05:28:10.000000000 +0000
+++ UI/obs-app.cpp
@@ -1329,6 +1329,8 @@ string OBSApp::GetVersionString() const
 	ver << "mac)";
 #elif __FreeBSD__
 	ver << "freebsd)";
+#elif __NetBSD__
+	ver << "netbsd)";
 #else /* assume linux for the time being */
 	ver << "linux)";
 #endif
