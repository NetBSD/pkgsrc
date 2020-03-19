$NetBSD: patch-ic_m68k_m68k-misc.c,v 1.2 2020/03/19 02:27:21 rin Exp $

- Fix from upstream CVS: fix sequencing and fault handling for
  read-modify-write instructions.

- Fix logic to determine whether destination EA for cas lies b/w page
  boundary or not.

--- ic/m68k/m68k-misc.c.orig	2009-08-30 04:47:52.000000000 +0900
+++ ic/m68k/m68k-misc.c	2020-03-18 23:15:56.877341698 +0900
@@ -1441,6 +1441,9 @@ tme_m68k_rmw_start(struct tme_m68k *ic,
   tme_uint32_t *buffer_reg;
   int supported;
 
+  /* this instruction can fault: */
+  TME_M68K_INSN_CANFAULT;
+
   /* if the user reran the cycle: */
   if (TME_M68K_SEQUENCE_RESTARTING
       && (ic->_tme_m68k_group0_buffer_read_softrr > 0
@@ -1690,7 +1693,7 @@ tme_m68k_rmw_start(struct tme_m68k *ic,
       tlb = rmw->tme_m68k_rmw_tlbs[address_i];
 
       /* if this TLB entry doesn't cover the entire operand: */
-      if ((((tme_bus_addr32_t) tlb->tme_m68k_tlb_linear_last) - address) < rmw->tme_m68k_rmw_size) {
+      if ((((tme_bus_addr32_t) tlb->tme_m68k_tlb_linear_last + 1) - address) < rmw->tme_m68k_rmw_size) {
 
 	/* we can't support this instruction on this memory, because
 	   we can't split an atomic operation across TLB entries.  on
@@ -1754,9 +1757,6 @@ tme_m68k_rmw_start(struct tme_m68k *ic,
 	  tlbs_busy[!tlb_i] = FALSE;
 	}
 
-	/* this instruction can fault: */
-	TME_M68K_INSN_CANFAULT;
-
 	/* do a slow read.  if this is the first address, we start a
 	   slow read-modify-write cycle, otherwise we do a normal slow
 	   read cycle: */
@@ -1869,6 +1869,9 @@ tme_m68k_rmw_start(struct tme_m68k *ic,
 
       /* byteswap the value read: */
       *buffer_reg = tme_betoh_u32(*buffer_reg);
+
+      /* step the transfer count: */
+      TME_M68K_SEQUENCE_TRANSFER_STEP;
     
     } while (++address_i < rmw->tme_m68k_rmw_address_count);
   }
@@ -1990,6 +1993,9 @@ tme_m68k_rmw_finish(struct tme_m68k *ic,
 	      + (sizeof(ic->tme_m68k_ireg_memx32)
 		 - rmw->tme_m68k_rmw_size)),
 	     rmw->tme_m68k_rmw_size);
+
+      /* step the transfer count: */
+      TME_M68K_SEQUENCE_TRANSFER_STEP;
     }
 
   } while (++address_i < rmw->tme_m68k_rmw_address_count);
