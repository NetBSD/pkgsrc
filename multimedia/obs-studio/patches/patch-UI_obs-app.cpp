$NetBSD: patch-UI_obs-app.cpp,v 1.2 2021/01/12 16:17:47 ryoon Exp $

Support NetBSD.

--- UI/obs-app.cpp.orig	2021-01-04 15:02:53.000000000 +0000
+++ UI/obs-app.cpp
@@ -1448,6 +1448,8 @@ string OBSApp::GetVersionString() const
 	ver << "openbsd)";
 #elif __FreeBSD__
 	ver << "freebsd)";
+#elif __NetBSD__
+	ver << "netbsd)";
 #else /* assume linux for the time being */
 	ver << "linux)";
 #endif
