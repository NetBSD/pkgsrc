$NetBSD: patch-project.mak,v 1.1 2016/03/31 10:27:26 markd Exp $

Do not create an ld.conf, this is done afterwards through the PLIST
--- project.mak.orig	2015-11-09 21:23:00.000000000 +0000
+++ project.mak
@@ -96,7 +96,7 @@ endif
 
 ifeq ($(INSTMETH),findlib)
 install:
-	$(OCAMLFIND) install -destdir "$(INSTALLDIR)" zarith META $(TOINSTALL) dllzarith.$(DLLSUFFIX)
+	$(OCAMLFIND) install -destdir "$(INSTALLDIR)" -ldconf ignore zarith META $(TOINSTALL) dllzarith.$(DLLSUFFIX)
 
 uninstall:
 	$(OCAMLFIND) remove -destdir "$(INSTALLDIR)" zarith
