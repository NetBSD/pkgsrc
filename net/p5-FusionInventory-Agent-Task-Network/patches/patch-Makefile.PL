$NetBSD: patch-Makefile.PL,v 1.2 2016/04/21 12:08:55 jperkin Exp $

Fix man pages path

--- Makefile.PL.orig	2013-01-14 13:47:29.000000000 +0100
+++ Makefile.PL	2013-01-14 13:47:45.000000000 +0100
@@ -83,12 +83,12 @@
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
         DATADIR              => '$(PREFIX)/share/fusioninventory',
         FULLPERLRUN          => '$(FULLPERL) -I$(DATADIR)/lib'
     );
