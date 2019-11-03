$NetBSD: patch-ELF_Options.td,v 1.4 2019/11/03 12:10:29 kamil Exp $

Add dummy option for an AArch64 erratum.

--- ELF/Options.td.orig	2019-07-17 14:54:02.000000000 +0000
+++ ELF/Options.td
@@ -168,6 +168,9 @@ defm filter: Eq<"filter", "Set DT_FILTER
 
 defm fini: Eq<"fini", "Specify a finalizer function">, MetaVarName<"<symbol>">;
 
+def fix_cortex_a53_835769: F<"fix-cortex-a53-835769">,
+  HelpText<"Apply fixes for AArch64 Cortex-A53 erratum 835769">;
+
 def fix_cortex_a53_843419: F<"fix-cortex-a53-843419">,
   HelpText<"Apply fixes for AArch64 Cortex-A53 erratum 843419">;
 
