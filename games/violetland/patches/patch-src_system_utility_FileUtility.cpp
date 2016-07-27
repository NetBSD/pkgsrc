$NetBSD: patch-src_system_utility_FileUtility.cpp,v 1.1 2016/07/27 21:14:36 kamil Exp $

Add NetBSD support.

--- src/system/utility/FileUtility.cpp.orig	2016-07-27 09:04:07.000000000 +0000
+++ src/system/utility/FileUtility.cpp
@@ -66,7 +66,7 @@ FileUtility::FileUtility(char *argPath) 
 	m_resPath = m_appPath;
 	m_usrPath = m_resPath;
 #endif //_WIN32
-#if defined linux || defined __FreeBSD__ || defined __OpenBSD__
+#if defined linux || defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
 #ifndef INSTALL_PREFIX
 #define INSTALL_PREFIX "/usr/local";
 #endif //INSTALL_PREFIX
@@ -83,7 +83,7 @@ FileUtility::FileUtility(char *argPath) 
 	mkdir(m_usrPath.string().c_str(), S_IRWXU | S_IRGRP | S_IROTH);
 	m_usrPath /= "violetland";
 	mkdir(m_usrPath.string().c_str(), S_IRWXU | S_IRGRP | S_IROTH);
-#endif //linux || __FreeBSD__
+#endif //linux || __FreeBSD__ || __NetBSD__
 	traceResPath();
 }
 
