$NetBSD: patch-src_promemul_arcbios.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/promemul/arcbios.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/promemul/arcbios.cc
@@ -696,7 +696,7 @@ static uint64_t arcbios_addchild64(struc
 		uint64_t eparent, echild, epeer, tmp;
 		unsigned char buf[8];
 
-		/*  debug("[ addchild: peeraddr = 0x%016"PRIx64" ]\n",
+		/*  debug("[ addchild: peeraddr = 0x%016" PRIx64 " ]\n",
 		    (uint64_t) peeraddr);  */
 
 		cpu->memory_rw(cpu, cpu->mem,
@@ -741,7 +741,7 @@ static uint64_t arcbios_addchild64(struc
 		    + ((uint64_t)buf[4] << 32) + ((uint64_t)buf[5] << 40)
 		    + ((uint64_t)buf[6] << 48) + ((uint64_t)buf[7] << 56);
 
-		/*  debug("  epeer=%"PRIx64" echild=%"PRIx64" eparent=%"PRIx64
+		/*  debug("  epeer=%" PRIx64 " echild=%" PRIx64 " eparent=%" PRIx64
 		    "\n", (uint64_t) epeer, (uint64_t) echild,
 		    (uint64_t) eparent);  */
 
@@ -749,16 +749,16 @@ static uint64_t arcbios_addchild64(struc
 			epeer = a;
 			store_64bit_word(cpu, peeraddr + 0 *
 			    machine->md.arc->wordlen, epeer);
-			/*  debug("[ addchild: adding 0x%016"PRIx64" as peer "
-			    "to 0x%016"PRIx64" ]\n", (uint64_t) a,
+			/*  debug("[ addchild: adding 0x%016" PRIx64 " as peer "
+			    "to 0x%016" PRIx64 " ]\n", (uint64_t) a,
 			    (uint64_t) peeraddr);  */
 		}
 		if (peeraddr == parent && echild == 0) {
 			echild = a;
 			store_64bit_word(cpu, peeraddr + 1 *
 			    machine->md.arc->wordlen, echild);
-			/*  debug("[ addchild: adding 0x%016"PRIx64" as child "
-			    "to 0x%016"PRIx64" ]\n", (uint64_t) a,
+			/*  debug("[ addchild: adding 0x%016" PRIx64 " as child "
+			    "to 0x%016" PRIx64 " ]\n", (uint64_t) a,
 			    (uint64_t) peeraddr);  */
 		}
 
@@ -866,8 +866,8 @@ uint64_t arcbios_addchild_manual(struct 
 		    machine->md.arc->next_component_address +
 		    (cpu->machine->md.arc->arc_64bit? 0x18 : 0x0c);
 
-		/*  printf("& ADDING %i: configdata=0x%016"PRIx64" "
-		    "component=0x%016"PRIx64"\n",
+		/*  printf("& ADDING %i: configdata=0x%016" PRIx64 " "
+		    "component=0x%016" PRIx64 "\n",
 		     machine->md.arc->n_configuration_data,
 		    (uint64_t) machine->md.arc->configuration_data_configdata[
 			machine->md.arc->n_configuration_data],
@@ -946,14 +946,14 @@ static void arcbios_get_msdos_partition_
 ugly_goto:
 	*start = 0; *size = 0;
 
-	/*  printf("reading MSDOS partition from offset 0x%"PRIx64"\n",
+	/*  printf("reading MSDOS partition from offset 0x%" PRIx64 "\n",
 	    (uint64_t) offset);  */
 
 	res = diskimage_access(machine, disk_id, disk_type, 0, offset,
 	    sector, sizeof(sector));
 	if (!res) {
 		fatal("[ arcbios_get_msdos_partition_size(): couldn't "
-		    "read the disk image, id %i, offset 0x%"PRIx64" ]\n",
+		    "read the disk image, id %i, offset 0x%" PRIx64 " ]\n",
 		    disk_id, (uint64_t) offset);
 		return;
 	}
@@ -1236,7 +1236,7 @@ int arcbios_emul(struct cpu *cpu)
 				cpu->cd.mips.gpr[MIPS_GPR_V0] = (int64_t)
 				    (int32_t) cpu->cd.mips.gpr[MIPS_GPR_V0];
 		}
-		debug("[ ARCBIOS GetPeer(node 0x%016"PRIx64"): 0x%016"PRIx64
+		debug("[ ARCBIOS GetPeer(node 0x%016" PRIx64 "): 0x%016" PRIx64
 		    " ]\n", (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A0],
 		    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_V0]);
 		break;
@@ -1287,8 +1287,8 @@ int arcbios_emul(struct cpu *cpu)
 				cpu->cd.mips.gpr[MIPS_GPR_V0] = (int64_t)
 				    (int32_t)cpu->cd.mips.gpr[MIPS_GPR_V0];
 		}
-		debug("[ ARCBIOS GetChild(node 0x%016"PRIx64"): 0x%016"
-		    PRIx64" ]\n", (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A0],
+		debug("[ ARCBIOS GetChild(node 0x%016" PRIx64 "): 0x%016"
+		    PRIx64 " ]\n", (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A0],
 		    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_V0]);
 		break;
 	case 0x2c:		/*  GetParent(node)  */
@@ -1336,19 +1336,19 @@ int arcbios_emul(struct cpu *cpu)
 				cpu->cd.mips.gpr[MIPS_GPR_V0] = (int64_t)
 				    (int32_t) cpu->cd.mips.gpr[MIPS_GPR_V0];
 		}
-		debug("[ ARCBIOS GetParent(node 0x%016"PRIx64"): 0x%016"
-		    PRIx64" ]\n", (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A0],
+		debug("[ ARCBIOS GetParent(node 0x%016" PRIx64 "): 0x%016"
+		    PRIx64 " ]\n", (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A0],
 		    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_V0]);
 		break;
 	case 0x30:  /*  GetConfigurationData(void *configdata, void *node)  */
-		/*  fatal("[ ARCBIOS GetConfigurationData(0x%016"PRIx64","
-		    "0x%016"PRIx64") ]\n",
+		/*  fatal("[ ARCBIOS GetConfigurationData(0x%016" PRIx64 ","
+		    "0x%016" PRIx64 ") ]\n",
 		    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A0],
 		    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A1]);  */
 		cpu->cd.mips.gpr[MIPS_GPR_V0] = ARCBIOS_EINVAL;
 		for (i=0; i<machine->md.arc->n_configuration_data; i++) {
 			/*  fatal("configuration_data_component[%i] = "
-			    "0x%016"PRIx64"\n", i, (uint64_t) machine->
+			    "0x%016" PRIx64 "\n", i, (uint64_t) machine->
 			    md.arc->configuration_data_component[i]);  */
 			if (cpu->cd.mips.gpr[MIPS_GPR_A1] ==
 			    machine->md.arc->configuration_data_component[i]) {
@@ -1671,8 +1671,8 @@ int arcbios_emul(struct cpu *cpu)
 			arcbios_handle_to_start_and_size(machine,
 			    handleTmp, &partition_offset, &size);
 
-			debug("[ ARCBIOS Write(%i,0x%08"PRIx64",%i,0x%08"
-			    PRIx64") ]\n", (int) cpu->cd.mips.gpr[MIPS_GPR_A0],
+			debug("[ ARCBIOS Write(%i,0x%08" PRIx64 ",%i,0x%08"
+			    PRIx64 ") ]\n", (int) cpu->cd.mips.gpr[MIPS_GPR_A0],
 			    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A1],
 			    (int) cpu->cd.mips.gpr[MIPS_GPR_A2],
 			    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A3]);
@@ -1718,13 +1718,13 @@ int arcbios_emul(struct cpu *cpu)
 		break;
 	case 0x70:	/*  Seek(uint32_t handle, int64_t *ofs,
 				 uint32_t whence): uint32_t  */
-		debug("[ ARCBIOS Seek(%i,0x%08"PRIx64",%i): ",
+		debug("[ ARCBIOS Seek(%i,0x%08" PRIx64 ",%i): ",
 		    (int) cpu->cd.mips.gpr[MIPS_GPR_A0],
 		    (uint64_t)cpu->cd.mips.gpr[MIPS_GPR_A1],
 		    (int) cpu->cd.mips.gpr[MIPS_GPR_A2]);
 
 		if (cpu->cd.mips.gpr[MIPS_GPR_A2] != 0) {
-			fatal("[ ARCBIOS Seek(%i,0x%08"PRIx64",%i): "
+			fatal("[ ARCBIOS Seek(%i,0x%08" PRIx64 ",%i): "
 			    "UNIMPLEMENTED whence=%i ]\n",
 			    (int) cpu->cd.mips.gpr[MIPS_GPR_A0],
 			    (uint64_t) cpu->cd.mips.gpr[MIPS_GPR_A1],
@@ -1752,7 +1752,7 @@ int arcbios_emul(struct cpu *cpu)
 			    
 			machine->md.arc->current_seek_offset[
 			    cpu->cd.mips.gpr[MIPS_GPR_A0]] = ofs;
-			debug("%016"PRIx64" ]\n", (uint64_t) ofs);
+			debug("%016" PRIx64 " ]\n", (uint64_t) ofs);
 		}
 
 		cpu->cd.mips.gpr[MIPS_GPR_V0] = 0;	/*  Success.  */
@@ -2456,7 +2456,7 @@ void arcbios_init(struct machine *machin
 		machine->md.arc->console_curx = 0;
 		machine->md.arc->console_cury = 0;
 
-		arcbios_putstring(cpu, "GXemul "VERSION"  ARCBIOS emulation\n");
+		arcbios_putstring(cpu, "GXemul " VERSION "  ARCBIOS emulation\n");
 
 		snprintf(tmpstr, sizeof(tmpstr), "%i cpu%s (%s), %i MB "
 		    "memory\n\n", machine->ncpus, machine->ncpus > 1? "s" : "",
@@ -2609,7 +2609,7 @@ void arcbios_init(struct machine *machin
 
 	system = arcbios_addchild_manual(cpu, COMPONENT_CLASS_SystemClass,
 	    COMPONENT_TYPE_ARC, 0,1,2,0, 0xffffffff, name, 0/*ROOT*/, NULL, 0);
-	debug("ARC system @ 0x%"PRIx64" (\"%s\")\n", (uint64_t) system, name);
+	debug("ARC system @ 0x%" PRIx64 " (\"%s\")\n", (uint64_t) system, name);
 
 
 	/*
@@ -2720,18 +2720,18 @@ void arcbios_init(struct machine *machin
 			    0xffffffff, NULL, cpuaddr, NULL, 0);
 		}
 
-		debug("ARC cpu%i @ 0x%"PRIx64, i, (uint64_t) cpuaddr);
+		debug("ARC cpu%i @ 0x%" PRIx64, i, (uint64_t) cpuaddr);
 
 		if (fpu != 0)
-			debug(" (fpu @ 0x%"PRIx64")\n", (uint64_t) fpu);
+			debug(" (fpu @ 0x%" PRIx64 ")\n", (uint64_t) fpu);
 		else
 			debug("\n");
 
-		debug("    picache @ 0x%"PRIx64", pdcache @ 0x%"PRIx64"\n",
+		debug("    picache @ 0x%" PRIx64 ", pdcache @ 0x%" PRIx64 "\n",
 		    (uint64_t) picache, (uint64_t) pdcache);
 
 		if (cpu->cd.mips.cache_secondary >= 12)
-			debug("    sdcache @ 0x%"PRIx64"\n",
+			debug("    sdcache @ 0x%" PRIx64 "\n",
 			    (uint64_t) sdcache);
 
 		if (machine->machine_type == MACHINE_SGI) {
@@ -2740,7 +2740,7 @@ void arcbios_init(struct machine *machin
 			    COMPONENT_CLASS_MemoryClass,
 			    COMPONENT_TYPE_MemoryUnit, 0, 1, 2, 0,
 			    0xffffffff, "memory", cpuaddr, NULL, 0);
-			debug("ARC memory @ 0x%"PRIx64"\n", (uint64_t) memory);
+			debug("ARC memory @ 0x%" PRIx64 "\n", (uint64_t) memory);
 		}
 	}
 
@@ -2847,4 +2847,3 @@ void arcbios_init(struct machine *machin
 
 	arc_environment_setup(machine, is64bit, primary_ether_addr);
 }
-
