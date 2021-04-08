$NetBSD: patch-openscad.pro,v 1.3 2021/04/08 10:26:08 bouyer Exp $

install manpage to correct location

--- openscad.pro.orig	2021-01-31 18:41:09.000000000 +0100
+++ openscad.pro	2021-04-04 20:58:11.094361964 +0200
@@ -757,7 +757,7 @@
 icon512.extra = test -f icons/$${FULLNAME}-512.png && cp -f icons/$${FULLNAME}-512.png \"\$(INSTALL_ROOT)$${icon512.path}/$${FULLNAME}.png\" || cp -f icons/openscad-512.png \"\$(INSTALL_ROOT)$${icon512.path}/$${FULLNAME}.png\"
 INSTALLS += icon48 icon64 icon128 icon256 icon512
 
-man.path = $$PREFIX/share/man/man1
+man.path = $$PREFIX/man/man1
 man.extra = cp -f doc/openscad.1 \"\$(INSTALL_ROOT)$${man.path}/$${FULLNAME}.1\"
 INSTALLS += man
 
