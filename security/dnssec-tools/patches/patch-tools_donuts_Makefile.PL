$NetBSD: patch-tools_donuts_Makefile.PL,v 1.1 2011/08/19 12:16:33 obache Exp $

* fixes installed location reference.

--- tools/donuts/Makefile.PL.orig	2011-01-04 18:36:36.000000000 +0000
+++ tools/donuts/Makefile.PL
@@ -31,7 +31,7 @@ installrulefiles:
 	$(INSTALL) rules/*.txt $(RULESDIR)
 
 installfixpaths:
-	$(PERL) -p -i -e "s|/usr/local/share|$(PREFIX)/share|" $(DISTDIR)/$(INSTALLBIN)/donuts
+	$(PERL) -p -i -e "s|/usr/local/share|$(PREFIX)/share|" $(DESTINSTALLVENDORBIN)/donuts
 ';
 }
 
