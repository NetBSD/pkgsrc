$NetBSD: patch-src_cpus_cpu__alpha__palcode.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/cpus/cpu_alpha_palcode.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/cpu_alpha_palcode.cc
@@ -90,7 +90,7 @@ void alpha_palcode_name(uint32_t palcode
 	case 0xaa: snprintf(buf, buflen, "PAL_gentrap"); break;
 	case 0xae: snprintf(buf, buflen, "PAL_clrfen"); break;
 	case 0x3fffffe: snprintf(buf, buflen, "GXemul_PROM"); break;
-	default:snprintf(buf, buflen, "UNKNOWN 0x%"PRIx32, palcode);
+	default:snprintf(buf, buflen, "UNKNOWN 0x%" PRIx32, palcode);
 	}
 }
 
@@ -144,7 +144,7 @@ void alpha_prom_call(struct cpu *cpu)
 		store_buf(cpu, a2, s, len);
 		break;
 
-	default:fatal("[ Alpha PALcode: GXemul PROM call, a0=0x%"PRIx64" ]\n",
+	default:fatal("[ Alpha PALcode: GXemul PROM call, a0=0x%" PRIx64 " ]\n",
 		    (uint64_t) cpu->cd.alpha.r[ALPHA_A0]);
 		cpu->running = 0;
 	}
@@ -307,7 +307,7 @@ Make sure they are correct, as documente
 		 *	a0 = -1: invalidate everything with ASM=0.
 		 *	a0 = -2: invalidate everything
 		 */
-		// debug("[ Alpha PALcode: PAL_OSF1_tbi: a0=%"PRIi64" a1=0x%"
+		// debug("[ Alpha PALcode: PAL_OSF1_tbi: a0=%" PRIi64 " a1=0x%"
 		//    PRIx64" ]\n", (int64_t)a0, (uint64_t)a1);
 		if (a0 >= 1)
 			cpu->invalidate_translation_caches(cpu, a1, INVALIDATE_VADDR);
@@ -390,4 +390,3 @@ Make sure they are correct, as documente
 	 *  However, it's easier to just leave the registers as they are.
 	 */
 }
-
