$NetBSD: patch-ELF_Options.td,v 1.1 2019/02/01 16:30:00 mgorny Exp $

Add support for customizing LLD behavior on target triple.
https://reviews.llvm.org/D56650

--- ELF/Options.td.orig	2018-07-30 17:36:38.000000000 +0000
+++ ELF/Options.td
@@ -303,6 +303,8 @@ defm symbol_ordering_file:
 
 defm sysroot: Eq<"sysroot", "Set the system root">;
 
+defm target: Eq<"target", "Apply configuration defaults for a given target">;
+
 def target1_rel: F<"target1-rel">, HelpText<"Interpret R_ARM_TARGET1 as R_ARM_REL32">;
 
 def target1_abs: F<"target1-abs">, HelpText<"Interpret R_ARM_TARGET1 as R_ARM_ABS32 (default)">;
