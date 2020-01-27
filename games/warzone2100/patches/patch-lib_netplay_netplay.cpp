$NetBSD: patch-lib_netplay_netplay.cpp,v 1.2 2020/01/27 19:35:54 triaxx Exp $

--- lib/netplay/netplay.cpp.orig	2019-08-31 18:17:22.000000000 +0000
+++ lib/netplay/netplay.cpp
@@ -1801,7 +1801,7 @@ static void NETcheckPlayers()
 // We should not block here.
 bool NETrecvNet(NETQUEUE *queue, uint8_t *type)
 {
-	const int status = upnp_status; // hack fix for clang and c++11 - fixed in standard for c++14
+	const int status = upnp_status.load(); // hack fix for clang and c++11 - fixed in standard for c++14
 	switch (status)
 	{
 	case UPNP_ERROR_CONTROL_NOT_AVAILABLE:
