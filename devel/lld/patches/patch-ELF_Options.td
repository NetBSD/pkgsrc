$NetBSD: patch-ELF_Options.td,v 1.5 2022/08/12 08:52:51 pin Exp $

Add dummy option for an AArch64 erratum.

--- ELF/Options.td.orig	2022-06-22 16:46:24.000000000 +0000
+++ ELF/Options.td
@@ -217,6 +217,9 @@ defm filter: Eq<"filter", "Set DT_FILTER
 
 defm fini: Eq<"fini", "Specify a finalizer function">, MetaVarName<"<symbol>">;
 
+def fix_cortex_a53_835769: F<"fix-cortex-a53-835769">,
+  HelpText<"Apply fixes for AArch64 Cortex-A53 erratum 835769">;
+
 def fix_cortex_a53_843419: F<"fix-cortex-a53-843419">,
   HelpText<"Apply fixes for AArch64 Cortex-A53 erratum 843419">;
 
