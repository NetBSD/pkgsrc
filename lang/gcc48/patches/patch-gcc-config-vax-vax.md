$NetBSD: patch-gcc-config-vax-vax.md,v 1.1 2013/10/24 18:31:12 martin Exp $

Part of upstream change rev. 202796, additionally change from Matt Thomas
to fix http://gcc.gnu.org/bugzilla/show_bug.cgi?id=58442.

--- gcc/config/vax/vax.md.orig	2013-01-15 22:30:24.000000000 +0100
+++ gcc/config/vax/vax.md	2013-10-24 18:21:32.000000000 +0200
@@ -697,14 +697,14 @@
 	(ashift:DI (match_operand:DI 1 "general_operand" "g")
 		   (match_operand:QI 2 "general_operand" "g")))]
   ""
-  "ashq %2,%1,%0")
+  "ashq %2,%D1,%0")
 
 (define_insn ""
   [(set (match_operand:DI 0 "nonimmediate_operand" "=g")
 	(ashiftrt:DI (match_operand:DI 1 "general_operand" "g")
 		     (neg:QI (match_operand:QI 2 "general_operand" "g"))))]
   ""
-  "ashq %2,%1,%0")
+  "ashq %2,%D1,%0")
 
 ;; We used to have expand_shift handle logical right shifts by using extzv,
 ;; but this make it very difficult to do lshrdi3.  Since the VAX is the
@@ -781,8 +781,9 @@
    "(INTVAL (operands[1]) == 8 || INTVAL (operands[1]) == 16)
    && INTVAL (operands[2]) % INTVAL (operands[1]) == 0
    && (REG_P (operands[0])
-       || ! mode_dependent_address_p (XEXP (operands[0], 0),
-				       MEM_ADDR_SPACE (operands[0])))"
+       || (MEM_P(operands[0])
+          && ! mode_dependent_address_p (XEXP (operands[0], 0),
+				       MEM_ADDR_SPACE (operands[0]))))"
   "*
 {
   if (REG_P (operands[0]))
@@ -810,8 +811,9 @@
   "(INTVAL (operands[2]) == 8 || INTVAL (operands[2]) == 16)
    && INTVAL (operands[3]) % INTVAL (operands[2]) == 0
    && (REG_P (operands[1])
-       || ! mode_dependent_address_p (XEXP (operands[1], 0),
-				      MEM_ADDR_SPACE (operands[1])))"
+       || (MEM_P(operands[1])
+          && ! mode_dependent_address_p (XEXP (operands[1], 0),
+				      MEM_ADDR_SPACE (operands[1]))))"
   "*
 {
   if (REG_P (operands[1]))
@@ -838,7 +840,8 @@
   "(INTVAL (operands[2]) == 8 || INTVAL (operands[2]) == 16)
    && INTVAL (operands[3]) % INTVAL (operands[2]) == 0
    && (REG_P (operands[1])
-       || ! mode_dependent_address_p (XEXP (operands[1], 0),
+       || (MEM_P(operands[1])
+          && ! mode_dependent_address_p (XEXP (operands[1], 0),
 				      MEM_ADDR_SPACE (operands[1])))"
   "*
 {
