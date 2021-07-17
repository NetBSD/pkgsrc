$NetBSD: patch-src_knock__helper__ipt.sh,v 1.1 2021/07/17 16:01:34 adam Exp $

Portablility fix.

--- src/knock_helper_ipt.sh.orig	2021-07-17 15:59:26.000000000 +0000
+++ src/knock_helper_ipt.sh
@@ -167,7 +167,7 @@ do
 		echo "$SCRIPT_NAME - $IP"
 	fi
 
-	if [ "$IPT_SRC_IP" == "$IP" ]; then
+	if [ "$IPT_SRC_IP" = "$IP" ]; then
 		SEEN=1
 	fi
 done
@@ -186,4 +186,4 @@ if [ "$SEEN" -eq 0 ]; then
 	if [ "$DRY_RUN" -eq 0 ]; then
 		eval $IPTABLES $IPT_METHOD $IPT_CHAIN -s $IPT_SRC_IP -p $IPT_PROTO --dport $IPT_DST_PORT -j $IPT_RULE_TARGET $COMMENT
 	fi
-fi
\ No newline at end of file
+fi
