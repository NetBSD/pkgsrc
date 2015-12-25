$NetBSD: patch-src_in__sysctl.c,v 1.1 2015/12/25 20:08:38 joerg Exp $

--- src/in_sysctl.c.orig	2015-07-25 08:45:17.000000000 +0000
+++ src/in_sysctl.c
@@ -226,17 +226,19 @@ sysctl_read(void)
 			attr_update(e, m->attrid, rx, tx, flags);
 		}
 
-		snprintf(info_buf, sizeof(info_buf), "%u", ifm->ifm_data.ifi_mtu);
+		snprintf(info_buf, sizeof(info_buf), "%ju", (uintmax_t)ifm->ifm_data.ifi_mtu);
 		element_update_info(e, "MTU", info_buf);
 
-		snprintf(info_buf, sizeof(info_buf), "%u", ifm->ifm_data.ifi_metric);
+		snprintf(info_buf, sizeof(info_buf), "%ju", (uintmax_t)ifm->ifm_data.ifi_metric);
 		element_update_info(e, "Metric", info_buf);
 
+#ifndef __NetBSD__
 		snprintf(info_buf, sizeof(info_buf), "%u", ifm->ifm_data.ifi_recvquota);
 		element_update_info(e, "RX-Quota", info_buf);
 
 		snprintf(info_buf, sizeof(info_buf), "%u", ifm->ifm_data.ifi_xmitquota);
 		element_update_info(e, "TX-Quota", info_buf);
+#endif
 
 		element_notify_update(e, NULL);
 		element_lifesign(e, 1);
