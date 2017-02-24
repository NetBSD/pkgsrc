$NetBSD: patch-tools_start__slon.sh,v 1.1 2017/02/24 22:07:34 adam Exp $

Portability fix.

--- tools/start_slon.sh.orig	2011-10-11 20:20:52.000000000 +0000
+++ tools/start_slon.sh
@@ -16,7 +16,7 @@ test -r "$SLON_CONF" || (echo "No slon c
 
 PID_LINE=`grep pid_file $SLON_CONF | cut -d "#" -f 1 | grep "^[[:space:]]*pid_file='.*'"`
 PID_FILE=`echo $PID_LINE | cut -d "=" -f 2 | cut -d "'" -f 2`
-if [ "x$PID_FILE" == "x" ]; then
+if [ "x$PID_FILE" = "x" ]; then
     echo "pid_file not found in slon conf file - $SLON_CONF"
     exit 1
 else
