$NetBSD: patch-lib_client_CClient.cpp,v 1.1 2011/11/22 20:07:20 joerg Exp $

--- lib/client/CClient.cpp.orig	2011-11-22 19:38:57.000000000 +0000
+++ lib/client/CClient.cpp
@@ -26,6 +26,8 @@
 #include "CLog.h"
 #include "IEventQueue.h"
 #include "TMethodEventJob.h"
+#include <stdlib.h>
+#include <string.h>
 
 //
 // CClient
