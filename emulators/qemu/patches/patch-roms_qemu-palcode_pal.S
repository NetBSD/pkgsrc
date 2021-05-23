$NetBSD: patch-roms_qemu-palcode_pal.S,v 1.2 2021/05/23 13:53:10 thorpej Exp $

In the unaligned access exception vector, fix an apparent typo that
prevented the return PC from being stored in the trap frame.

In SWPPAL, allow an additional, non-architected argument for the
switch to OSF/1 PALcode.  This extra argument specifies the desired
value of $pv after SWPPAL has completed, and is for internal PALcode
use only and is needed for secondary CPU spin-up.  This is allowed
because per the architecure specification, all registers other than
$sp and $v0 are UNPREDICTABLE after SWPPAL, and this PALcode's use
of SWPPAL for secondary CPU spin-up is an implementation detail.
This PALcode was already relying on this UNPREDICTABLE behavior for
its own purposes; this change merely gives control of this behavior
to internal SWPPAL callers.

--- roms/qemu-palcode/pal.S.orig	2020-12-08 17:00:57.000000000 +0000
+++ roms/qemu-palcode/pal.S	2021-05-23 06:23:53.826566568 +0000
@@ -278,7 +278,7 @@ Pal_Unalign:
 	blbs	p6, MchkBugCheck
 	addq	p6, 4, p6		// increment past the faulting insn
 
-	STACK_FRAME p0, p1, p2, 1
+	STACK_FRAME p0, p6, p2, 1
 
 	mfpr	p0, ptEntUna
 	mfpr	$gp, ptKgp
@@ -566,6 +566,8 @@ ENDFN	CallPal_Cserve_Cont
  *	r17 (a1) = New PC
  *	r18 (a2) = New PCB
  *	r19 (a3) = New VptPtr
+ *	r20 (a4) = New Procedure Value (to place into $27)
+ *	           (Non-standard; See note below.)
  * 
  * OUTPUT PARAMETERS:
  *
@@ -574,11 +576,15 @@ ENDFN	CallPal_Cserve_Cont
  *			1 - Unknown PALcode variant
  *			2 - Known PALcode variant, but PALcode not loaded
  *
- *	r26 (ra) = r27 (pv) = New PC
- *		Note that this is non-architected, but is relied on by
+ *	r26 (ra) = New PC
+ *	r27 (pv) = From $20
+ *		Note that this is non-architected, but is relied upon by
  *		the usage of SwpPal within our own console code in order
- *		to simplify its use within C code.
- *
+ *		to simplify its use within C code.  We can get away with
+ *		the extra non-standard argument (in $20) because as
+ *		architected, all registers except SP and R0 are
+ *		UNPREDICTABLE; therefore private internal usage is
+ *		fine.
  */
 	ORG_CALL_PAL_PRIV(0x0A)
 CallPal_SwpPal:
@@ -624,7 +630,7 @@ CallPal_SwpPal_Cont:
 	mtpr	$31, qemu_tbia		// Flush TLB for new PTBR
 
 	mov	a1, $26
-	mov	a1, $27
+	mov	a4, $27
 	hw_ret	(a1)
 ENDFN	CallPal_SwpPal_Cont
 	.previous
