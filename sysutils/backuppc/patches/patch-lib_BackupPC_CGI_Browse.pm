$NetBSD: patch-lib_BackupPC_CGI_Browse.pm,v 1.1 2016/02/28 03:44:05 tnn Exp $

defined(@array) is deprecated

--- lib/BackupPC/CGI/Browse.pm.orig	2015-01-12 00:19:53.000000000 +0000
+++ lib/BackupPC/CGI/Browse.pm
@@ -65,7 +65,7 @@ sub action
     #
     # default to the newest backup
     #
-    if ( !defined($In{num}) && defined(@Backups) && @Backups > 0 ) {
+    if ( !defined($In{num}) && @Backups && @Backups > 0 ) {
         $i = @Backups - 1;
         $num = $Backups[$i]{num};
     }
