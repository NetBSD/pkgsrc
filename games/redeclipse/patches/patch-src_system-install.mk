$NetBSD: patch-src_system-install.mk,v 1.1 2023/09/15 22:47:59 charlotte Exp $

Parameterize ed(1).

--- src/system-install.mk.orig	2019-12-19 18:00:28.000000000 -0800
+++ src/system-install.mk	2023-09-15 15:24:25.538177725 -0700
@@ -19,6 +19,8 @@
 pixmapdir=$(DESTDIR)$(prefix)/share/pixmaps
 appdatadir=$(DESTDIR)$(prefix)/share/appdata
 
+ED?=	ed
+
 ICONS= \
 	install/nix/$(appsrcname)_x16.png \
 	install/nix/$(appsrcname)_x32.png \
@@ -69,7 +71,7 @@
 	s,@DOCDIR@,$(patsubst $(DESTDIR)%,%,$(docdir)),g\n\
 	g,@APPNAME@,\
 	s,@APPNAME@,$(appname),g\n\
-	w\n" | ed -s $(gamesbindir)/$(appname)
+	w\n" | $(ED) -s $(gamesbindir)/$(appname)
 
 system-install-server: server
 	$(MKDIR) $(libexecdir)/$(appname)
@@ -88,7 +90,7 @@
 	s,@DOCDIR@,$(patsubst $(DESTDIR)%,%,$(docdir)),g\n\
 	g,@APPNAME@,\
 	s,@APPNAME@,$(appname),g\n\
-	w\n" | ed -s $(gamesbindir)/$(appname)-server
+	w\n" | $(ED) -s $(gamesbindir)/$(appname)-server
 
 system-install-common:
 	$(MKDIR) $(libexecdir)/$(appname)
