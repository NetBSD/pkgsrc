$NetBSD: patch-configure.pl,v 1.1 2015/02/13 17:57:36 tnn Exp $

Prevent previous installation from altering build results.

--- configure.pl.orig	2015-01-12 00:19:53.000000000 +0000
+++ configure.pl
@@ -158,7 +158,7 @@ EOF
 # config file to get all the defaults.
 #
 my $ConfigPath = "";
-my $ConfigFileOK = 1;
+my $ConfigFileOK = 0;
 while ( 1 ) {
     if ( $ConfigFileOK && -f "/etc/BackupPC/config.pl"
             && (!defined($opts{fhs}) || $opts{fhs}) && !defined($opts{"config-path"}) ) {
