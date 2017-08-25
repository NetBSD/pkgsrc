$NetBSD: patch-src_Plugins_Qt_QTMSockets.cpp,v 1.1 2017/08/25 20:03:03 joerg Exp $

--- src/Plugins/Qt/QTMSockets.cpp.orig	2017-07-24 13:33:10.562028054 +0000
+++ src/Plugins/Qt/QTMSockets.cpp
@@ -19,6 +19,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 #include <netdb.h>
 #include <stdint.h>
