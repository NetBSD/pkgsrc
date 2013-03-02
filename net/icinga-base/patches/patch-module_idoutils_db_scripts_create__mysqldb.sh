$NetBSD: patch-module_idoutils_db_scripts_create__mysqldb.sh,v 1.1 2013/03/02 04:08:27 ryoon Exp $

--- module/idoutils/db/scripts/create_mysqldb.sh.orig	2013-01-13 22:18:37.000000000 +0000
+++ module/idoutils/db/scripts/create_mysqldb.sh
@@ -52,14 +52,14 @@ select now();
  \q
 EOS2
 
-if [ $? == 0 ]; then
+if [ $? = 0 ]; then
 				echo "Check icinga schema version with DB User $DBUSER..."
         mysql $DB -u $DBUSER -p$DBPASS -h $DBHOST -s <<EOS3
 select "DB-Version",version from icinga_dbversion where name='idoutils';
 \q
 EOS3
 
-        if [ $? == 0 ]; then
+        if [ $? = 0 ]; then
                 echo "Database ready"
                 RET=0
         else
