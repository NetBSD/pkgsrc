$NetBSD: patch-src_connectiontcpbase.cpp,v 1.1 2012/02/16 13:57:16 hans Exp $

--- src/connectiontcpbase.cpp.orig	2009-10-26 00:05:39.000000000 +0100
+++ src/connectiontcpbase.cpp	2012-01-20 11:51:07.167505326 +0100
@@ -20,6 +20,8 @@
 #include "prep.h"
 #include "mutexguard.h"
 
+#include <string.h>
+
 #ifdef __MINGW32__
 # include <winsock.h>
 #endif
