$NetBSD: patch-mozilla_toolkit_mozapps_installer_packager.mk,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/toolkit/mozapps/installer/packager.mk.orig	2017-03-05 20:58:33.000000000 +0000
+++ mozilla/toolkit/mozapps/installer/packager.mk
@@ -132,8 +132,8 @@ endif
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
