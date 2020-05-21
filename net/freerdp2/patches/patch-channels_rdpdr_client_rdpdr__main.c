$NetBSD: patch-channels_rdpdr_client_rdpdr__main.c,v 1.1 2020/05/21 10:11:23 nia Exp $

NetBSD does not have mntent

--- channels/rdpdr/client/rdpdr_main.c.orig	2020-05-08 09:40:17.000000000 +0000
+++ channels/rdpdr/client/rdpdr_main.c
@@ -111,7 +111,7 @@ static UINT rdpdr_send_device_list_remov
 	return rdpdr_send(rdpdr, s);
 }
 
-#if defined(_UWP) || defined(__IOS__)
+#if defined(_UWP) || defined(__IOS__) || defined(__NetBSD__)
 
 void first_hotplug(rdpdrPlugin* rdpdr)
 {
@@ -844,7 +844,7 @@ out:
 
 #endif
 
-#if !defined(_WIN32) && !defined(__IOS__)
+#if !defined(_WIN32) && !defined(__IOS__) && !defined(__NetBSD__)
 /**
  * Function description
  *
