$NetBSD: patch-lib_server_CServer.cpp,v 1.1 2011/11/22 20:07:20 joerg Exp $

--- lib/server/CServer.cpp.orig	2011-11-22 19:39:54.000000000 +0000
+++ lib/server/CServer.cpp
@@ -28,6 +28,7 @@
 #include "CLog.h"
 #include "TMethodEventJob.h"
 #include "CArch.h"
+#include <stdlib.h>
 #include <string.h>
 
 //
