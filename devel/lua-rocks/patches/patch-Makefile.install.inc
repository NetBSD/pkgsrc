$NetBSD: patch-Makefile.install.inc,v 1.2 2016/10/06 20:28:54 alnsn Exp $

Be pkg_alternatives(8) friendly.

--- Makefile.install.inc.orig	2016-10-06 19:01:55.000000000 +0000
+++ Makefile.install.inc
@@ -9,7 +9,6 @@ install_bins:
 	do \
 	   cp "$$f" "$(DESTDIR)$(BINDIR)/$$f-$$luaver"; \
 	   chmod +rx "$(DESTDIR)$(BINDIR)/$$f-$$luaver"; \
-	   ln -nfs "$$f-$$luaver" "$(DESTDIR)$(BINDIR)/$$f"; \
 	done
 
 install_luas:
