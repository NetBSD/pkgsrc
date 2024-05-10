$NetBSD: patch-src_dynamic-preprocessors_appid_service__plugins_service__rpc.c,v 1.2 2024/05/10 19:49:13 jperkin Exp $

endrpcent() is defined in /usr/include/rpc/rpcent.h in NetBSD.

--- src/dynamic-preprocessors/appid/service_plugins/service_rpc.c.orig	2020-07-10 11:28:23.000000000 +0000
+++ src/dynamic-preprocessors/appid/service_plugins/service_rpc.c
@@ -36,6 +36,10 @@
 #include "rpc/rpc.h"
 #endif
 
+#if defined(__NetBSD__) || defined(__sun)
+#include "rpc/rpcent.h"
+#endif
+
 /*#define RNA_DEBUG_RPC   1 */
 
 typedef enum
