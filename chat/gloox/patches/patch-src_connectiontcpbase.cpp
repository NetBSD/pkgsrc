$NetBSD: patch-src_connectiontcpbase.cpp,v 1.2 2014/05/06 08:41:38 wiz Exp $

--- src/connectiontcpbase.cpp.orig	2013-08-30 07:17:35.000000000 +0000
+++ src/connectiontcpbase.cpp
@@ -21,6 +21,8 @@
 #include "mutexguard.h"
 #include "util.h"
 
+#include <string.h>
+
 #ifdef __MINGW32__
 # include <winsock.h>
 #endif
