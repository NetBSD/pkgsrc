$NetBSD: patch-src_cpus_memory__mips__v2p.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/cpus/memory_mips_v2p.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/memory_mips_v2p.cc
@@ -294,7 +294,7 @@ int TRANSLATE_ADDRESS(struct cpu *cpu, u
 				case 0x07fffff:	pageshift = 22; break;
 				case 0x1ffffff:	pageshift = 24; break;
 				case 0x7ffffff:	pageshift = 26; break;
-				default:fatal("pmask=%08"PRIx32"\n", pmask);
+				default:fatal("pmask=%08" PRIx32 "\n", pmask);
 					exit(1);
 				}
 
@@ -347,8 +347,8 @@ int TRANSLATE_ADDRESS(struct cpu *cpu, u
 			/*  Is there a VPN and ASID match?  */
 			if (entry_vpn2 == vaddr_vpn2 &&
 			    (entry_asid == vaddr_asid || g_bit)) {
-				/*  debug("OK MAP 1, i=%i { vaddr=%016"PRIx64" "
-				    "==> paddr %016"PRIx64" v=%i d=%i "
+				/*  debug("OK MAP 1, i=%i { vaddr=%016" PRIx64 " "
+				    "==> paddr %016" PRIx64 " v=%i d=%i "
 				    "asid=0x%02x }\n", i, (uint64_t) vaddr,
 				    (uint64_t) *return_paddr, v_bit?1:0,
 				    d_bit?1:0, vaddr_asid);  */
@@ -357,16 +357,16 @@ int TRANSLATE_ADDRESS(struct cpu *cpu, u
 					    writeflag == MEM_READ)) {
 						uint64_t paddr;
 						/*  debug("OK MAP 2!!! { w=%i "
-						    "vaddr=%016"PRIx64" ==> "
+						    "vaddr=%016" PRIx64 " ==> "
 						    "d=%i v=%i paddr %016"
-						    PRIx64" ",
+						    PRIx64 " ",
 						    writeflag, (uint64_t)vaddr,
 						    d_bit?1:0, v_bit?1:0,
 						    (uint64_t) *return_paddr);
 						    debug(", tlb entry %2i: ma"
-						    "sk=%016"PRIx64" hi=%016"
-						    PRIx64" lo0=%016"PRIx64
-						    " lo1=%016"PRIx64"\n",
+						    "sk=%016" PRIx64 " hi=%016"
+						    PRIx64" lo0=%016" PRIx64
+						    " lo1=%016" PRIx64 "\n",
 						    i, cp0->tlbs[i].mask, cp0->
 						    tlbs[i].hi, cp0->tlbs[i].
 						    lo0, cp0->tlbs[i].lo1);
@@ -445,4 +445,3 @@ exception:
 	/*  Return failure:  */
 	return 0;
 }
-
