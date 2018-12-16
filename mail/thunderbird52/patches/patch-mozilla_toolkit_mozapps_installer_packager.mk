$NetBSD: patch-mozilla_toolkit_mozapps_installer_packager.mk,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/toolkit/mozapps/installer/packager.mk.orig	2017-04-14 04:53:30.000000000 +0000
+++ mozilla/toolkit/mozapps/installer/packager.mk
@@ -139,8 +139,8 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
-ifdef INSTALL_SDK # Here comes the hard part
+	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)/${MOZILLA_PKG_NAME}
+ifeq ($(MOZ_APP_NAME),xulrunner)
 	$(NSINSTALL) -D $(DESTDIR)$(includedir)
 	(cd $(DIST)/include && $(TAR) $(TAR_CREATE_FLAGS) - .) | \
 	  (cd $(DESTDIR)$(includedir) && tar -xf -)
