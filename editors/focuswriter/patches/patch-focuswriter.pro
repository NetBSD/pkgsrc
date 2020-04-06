$NetBSD: patch-focuswriter.pro,v 1.1 2020/04/06 08:28:38 pin Exp $

Add man to the correct location

--- focuswriter.pro.orig	2020-01-16 14:45:49.000000000 +0000
+++ focuswriter.pro
@@ -317,7 +317,7 @@ macx {
 	appdata.path = $$DATADIR/metainfo/
 
 	man.files = resources/unix/focuswriter.1
-	man.path = $$PREFIX/share/man/man1
+	man.path = $$PREFIX/$$PKGMANDIR/man1
 
 	qm.files = $$replace(TRANSLATIONS, .ts, .qm)
 	qm.path = $$DATADIR/focuswriter/translations
