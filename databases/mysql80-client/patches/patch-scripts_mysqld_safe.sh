$NetBSD: patch-scripts_mysqld_safe.sh,v 1.2 2022/11/02 17:02:10 jperkin Exp $

XXX: why are we doing this and why is it undocumented?

--- scripts/mysqld_safe.sh.orig	2022-09-13 16:15:16.000000000 +0000
+++ scripts/mysqld_safe.sh
@@ -852,7 +852,7 @@ fi
 # Alternatively, you can start mysqld with the "myisam-recover" option. See
 # the manual for details.
 #
-# echo "Checking tables in $DATADIR"
+# log_notice "Checking tables in $DATADIR"
 # $MY_BASEDIR_VERSION/bin/myisamchk --silent --force --fast --medium-check $DATADIR/*/*.MYI
 # $MY_BASEDIR_VERSION/bin/isamchk --silent --force $DATADIR/*/*.ISM
 
