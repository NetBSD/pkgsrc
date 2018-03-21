$NetBSD: patch-src_machines_machine__landisk.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/machines/machine_landisk.cc.orig	2014-08-17 08:45:14.000000000 +0000
+++ src/machines/machine_landisk.cc
@@ -90,7 +90,7 @@ MACHINE_SETUP(landisk)
 	device_add(machine, tmpstr);
 
 	/*  rsclock0 at shb0: RS5C313 real time clock  */
-	snprintf(tmpstr, sizeof(tmpstr), "rs5c313 addr=0x%"PRIx64,
+	snprintf(tmpstr, sizeof(tmpstr), "rs5c313 addr=0x%" PRIx64,
 	    (uint64_t) SCI_DEVICE_BASE);
 	device_add(machine, tmpstr);
 
@@ -142,4 +142,3 @@ MACHINE_REGISTER(landisk)
 	machine_entry_add_alias(me, "landisk");
 	machine_entry_add_alias(me, "usl-5p");
 }
-
