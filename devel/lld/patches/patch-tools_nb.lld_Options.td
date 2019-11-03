$NetBSD: patch-tools_nb.lld_Options.td,v 1.1 2019/11/03 12:11:27 kamil Exp $

[LLD] Add NetBSD support as a new flavor of LLD (nb.lld)
https://reviews.llvm.org/D69755

--- tools/nb.lld/Options.td.orig	2019-11-03 11:46:29.309947085 +0000
+++ tools/nb.lld/Options.td
@@ -0,0 +1,7 @@
+include "llvm/Option/OptParser.td"
+
+class F<string name>: Flag<["--", "-"], name>;
+
+def version: F<"version">, HelpText<"Display the version number and exit">;
+def v: Flag<["-"], "v">, HelpText<"Display the version number">;
+def: Flag<["-"], "V">, Alias<version>, HelpText<"Alias for --version">;
