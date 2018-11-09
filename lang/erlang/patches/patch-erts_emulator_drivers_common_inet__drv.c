$NetBSD: patch-erts_emulator_drivers_common_inet__drv.c,v 1.4 2018/11/09 17:16:01 nia Exp $

Unbreak build due to differences in the NetBSD SCTP implementation.

--- erts/emulator/drivers/common/inet_drv.c.orig	2018-09-24 10:32:43.000000000 +0100
+++ erts/emulator/drivers/common/inet_drv.c	2018-11-09 09:34:01.671317341 +0000
@@ -1182,7 +1182,11 @@
     inet_emergency_close
 };
 
-
+#ifdef __NetBSD__
+#undef SCTP_DELAYED_ACK_TIME
+#undef HAVE_DECL_SCTP_DELAYED_ACK_TIME
+#define HAVE_DECL_SCTP_DELAYED_ACK_TIME 0
+#endif
 
 #ifdef HAVE_UDP
 static int        packet_inet_init(void);
