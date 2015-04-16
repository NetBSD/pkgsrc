$NetBSD: patch-scripts_mysqld_safe.sh,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- scripts/mysqld_safe.sh.orig	2015-02-13 12:07:04.000000000 +0000
+++ scripts/mysqld_safe.sh
@@ -820,7 +820,7 @@ fi
 # Alternatively, you can start mysqld with the "myisam-recover" option. See
 # the manual for details.
 #
-# echo "Checking tables in $DATADIR"
+# log_notice "Checking tables in $DATADIR"
 # $MY_BASEDIR_VERSION/bin/myisamchk --silent --force --fast --medium-check $DATADIR/*/*.MYI
 # $MY_BASEDIR_VERSION/bin/isamchk --silent --force $DATADIR/*/*.ISM
 
