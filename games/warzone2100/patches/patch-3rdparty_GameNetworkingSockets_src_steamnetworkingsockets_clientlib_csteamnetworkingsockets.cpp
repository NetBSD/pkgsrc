$NetBSD: patch-3rdparty_GameNetworkingSockets_src_steamnetworkingsockets_clientlib_csteamnetworkingsockets.cpp,v 1.1 2025/10/12 09:06:19 triaxx Exp $

Add support for NetBSD.

--- 3rdparty/GameNetworkingSockets/src/steamnetworkingsockets/clientlib/csteamnetworkingsockets.cpp.orig	2025-09-16 16:42:25.000000000 +0000
+++ 3rdparty/GameNetworkingSockets/src/steamnetworkingsockets/clientlib/csteamnetworkingsockets.cpp
@@ -2444,6 +2444,8 @@ const char *CSteamNetworkingUtils::GetPl
 		return "linux";
 	#elif defined( FREEBSD ) || defined( __FreeBSD__ )
 		return "freebsd";
+	#elif defined( NETBSD ) || defined( __NetBSD__ )
+		return "netbsd";
 	#else
 		#error "Unknown platform"
 	#endif
