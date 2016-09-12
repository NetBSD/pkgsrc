$NetBSD: patch-gst_udp_gstudpsrc.c,v 1.1 2016/09/12 09:00:10 wiz Exp $

--- gst/udp/gstudpsrc.c.orig	2016-07-11 06:19:14.000000000 +0000
+++ gst/udp/gstudpsrc.c
@@ -202,8 +202,10 @@ gst_ip_pktinfo_message_deserialize (gint
   message = g_object_new (GST_TYPE_IP_PKTINFO_MESSAGE, NULL);
   message->ifindex = pktinfo->ipi_ifindex;
 #ifndef G_OS_WIN32
+#ifndef __NetBSD__
   message->spec_dst = pktinfo->ipi_spec_dst;
 #endif
+#endif
   message->addr = pktinfo->ipi_addr;
 
   return G_SOCKET_CONTROL_MESSAGE (message);
