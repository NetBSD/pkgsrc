$NetBSD: patch-configure.pl,v 1.3 2020/10/20 22:16:16 tnn Exp $

Prevent previous installation from altering build results.

--- configure.pl.orig	2020-06-20 22:55:58.000000000 +0000
+++ configure.pl
@@ -250,7 +250,7 @@ EOF
 #
 my $ConfigDir    = $opts{"config-dir"} || "/etc/BackupPC";
 my $ConfigPath   = "";
-my $ConfigFileOK = 1;
+my $ConfigFileOK = 0;
 while ( 1 ) {
     if (   $ConfigFileOK
         && -f "$DestDir$ConfigDir/config.pl"
