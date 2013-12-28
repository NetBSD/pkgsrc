$NetBSD: patch-ic_m68k_m68k-misc.c,v 1.1 2013/12/28 19:16:48 martin Exp $

Fix from upstream CVS: fix sequencing and fault handling for read-modify-write
instructions.

--- ic/m68k/m68k-misc.c.orig	2009-08-29 21:47:52.000000000 +0200
+++ ic/m68k/m68k-misc.c	2013-12-23 13:12:54.000000000 +0100
@@ -1441,6 +1441,9 @@ tme_m68k_rmw_start(struct tme_m68k *ic,
   tme_uint32_t *buffer_reg;
   int supported;
 
+  /* this instruction can fault: */
+  TME_M68K_INSN_CANFAULT;
+
   /* if the user reran the cycle: */
   if (TME_M68K_SEQUENCE_RESTARTING
       && (ic->_tme_m68k_group0_buffer_read_softrr > 0
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
