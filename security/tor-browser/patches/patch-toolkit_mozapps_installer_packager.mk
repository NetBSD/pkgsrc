$NetBSD: patch-toolkit_mozapps_installer_packager.mk,v 1.1 2019/02/25 15:32:24 wiz Exp $

* Symbolic link to lib/firefox/firefox causes 'Couldn't load XPCOM.' error.

--- toolkit/mozapps/installer/packager.mk.orig	2018-01-11 20:17:05.000000000 +0000
+++ toolkit/mozapps/installer/packager.mk
@@ -137,7 +137,7 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	#ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 checksum:
 	mkdir -p `dirname $(CHECKSUM_FILE)`
