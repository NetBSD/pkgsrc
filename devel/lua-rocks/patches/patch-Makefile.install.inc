$NetBSD: patch-Makefile.install.inc,v 1.1.1.1 2016/06/06 21:31:52 alnsn Exp $

Be pkg_alternatives(8) friendly.

--- Makefile.install.inc.orig	2015-12-29 15:50:56.000000000 +0000
+++ Makefile.install.inc
@@ -8,7 +8,6 @@ install_bins:
 	for f in $(BIN_FILES); \
 	do \
 	   cp "$$f" "$(DESTDIR)$(BINDIR)/$$f-$$luaver"; \
-	   ln -nfs "$$f-$$luaver" "$(DESTDIR)$(BINDIR)/$$f"; \
 	done
 
 install_luas:
