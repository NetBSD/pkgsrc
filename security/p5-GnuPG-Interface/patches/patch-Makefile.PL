$NetBSD: patch-Makefile.PL,v 1.2 2020/06/08 14:18:15 wiz Exp $

pkgsrc takes care the right version is installed.

--- Makefile.PL.orig	2020-05-13 19:57:03.000000000 +0000
+++ Makefile.PL
@@ -8,9 +8,6 @@ system("which", "gpg");
 die "gpg (GnuPG) not found" if ( $? != 0 );
 
 my $output = `gpg --version`;
-die "Can't determine gpg version"
-    unless $output =~ /^gpg \(GnuPG.*?\) (\d+\.\d+)/;
-die "gpg (GnuPG) 1.4 or later is required" unless $1 >= 1.4;
 
 
 author 'BPS';
