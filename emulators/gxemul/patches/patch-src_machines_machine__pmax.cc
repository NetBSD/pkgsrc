$NetBSD: patch-src_machines_machine__pmax.cc,v 1.3 2019/01/04 13:35:17 ryoon Exp $

sd0 -> rz0 so we can find our boot device.

--- src/machines/machine_pmax.cc.orig	2018-12-07 06:29:22.000000000 +0000
+++ src/machines/machine_pmax.cc
@@ -804,7 +804,7 @@ abort();
 			strlcpy(bootpath, "rz(0,0,0)", sizeof(bootpath));
 		else
 #endif
-			strlcpy(bootpath, "5/rz1/", sizeof(bootpath));
+			strlcpy(bootpath, "5/rz0/", sizeof(bootpath));
 
 		if (machine->bootdev_id < 0 || machine->force_netboot) {
 			/*  tftp boot:  */
