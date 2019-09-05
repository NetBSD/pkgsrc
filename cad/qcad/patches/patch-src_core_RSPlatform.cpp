$NetBSD: patch-src_core_RSPlatform.cpp,v 1.2 2019/09/05 13:39:10 nia Exp $

enhance getSystemId for some common platforms

--- src/core/RSPlatform.cpp.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/core/RSPlatform.cpp
@@ -43,7 +43,7 @@
 QString RS::getHostId() {
     return QString("%1_%2")
             .arg(getSystemId())
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD) || defined(Q_OS_FREEBSD) || defined(Q_OS_SOLARIS)
     .arg(getenv("HOSTNAME"));
 #elif defined(Q_OS_MAC)
     // environment variable HOSTNAME not exported on OS X by default:
@@ -56,7 +56,7 @@ QString RS::getHostId() {
 }
 
 /**
- * \return Unique system ID ("linux", "osx", "win").
+ * \return Unique system ID ("linux", "osx", "win", "netbsd", "freebsd", "solaris").
  */
 QString RS::getSystemId() {
 #if defined(Q_OS_LINUX)
@@ -65,6 +65,12 @@ QString RS::getSystemId() {
     return "osx";
 #elif defined(Q_OS_WIN)
     return "win";
+#elif defined(Q_OS_NETBSD)
+    return "netbsd";
+#elif defined(Q_OS_FREEBSD)
+    return "freebsd";
+#elif defined(Q_OS_SOLARIS)
+    return "solaris";
 #else
     return "unknown";
 #endif
