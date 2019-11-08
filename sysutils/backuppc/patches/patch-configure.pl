$NetBSD: patch-configure.pl,v 1.2 2019/11/08 17:11:12 tnn Exp $

Prevent previous installation from altering build results.

--- configure.pl.orig	2018-05-07 17:14:29.000000000 +0000
+++ configure.pl
@@ -266,7 +266,7 @@ EOF
 #
 my $ConfigDir = $opts{"config-dir"} || "/etc/BackupPC";
 my $ConfigPath = "";
-my $ConfigFileOK = 1;
+my $ConfigFileOK = 0;
 while ( 1 ) {
     if ( $ConfigFileOK && -f "$DestDir$ConfigDir/config.pl"
             && (!defined($opts{fhs}) || $opts{fhs}) && !defined($opts{"config-path"}) ) {
