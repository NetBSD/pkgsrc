$NetBSD: patch-ntpd_refclock__oncore.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/refclock_oncore.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ ntpd/refclock_oncore.c
@@ -1804,7 +1804,7 @@ oncore_get_timestamp(
 		Rsm = ((instance->BEHa[129]<<8) | instance->BEHa[130]);
 
 	if (instance->chan == 6 || instance->chan == 8) {
-		char	f1[5], f2[5], f3[5], f4[5];
+		char	f1[6], f2[6], f3[6], f4[6];
 		if (instance->traim) {
 			snprintf(f1, sizeof(f1), "%d",
 				 instance->BEHn[21]);
@@ -1837,7 +1837,7 @@ oncore_get_timestamp(
 		    instance->BEHa[57], instance->BEHa[61], instance->BEHa[65], instance->BEHa[69]
 		    );					/* will be 0 for 6 chan */
 	} else if (instance->chan == 12) {
-		char	f1[5], f2[5], f3[5], f4[5];
+		char	f1[6], f2[6], f3[6], f4[6];
 		if (instance->traim) {
 			snprintf(f1, sizeof(f1), "%d",
 				 instance->BEHn[6]);
@@ -3429,9 +3429,10 @@ oncore_check_leap_sec(
 		instance->Bj_day = instance->BEHa[5];
 
 		if (instance->saw_Gj < 0) {	/* -1 DONT have Gj use Bj */
-			if ((instance->BEHa[4] == 6) || (instance->BEHa[4] == 12))
+			if ((instance->BEHa[4] == 6) || (instance->BEHa[4] == 12)) {
 				oncore_sendmsg(instance, oncore_cmd_Bj, sizeof(oncore_cmd_Bj));
 				oncore_sendmsg(instance, oncore_cmd_Bl, sizeof(oncore_cmd_Bl));
+			}
 			return;
 		}
 
@@ -3872,9 +3873,10 @@ oncore_set_traim(
 			oncore_sendmsg(instance, oncore_cmd_Bnx, sizeof(oncore_cmd_Bnx));
 		else if (instance->chan == 8)
 			oncore_sendmsg(instance, oncore_cmd_Enx, sizeof(oncore_cmd_Enx));
-		else	/* chan == 12 */
+		else {	/* chan == 12 */
 			oncore_sendmsg(instance, oncore_cmd_Ge0, sizeof(oncore_cmd_Ge0));
 			oncore_sendmsg(instance, oncore_cmd_Hn0, sizeof(oncore_cmd_Hn0));
+		}
 	}
 }
 
