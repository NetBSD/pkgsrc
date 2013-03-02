$NetBSD: patch-module_idoutils_db_scripts_create__pgsqldb.sh,v 1.1 2013/03/02 04:08:27 ryoon Exp $

--- module/idoutils/db/scripts/create_pgsqldb.sh.orig	2013-01-13 22:18:37.000000000 +0000
+++ module/idoutils/db/scripts/create_pgsqldb.sh
@@ -36,7 +36,7 @@ psql postgres >create_pgsqldb.log <<EOS1
  CREATE USER $DBUSER WITH PASSWORD '$DBPASS';
  \q
 EOS1
-if [ $? == 0 ]; then
+if [ $? = 0 ]; then
 				createlang plpgsql icinga;
 				echo "Create icinga objects..."
         PGPASSWORD=$DBPASS
@@ -51,7 +51,7 @@ select version as DBVersion from icinga_
 select now();
 \q
 EOS2
-        if [ $? == 0 ]; then
+        if [ $? = 0 ]; then
                 echo "Database ready"
         else
                 echo "Database creation failed"
@@ -75,4 +75,4 @@ echo "Dont forget to modify pg_hba.conf 
 rm -rf /tmp/pgsql
 echo "Logfiles:"
 ls -l *pgsql*.log
-exit $RET
\ No newline at end of file
+exit $RET
