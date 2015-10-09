$NetBSD: patch-bin_zkServer.sh,v 1.1 2015/10/09 13:59:56 fhajny Exp $

Use awk instead of grep/sed, and Bash echo for better portability.
--- bin/zkServer.sh.orig	2014-02-20 10:14:08.000000000 +0000
+++ bin/zkServer.sh
@@ -81,7 +81,7 @@ fi
 echo "Using config: $ZOOCFG" >&2
 
 if [ -z "$ZOOPIDFILE" ]; then
-    ZOO_DATADIR="$(grep "^[[:space:]]*dataDir" "$ZOOCFG" | sed -e 's/.*=//')"
+    ZOO_DATADIR="$(awk -F= '{ if ($1=="dataDir") print $2}' "$ZOOCFG")"
     if [ ! -d "$ZOO_DATADIR" ]; then
         mkdir -p "$ZOO_DATADIR"
     fi
@@ -110,7 +110,7 @@ start)
     -cp "$CLASSPATH" $JVMFLAGS $ZOOMAIN "$ZOOCFG" > "$_ZOO_DAEMON_OUT" 2>&1 < /dev/null &
     if [ $? -eq 0 ]
     then
-      if /bin/echo -n $! > "$ZOOPIDFILE"
+      if echo -n $! > "$ZOOPIDFILE"
       then
         sleep 1
         echo STARTED
@@ -161,12 +161,12 @@ restart)
     ;;
 status)
     # -q is necessary on some versions of linux where nc returns too quickly, and no stat result is output
-    clientPortAddress=`grep "^[[:space:]]*clientPortAddress[^[:alpha:]]" "$ZOOCFG" | sed -e 's/.*=//'`
+    clientPortAddress=`awk -F= '{if ($1=="clientPortAddress") print $2}' "$ZOOCFG"`
     if ! [ $clientPortAddress ]
     then
 	clientPortAddress="localhost"
     fi
-    clientPort=`grep "^[[:space:]]*clientPort[^[:alpha:]]" "$ZOOCFG" | sed -e 's/.*=//'`
+    clientPort=`awk -F= '{if ($1=="clientPort") print $2}' "$ZOOCFG"`
     STAT=`"$JAVA" "-Dzookeeper.log.dir=${ZOO_LOG_DIR}" "-Dzookeeper.root.logger=${ZOO_LOG4J_PROP}" \
              -cp "$CLASSPATH" $JVMFLAGS org.apache.zookeeper.client.FourLetterWordMain \
              $clientPortAddress $clientPort srvr 2> /dev/null    \
