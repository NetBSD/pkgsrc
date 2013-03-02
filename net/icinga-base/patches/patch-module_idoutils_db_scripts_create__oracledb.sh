$NetBSD: patch-module_idoutils_db_scripts_create__oracledb.sh,v 1.1 2013/03/02 04:08:27 ryoon Exp $

--- module/idoutils/db/scripts/create_oracledb.sh.orig	2013-01-13 22:18:37.000000000 +0000
+++ module/idoutils/db/scripts/create_oracledb.sh
@@ -67,7 +67,7 @@ connect sys/${SYSPASS}@${DB} as sysdba;
 EOS1
 RET=$?
 
-if [ $RET == 0 ]; then
+if [ $RET = 0 ]; then
 	 #create icinga schema objects using newly created user
    $SP /nolog <<EOS2
    --exit if connect errornous
@@ -81,7 +81,7 @@ connect ${DBUSER}/${DBPASS}@${DB}
 EOS2
 	RET=$?
 	#check if dbversion entered(last insert)
-	if [ $RET == 0 ]; then
+	if [ $RET = 0 ]; then
 		echo "Connecting now as $DBUSER on $DB and  check icinga schema version"
   	$SP /nolog <<EOS3
 connect ${DBUSER}/${DBPASS}@${DB}
@@ -92,7 +92,7 @@ select sysdate from dual;
 exit;
 EOS3
 
-     	if [ $? == 0 ]; then
+     	if [ $? = 0 ]; then
                 echo "Database ready"
                  RET=0
      	else
