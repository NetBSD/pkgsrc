$NetBSD: patch-Makefile.PL,v 1.1.1.1 2013/01/14 14:47:38 bouyer Exp $
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
+        INSTALLMAN1DIR       => '$(PREFIX)/man/man1',
+        INSTALLSITEMAN1DIR   => '$(PREFIX)/man/man1',
+        INSTALLVENDORMAN1DIR => '$(PREFIX)/man/man1',
+        INSTALLMAN3DIR       => '$(PREFIX)/man/man3',
+        INSTALLSITEMAN3DIR   => '$(PREFIX)/man/man3',
+        INSTALLVENDORMAN3DIR => '$(PREFIX)/man/man3',
         DATADIR              => '$(PREFIX)/share/fusioninventory',
         FULLPERLRUN          => '$(FULLPERL) -I$(DATADIR)/lib'
     );
