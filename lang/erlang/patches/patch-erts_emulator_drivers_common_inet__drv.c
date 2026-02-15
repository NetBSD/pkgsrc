$NetBSD: patch-erts_emulator_drivers_common_inet__drv.c,v 1.7 2026/02/15 18:14:31 gdt Exp $

Fix ctype(3) misuse.

Unbreak build due to differences in the NetBSD SCTP implementation.

--- erts/emulator/drivers/common/inet_drv.c.orig	2026-02-04 14:57:36.000000000 +0000
+++ erts/emulator/drivers/common/inet_drv.c
@@ -606,9 +606,9 @@ static int my_strncasecmp(const char *s1
 {
     int i;
 
-    for (i=0;i<n-1 && s1[i] && s2[i] && toupper(s1[i]) == toupper(s2[i]);++i)
+    for (i=0;i<n-1 && s1[i] && s2[i] && toupper((unsigned char)s1[i]) == toupper((unsigned char)s2[i]);++i)
 	;
-    return (toupper(s1[i]) - toupper(s2[i]));
+    return (toupper((unsigned char)s1[i]) - toupper((unsigned char)s2[i]));
 }
 	
 
@@ -1362,6 +1362,11 @@ static struct erl_drv_entry tcp_inet_dri
 };
 
 
+#ifdef __NetBSD__
+#undef SCTP_DELAYED_ACK_TIME
+#undef HAVE_DECL_SCTP_DELAYED_ACK_TIME
+#define HAVE_DECL_SCTP_DELAYED_ACK_TIME 0
+#endif
 
 #ifdef HAVE_UDP
 
