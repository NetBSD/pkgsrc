$NetBSD: patch-ic_sparc_sparc-execute.c,v 1.1 2020/08/13 05:59:52 tsutsui Exp $

- Appease gcc warning.

--- ic/sparc/sparc-execute.c.orig	2010-05-22 13:25:10.000000000 +0000
+++ ic/sparc/sparc-execute.c
@@ -612,7 +612,7 @@ _TME_SPARC_EXECUTE_NAME(struct tme_sparc
 			    != pc_previous)) {
       if (__tme_predict_true(((tme_sparc_ireg_t) (pc + sizeof(tme_uint32_t)))
 			     == ic->tme_sparc_ireg(TME_SPARC_IREG_PC_NEXT))) {
-	tme_recode_thunk_off_t insns_thunk;
+	tme_recode_thunk_off_t insns_thunk = 0; /* XXX gcc -Wuninitialized */
 
 	/* if the current instruction TLB entry is not the invalid TLB
 	   entry, and there is an instructions thunk for this PC: */
