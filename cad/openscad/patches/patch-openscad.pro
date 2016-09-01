$NetBSD: patch-openscad.pro,v 1.2 2016/09/01 19:53:36 plunky Exp $

install manpage to correct location

--- openscad.pro.orig	2015-11-16 05:13:56.000000000 +0000
+++ openscad.pro
@@ -585,6 +585,6 @@ icons.path = $$PREFIX/share/pixmaps
 icons.extra = test -f icons/$${FULLNAME}.png && cp -f icons/$${FULLNAME}.png \"\$(INSTALL_ROOT)$${icons.path}/\" || cp -f icons/openscad.png \"\$(INSTALL_ROOT)$${icons.path}/$${FULLNAME}.png\"
 INSTALLS += icons
 
-man.path = $$PREFIX/share/man/man1
+man.path = $$PREFIX/man/man1
 man.extra = cp -f doc/openscad.1 \"\$(INSTALL_ROOT)$${man.path}/$${FULLNAME}.1\"
 INSTALLS += man
