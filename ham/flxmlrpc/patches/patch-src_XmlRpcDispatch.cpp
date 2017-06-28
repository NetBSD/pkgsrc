$NetBSD: patch-src_XmlRpcDispatch.cpp,v 1.1 2017/06/28 11:07:21 wiedi Exp $

add include on SunOS for memset

--- src/XmlRpcDispatch.cpp.orig	2015-04-19 13:32:14.000000000 +0000
+++ src/XmlRpcDispatch.cpp
@@ -32,6 +32,10 @@
 #	include <sys/timeb.h>
 #endif // __FreeBSD__
 
+#if defined(__sun)
+#include <string.h>
+#endif
+
 #if defined(_WINDOWS)
 # include <winsock2.h>
 
