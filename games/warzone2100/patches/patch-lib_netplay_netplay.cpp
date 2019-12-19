$NetBSD: patch-lib_netplay_netplay.cpp,v 1.1 2019/12/19 22:16:05 joerg Exp $

--- lib/netplay/netplay.cpp.orig	2019-12-19 16:30:29.430922431 +0000
+++ lib/netplay/netplay.cpp
@@ -1783,7 +1783,7 @@ static void NETcheckPlayers(void)
 // We should not block here.
 bool NETrecvNet(NETQUEUE *queue, uint8_t *type)
 {
-	switch (upnp_status)
+	switch (upnp_status.load())
 	{
 	case UPNP_ERROR_CONTROL_NOT_AVAILABLE:
 	case UPNP_ERROR_DEVICE_NOT_FOUND:
