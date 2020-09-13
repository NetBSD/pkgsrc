$NetBSD: patch-Makefile.PL,v 1.3 2020/09/13 09:13:45 wiz Exp $

Fix man page path.
Install config into examples/ directory.

--- Makefile.PL.orig	2019-04-12 15:04:29.000000000 +0000
+++ Makefile.PL
@@ -173,12 +173,12 @@ sub constants {
         INSTALLLIB           => '$(DATADIR)/lib',
         INSTALLSITELIB       => '$(DATADIR)/lib',
         INSTALLVENDORLIB     => '$(DATADIR)/lib',
-        INSTALLMAN1DIR       => '$(PREFIX)/share/man/man1',
-        INSTALLSITEMAN1DIR   => '$(PREFIX)/share/man/man1',
-        INSTALLVENDORMAN1DIR => '$(PREFIX)/share/man/man1',
-        INSTALLMAN3DIR       => '$(PREFIX)/share/man/man3',
-        INSTALLSITEMAN3DIR   => '$(PREFIX)/share/man/man3',
-        INSTALLVENDORMAN3DIR => '$(PREFIX)/share/man/man3',
+        INSTALLMAN1DIR       => '$(PREFIX)/$(PKGMANDIR)/man1',
+        INSTALLSITEMAN1DIR   => '$(PREFIX)/$(PKGMANDIR)/man1',
+        INSTALLVENDORMAN1DIR => '$(PREFIX)/$(PKGMANDIR)/man1',
+        INSTALLMAN3DIR       => '$(PREFIX)/$(PKGMANDIR)/man3',
+        INSTALLSITEMAN3DIR   => '$(PREFIX)/$(PKGMANDIR)/man3',
+        INSTALLVENDORMAN3DIR => '$(PREFIX)/$(PKGMANDIR)/man3',
         SYSCONFDIR           => '$(PREFIX)/etc/fusioninventory',
         DATADIR              => '$(PREFIX)/share/fusioninventory',
         LOCALSTATEDIR        => '$(PREFIX)/var/fusioninventory',
@@ -239,17 +239,17 @@ sub install {
     $install .= <<'EOF';
 
 config_install : pure_install
-	$(MKPATH) $(DESTDIR)$(SYSCONFDIR)
-	$(NOECHO) $(CHMOD) $(PERM_DIR) $(DESTDIR)$(SYSCONFDIR)
+	$(MKPATH) $(DESTDIR)$(PREFIX)/share/examples/fusioninventory
+	$(NOECHO) $(CHMOD) $(PERM_DIR) $(DESTDIR)$(PREFIX)/share/examples/fusioninventory
 	for config in agent.cfg inventory-server-plugin.cfg server-test-plugin.cfg ssl-server-plugin.cfg ; \
 	do \
-	  if $(TEST_F) $(DESTDIR)/$(SYSCONFDIR)/$$config; then \
-	    $(RM_F) $(DESTDIR)$(SYSCONFDIR)/$$config.new; \
-	    $(CP) etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/$$config.new; \
-	    $(CHMOD) $(PERM_RW) $(DESTDIR)$(SYSCONFDIR)/$$config.new; \
+	  if $(TEST_F) $(DESTDIR)/$(PREFIX)/share/examples/fusioninventory/$$config; then \
+	    $(RM_F) $(DESTDIR)$(PREFIX)/share/examples/fusioninventory/$$config.new; \
+	    $(CP) etc/agent.cfg $(DESTDIR)$(PREFIX)/share/examples/fusioninventory/$$config.new; \
+	    $(CHMOD) $(PERM_RW) $(DESTDIR)$(PREFIX)/share/examples/fusioninventory/$$config.new; \
 	  else \
-	    $(CP) etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/$$config; \
-	    $(CHMOD) $(PERM_RW) $(DESTDIR)$(SYSCONFDIR)/$$config; \
+	    $(CP) etc/agent.cfg $(DESTDIR)$(PREFIX)/share/examples/fusioninventory/$$config; \
+	    $(CHMOD) $(PERM_RW) $(DESTDIR)$(PREFIX)/share/examples/fusioninventory/$$config; \
 	  fi; \
 	done
 	$(ABSPERLRUN) -pi \
