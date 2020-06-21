$NetBSD: patch-ntpd_refclock__jupiter.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/refclock_jupiter.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ ntpd/refclock_jupiter.c
@@ -186,8 +186,8 @@ jupiter_start(
 	snprintf(gpsdev, sizeof(gpsdev), DEVICE, unit);
 	fd = refclock_open(gpsdev, SPEED232, LDISC_RAW);
 	if (fd <= 0) {
-		jupiter_debug(peer, "jupiter_start", "open %s: %m",
-			      gpsdev);
+		jupiter_debug(peer, "jupiter_start", "open %s: %s",
+			      gpsdev, strerror(errno));
 		return (0);
 	}
 
