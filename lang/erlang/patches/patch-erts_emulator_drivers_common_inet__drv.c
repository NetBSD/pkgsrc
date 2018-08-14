$NetBSD: patch-erts_emulator_drivers_common_inet__drv.c,v 1.3 2018/08/14 18:40:42 nia Exp $

Unbreak build due to differences in the NetBSD SCTP implementation.

--- erts/emulator/drivers/common/inet_drv.c.orig	2018-06-19 07:07:55.000000000 +0000
+++ erts/emulator/drivers/common/inet_drv.c
@@ -1551,6 +1551,12 @@ static void *realloc_wrapper(void *curre
 #   define SCTP_ANC_BUFF_SIZE   INET_DEF_BUFFER/2 /* XXX: not very good... */
 #endif
 
+#ifdef __NetBSD__
+#undef SCTP_DELAYED_ACK_TIME
+#undef HAVE_DECL_SCTP_DELAYED_ACK_TIME
+#define HAVE_DECL_SCTP_DELAYED_ACK_TIME 0
+#endif
+
 #ifdef HAVE_UDP
 static int load_address(ErlDrvTermData* spec, int i, char* buf)
 {
