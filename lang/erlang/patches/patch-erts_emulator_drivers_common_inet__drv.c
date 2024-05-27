$NetBSD: patch-erts_emulator_drivers_common_inet__drv.c,v 1.6 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

Unbreak build due to differences in the NetBSD SCTP implementation.

--- erts/emulator/drivers/common/inet_drv.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ erts/emulator/drivers/common/inet_drv.c
@@ -591,9 +591,9 @@ static int my_strncasecmp(const char *s1
 {
     int i;
 
-    for (i=0;i<n-1 && s1[i] && s2[i] && toupper(s1[i]) == toupper(s2[i]);++i)
+    for (i=0;i<n-1 && s1[i] && s2[i] && toupper((unsigned char)s1[i]) == toupper((unsigned char)s2[i]);++i)
 	;
-    return (toupper(s1[i]) - toupper(s2[i]));
+    return (toupper((unsigned char)s1[i]) - toupper((unsigned char)s2[i]));
 }
 	
 
@@ -1331,7 +1331,11 @@ static struct erl_drv_entry tcp_inet_dri
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
