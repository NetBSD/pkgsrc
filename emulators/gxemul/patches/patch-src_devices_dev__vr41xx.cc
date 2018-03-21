$NetBSD: patch-src_devices_dev__vr41xx.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/devices/dev_vr41xx.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/dev_vr41xx.cc
@@ -466,7 +466,7 @@ static uint64_t vr41xx_kiu(struct cpu *c
 	default:
 		if (writeflag == MEM_WRITE)
 			debug("[ vr41xx KIU: unimplemented write to offset "
-			    "0x%x, data=0x%016"PRIx64" ]\n", ofs,
+			    "0x%x, data=0x%016" PRIx64 " ]\n", ofs,
 			    (uint64_t) idata);
 		else
 			debug("[ vr41xx KIU: unimplemented read from offset "
@@ -638,11 +638,11 @@ DEVICE_ACCESS(vr41xx)
 	default:
 		if (writeflag == MEM_WRITE)
 			debug("[ vr41xx: unimplemented write to address "
-			    "0x%"PRIx64", data=0x%016"PRIx64" ]\n",
+			    "0x%" PRIx64 ", data=0x%016" PRIx64 " ]\n",
 			    (uint64_t) relative_addr, (uint64_t) idata);
 		else
 			debug("[ vr41xx: unimplemented read from address "
-			    "0x%"PRIx64" ]\n", (uint64_t) relative_addr);
+			    "0x%" PRIx64 " ]\n", (uint64_t) relative_addr);
 	}
 
 ret:
@@ -776,7 +776,7 @@ struct vr41xx_data *dev_vr41xx_init(stru
 	 */
 	if (cpumodel == 4131) {
 		snprintf(tmps, sizeof(tmps), "ns16550 irq=%s.cpu[%i].vrip.%i "
-		    "addr=0x%"PRIx64" name2=siu", machine->path,
+		    "addr=0x%" PRIx64 " name2=siu", machine->path,
 		    machine->bootstrap_cpu, VRIP_INTR_SIU,
 		    (uint64_t) (baseaddr+0x800));
 		device_add(machine, tmps);
@@ -804,4 +804,3 @@ struct vr41xx_data *dev_vr41xx_init(stru
 
 	return d;
 }
-
