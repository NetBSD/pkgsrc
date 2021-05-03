$NetBSD: patch-Makefile.PL,v 1.4 2021/05/03 17:12:23 bouyer Exp $

Fix man page path.
Install config into examples/ directory.

--- Makefile.PL.orig	2020-09-28 11:55:10.000000000 +0200
+++ Makefile.PL	2021-05-03 18:36:36.841916298 +0200
@@ -174,12 +174,12 @@
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
@@ -240,18 +240,12 @@
     $install .= <<'EOF';
 
 config_install : pure_install
-	$(MKPATH) $(DESTDIR)$(SYSCONFDIR)
-	$(NOECHO) $(CHMOD) $(PERM_DIR) $(DESTDIR)$(SYSCONFDIR)
-	for config in agent.cfg $(shell cd etc; echo *-plugin.cfg ); \
+	$(MKPATH) $(DESTDIR)$(PREFIX)/share/examples/fusioninventory
+	$(NOECHO) $(CHMOD) $(PERM_DIR) $(DESTDIR)$(PREFIX)/share/examples/fusioninventory
+	for config in agent.cfg inventory-server-plugin.cfg proxy-server-plugin.cfg proxy2-server-plugin.cfg server-test-plugin.cfg ssl-server-plugin.cfg; \
 	do \
-	  if $(TEST_F) $(DESTDIR)$(SYSCONFDIR)/$$config; then \
-	    $(RM_F) $(DESTDIR)$(SYSCONFDIR)/$$config.new; \
-	    $(CP) etc/$$config $(DESTDIR)$(SYSCONFDIR)/$$config.new; \
-	    $(CHMOD) $(PERM_RW) $(DESTDIR)$(SYSCONFDIR)/$$config.new; \
-	  else \
-	    $(CP) etc/$$config $(DESTDIR)$(SYSCONFDIR)/$$config; \
-	    $(CHMOD) $(PERM_RW) $(DESTDIR)$(SYSCONFDIR)/$$config; \
-	  fi; \
+	  $(CP) etc/$$config $(DESTDIR)$(PREFIX)/share/examples/fusioninventory/$$config; \
+	  $(CHMOD) $(PERM_RW) $(DESTDIR)$(PREFIX)/share/examples/fusioninventory/$$config; \
 	done
 	$(ABSPERLRUN) -pi \
 	    -e "s|=> undef, # SYSCONFDIR.*|=> '$(SYSCONFDIR)',|;" \
