$NetBSD: patch-src_machines_machine__pmax.cc,v 1.1 2017/06/29 17:51:46 christos Exp $

sd0 -> rz0 so we can find our boot device.

--- src/machines/machine_pmax.cc.orig	2017-06-29 13:46:24.964078725 -0400
+++ src/machines/machine_pmax.cc	2017-06-29 13:46:39.643612752 -0400
@@ -789,7 +789,7 @@
 			strlcpy(bootpath, "rz(0,0,0)", sizeof(bootpath));
 		else
 #endif
-			strlcpy(bootpath, "5/rz1/", sizeof(bootpath));
+			strlcpy(bootpath, "5/rz0/", sizeof(bootpath));
 
 		if (machine->bootdev_id < 0 || machine->force_netboot) {
 			/*  tftp boot:  */
