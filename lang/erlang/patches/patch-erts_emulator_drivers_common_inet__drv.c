$NetBSD: patch-erts_emulator_drivers_common_inet__drv.c,v 1.2 2015/12/29 23:34:46 dholland Exp $

Unbreak build due to differences in the NetBSD SCTP implementation.

--- erts/emulator/drivers/common/inet_drv.c.orig	2015-11-17 11:35:14.000000000 +0000
+++ erts/emulator/drivers/common/inet_drv.c
@@ -567,6 +567,12 @@ typedef unsigned long  u_long;
 #     define sctp_adaptation_layer_event sctp_adaption_layer_event
 #endif
 
+#ifdef __NetBSD__
+#undef SCTP_DELAYED_ACK_TIME
+#undef HAVE_DECL_SCTP_DELAYED_ACK_TIME
+#define HAVE_DECL_SCTP_DELAYED_ACK_TIME 0
+#endif
+
 #if defined(__GNUC__) && defined(HAVE_SCTP_BINDX)
 static typeof(sctp_bindx) *p_sctp_bindx = NULL;
 #else
