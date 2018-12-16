$NetBSD: patch-toolkit_mozapps_installer_packager.mk,v 1.1 2018/12/16 08:12:16 ryoon Exp $

--- toolkit/mozapps/installer/packager.mk.orig	2018-12-04 23:12:03.000000000 +0000
+++ toolkit/mozapps/installer/packager.mk
@@ -130,7 +130,7 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	#ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 checksum:
 	mkdir -p `dirname $(CHECKSUM_FILE)`
