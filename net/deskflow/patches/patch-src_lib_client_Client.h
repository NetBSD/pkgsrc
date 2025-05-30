$NetBSD: patch-src_lib_client_Client.h,v 1.1 2025/05/30 21:17:32 tnn Exp $

- include climits for INT_MAX

--- src/lib/client/Client.h.orig	2025-05-30 20:27:53.151932859 +0000
+++ src/lib/client/Client.h
@@ -17,6 +17,7 @@
 #include "mt/CondVar.h"
 #include "net/NetworkAddress.h"
 
+#include <climits>
 #include <memory>
 
 class EventQueueTimer;
