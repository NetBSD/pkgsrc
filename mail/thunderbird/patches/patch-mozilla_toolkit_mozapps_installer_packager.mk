$NetBSD: patch-mozilla_toolkit_mozapps_installer_packager.mk,v 1.1 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/toolkit/mozapps/installer/packager.mk.orig	2016-04-07 21:33:34.000000000 +0000
+++ mozilla/toolkit/mozapps/installer/packager.mk
@@ -133,7 +133,7 @@ endif
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
 	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
-ifdef INSTALL_SDK # Here comes the hard part
+ifeq ($(MOZ_APP_NAME),xulrunner)
 	$(NSINSTALL) -D $(DESTDIR)$(includedir)
 	(cd $(DIST)/include && $(TAR) $(TAR_CREATE_FLAGS) - .) | \
 	  (cd $(DESTDIR)$(includedir) && tar -xf -)
