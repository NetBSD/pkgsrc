$NetBSD: patch-3rdparty_GameNetworkingSockets_src_steamnetworkingsockets_clientlib_steamnetworkingsockets__lowlevel.cpp,v 1.1 2025/10/12 09:06:19 triaxx Exp $

NetBSD does not implement AI_V4MAPPED in netbsd.h.

--- 3rdparty/GameNetworkingSockets/src/steamnetworkingsockets/clientlib/steamnetworkingsockets_lowlevel.cpp.orig	2025-10-12 04:45:00.662361482 +0000
+++ 3rdparty/GameNetworkingSockets/src/steamnetworkingsockets/clientlib/steamnetworkingsockets_lowlevel.cpp
@@ -4204,7 +4204,11 @@ bool ResolveHostname( const char* pszHos
 
 	addrinfo hints;
 	V_memset( &hints, 0, sizeof( hints ) );
+#ifdef AI_V4MAPPED
 	hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;
+#else
+	hints.ai_flags = AI_ADDRCONFIG;
+#endif
 	hints.ai_family = AF_UNSPEC;
 	hints.ai_socktype = 0;
 	hints.ai_protocol = 0;
