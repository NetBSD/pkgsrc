$NetBSD: patch-src_lib_server_Server.h,v 1.1 2025/05/30 21:17:32 tnn Exp $

- include climits for INT_MAX

--- src/lib/server/Server.h.orig	2025-05-30 20:26:27.763507219 +0000
+++ src/lib/server/Server.h
@@ -19,6 +19,7 @@
 #include "deskflow/ServerArgs.h"
 #include "server/Config.h"
 
+#include <climits>
 #include <map>
 #include <memory>
 #include <set>
