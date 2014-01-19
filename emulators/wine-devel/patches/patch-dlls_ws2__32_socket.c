$NetBSD: patch-dlls_ws2__32_socket.c,v 1.1 2014/01/19 10:58:23 adam Exp $

Fix AI_V4MAPPED confusion on NetBSD.

--- dlls/ws2_32/socket.c.orig	2014-01-03 19:00:47.000000000 +0000
+++ dlls/ws2_32/socket.c
@@ -173,6 +173,10 @@
 #define INADDR_NONE ~0UL
 #endif
 
+#ifdef USE_WS_PREFIX
+#define AI_V4MAPPED WS_AI_V4MAPPED
+#endif
+
 WINE_DEFAULT_DEBUG_CHANNEL(winsock);
 WINE_DECLARE_DEBUG_CHANNEL(winediag);
 
