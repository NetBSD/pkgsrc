$NetBSD: patch-src_machines_machine__pmax.cc,v 1.2 2018/03/21 17:39:42 kamil Exp $

sd0 -> rz0 so we can find our boot device.

Fix C++11 literals.

--- src/machines/machine_pmax.cc.orig	2014-08-17 08:45:14.000000000 +0000
+++ src/machines/machine_pmax.cc
@@ -660,7 +660,7 @@ abort();
 
 		/*  KN230 mainbus / interrupt controller:  */
 		snprintf(tmpstr, sizeof(tmpstr),
-		    "kn230 addr=0x%"PRIx64, (uint64_t) KN230_SYS_ICSR);
+		    "kn230 addr=0x%" PRIx64, (uint64_t) KN230_SYS_ICSR);
 		device_add(machine, tmpstr);
 
 		/*
@@ -789,7 +789,7 @@ abort();
 			strlcpy(bootpath, "rz(0,0,0)", sizeof(bootpath));
 		else
 #endif
-			strlcpy(bootpath, "5/rz1/", sizeof(bootpath));
+			strlcpy(bootpath, "5/rz0/", sizeof(bootpath));
 
 		if (machine->bootdev_id < 0 || machine->force_netboot) {
 			/*  tftp boot:  */
@@ -885,7 +885,7 @@ abort();
 	 */
 	{
 		char tmps[300];
-		snprintf(tmps, sizeof(tmps), "cca=%"PRIx32,
+		snprintf(tmps, sizeof(tmps), "cca=%" PRIx32,
 		    (uint32_t) (DEC_DECCCA_BASEADDR + 0xa0000000ULL));
 		add_environment_string(cpu, tmps, &addr);
 	}
@@ -898,14 +898,14 @@ abort();
 		tmps[sizeof(tmps)-1] = '\0';
 		add_environment_string(cpu, tmps, &addr);
 
-		snprintf(tmps, sizeof(tmps), "bitmap=0x%"PRIx32, (uint32_t)
+		snprintf(tmps, sizeof(tmps), "bitmap=0x%" PRIx32, (uint32_t)
 		    ( (DEC_MEMMAP_ADDR + sizeof(uint32_t) /* skip the
 			page size and point to the memmap */
 		    ) & 0xffffffffULL) );
 		tmps[sizeof(tmps)-1] = '\0';
 		add_environment_string(cpu, tmps, &addr);
 
-		snprintf(tmps, sizeof(tmps), "bitmaplen=0x%"PRIx32, (uint32_t)
+		snprintf(tmps, sizeof(tmps), "bitmaplen=0x%" PRIx32, (uint32_t)
 		    ( machine->physical_ram_in_mb * 1048576 / 4096 / 8) );
 		tmps[sizeof(tmps)-1] = '\0';
 		add_environment_string(cpu, tmps, &addr);
@@ -994,4 +994,3 @@ MACHINE_REGISTER(pmax)
 
 	me->set_default_ram = machine_default_ram_pmax;
 }
-
