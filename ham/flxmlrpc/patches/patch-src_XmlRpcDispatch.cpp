$NetBSD: patch-src_XmlRpcDispatch.cpp,v 1.2 2017/06/28 13:47:42 wiedi Exp $

add include for memset

--- src/XmlRpcDispatch.cpp.orig	2015-04-19 13:32:14.000000000 +0000
+++ src/XmlRpcDispatch.cpp
@@ -32,6 +32,8 @@
 #	include <sys/timeb.h>
 #endif // __FreeBSD__
 
+#include <string.h>
+
 #if defined(_WINDOWS)
 # include <winsock2.h>
 
