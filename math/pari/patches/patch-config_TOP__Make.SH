$NetBSD: patch-config_TOP__Make.SH,v 1.3 2023/04/24 08:51:13 riastradh Exp $

* don't generate docs implicitly

--- config/TOP_Make.SH.orig	2022-09-16 17:16:27.000000000 +0000
+++ config/TOP_Make.SH
@@ -40,7 +40,6 @@ dft target::
 
 all::
 	@\$(MAKE) gp
-	@-cd doc && \$(MAKE) doc
 
 gp bench test-kernel test-all install cleanall cleanobj cleantest nsis link-data install-bin install-doc install-doctex install-docdvi install-docpdf install-nodata install-data install-lib-sta install-bin-sta dobench dyntest-all statest-all tune $top_test_extra $top_dotest_extra::
 	@dir=\`config/objdir\`; echo "Making \$@ in \$\$dir";\\
