$NetBSD: patch-src_dynamic-preprocessors_appid_service__plugins_service__rpc.c,v 1.1 2020/10/01 19:45:02 nils Exp $

endrpcent() is defined in /usr/include/rpc/rpcent.h in NetBSD.

--- src/dynamic-preprocessors/appid/service_plugins/service_rpc.c.orig	2020-07-10 11:28:23.000000000 +0000
+++ src/dynamic-preprocessors/appid/service_plugins/service_rpc.c
@@ -36,6 +36,10 @@
 #include "rpc/rpc.h"
 #endif
 
+#if defined(__NetBSD__)
+#include "rpc/rpcent.h"
+#endif
+
 /*#define RNA_DEBUG_RPC   1 */
 
 typedef enum
