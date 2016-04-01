$NetBSD: patch-Makefile.PL,v 1.2 2016/04/01 12:07:30 jperkin Exp $
install sample config file in examples/ dir
Fix man pages path

--- Makefile.PL.orig	2012-11-13 14:17:02.000000000 +0100
+++ Makefile.PL	2013-01-14 13:20:36.000000000 +0100
@@ -72,11 +72,6 @@
 $MY::variables{DATADIR} =~ s/\$\(PREFIX\)/$MY::variables{PREFIX}/;
 $MY::variables{LOCALSTATEDIR} =~ s/\$\(PREFIX\)/$MY::variables{PREFIX}/;
 
-# look for already existing configuration file
-my $config_file_message = -f "$MY::variables{SYSCONFDIR}/agent.cfg" ?
-    "previous configuration file found, new one will be installed as agent.cfg.new" :
-    "no previous configuration file found, new one will be installed as agent.cfg";
-
 print <<EOF;
 
 Installation summary
@@ -86,7 +81,6 @@
 constant data installation directory: $MY::variables{DATADIR}
 variable data installation directory: $MY::variables{LOCALSTATEDIR}
 
-$config_file_message
 EOF
 
 package MY;
@@ -108,12 +102,12 @@
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
@@ -163,12 +157,8 @@
     $install .= <<'EOF';
 
 config_install :
-	install -d -m 755 $(DESTDIR)$(SYSCONFDIR)
-	if [ -f $(DESTDIR)/$(SYSCONFDIR)/agent.cfg ]; then \
-	    install -m 644 etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/agent.cfg.new; \
-	else \
-	    install -m 644 etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/agent.cfg; \
-	fi
+	install -d -m 755 $(DESTDIR)$(PREFIX)/share/examples/fusioninventory; \
+	install -m 644 etc/agent.cfg $(DESTDIR)$(PREFIX)/share/examples/fusioninventory/agent.cfg;
 
 data_install :
 	install -d -m 755 $(DESTDIR)$(DATADIR)
