$NetBSD: patch-src_UPnPBase.h,v 1.1 2020/11/19 20:01:41 nia Exp $

Fix build with upnp 1.8.x.

From FreeBSD Ports.

--- src/UPnPBase.h.orig	2016-09-16 07:55:07.000000000 +0000
+++ src/UPnPBase.h
@@ -489,9 +489,15 @@ public:
 
 	// Callback function
 	static int Callback(
+#if UPNP_VERSION >= 10800
+		Upnp_EventType_e EventType,
+		const void *Event,
+		void *Cookie);
+#else
 		Upnp_EventType EventType,
 		void* Event,
 		void* Cookie);
+#endif
 
 private:
 	void OnEventReceived(
