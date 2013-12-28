$NetBSD: patch-ic_m68k_m68k-insns-auto.sh,v 1.1 2013/12/28 19:16:48 martin Exp $

Fix from upstream CVS: fix sequencing for cas32 (avoid a diag assert)

--- ic/m68k/m68k-insns-auto.sh.orig	2009-08-29 21:38:23.000000000 +0200
+++ ic/m68k/m68k-insns-auto.sh	2013-12-23 13:12:54.000000000 +0100
@@ -900,6 +900,10 @@ for size in 8 16 32; do
    	echo -n "    ic->tme_m68k_ireg_memx${size} = "
 	if test ${size} != 8; then echo -n "tme_betoh_u${size}"; fi
 	echo "(value_mem);"
+	echo ""
+	echo "    /* step the transfer count once for the read, and once for the write: */"
+	echo "    TME_M68K_SEQUENCE_TRANSFER_STEP;"
+	echo "    TME_M68K_SEQUENCE_TRANSFER_STEP;"
 	echo "  }"
 	echo ""
 	echo "  /* compare the compare operand to the effective address operand: */"
