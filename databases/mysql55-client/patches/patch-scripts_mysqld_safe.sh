$NetBSD: patch-scripts_mysqld_safe.sh,v 1.2 2012/10/01 15:54:40 adam Exp $

--- scripts/mysqld_safe.sh.orig	2011-03-31 13:36:18.000000000 +0000
+++ scripts/mysqld_safe.sh
@@ -718,7 +718,7 @@ fi
 # Alternatively, you can start mysqld with the "myisam-recover" option. See
 # the manual for details.
 #
-# echo "Checking tables in $DATADIR"
+# log_notice "Checking tables in $DATADIR"
 # $MY_BASEDIR_VERSION/bin/myisamchk --silent --force --fast --medium-check $DATADIR/*/*.MYI
 # $MY_BASEDIR_VERSION/bin/isamchk --silent --force $DATADIR/*/*.ISM
 
