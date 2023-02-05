$NetBSD: patch-toolkit_mozapps_installer_packager.mk,v 1.1 2023/02/05 08:32:24 he Exp $

--- toolkit/mozapps/installer/packager.mk.orig	2020-08-28 21:33:59.000000000 +0000
+++ toolkit/mozapps/installer/packager.mk
@@ -156,7 +156,7 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	#ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 upload:
 	$(PYTHON3) -u $(MOZILLA_DIR)/build/upload.py --base-path $(DIST) $(UPLOAD_FILES)
