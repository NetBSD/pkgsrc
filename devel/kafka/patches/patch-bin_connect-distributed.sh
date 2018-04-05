$NetBSD: patch-bin_connect-distributed.sh,v 1.2 2018/04/05 08:46:37 fhajny Exp $

Paths.

--- bin/connect-distributed.sh.orig	2018-03-23 22:51:56.000000000 +0000
+++ bin/connect-distributed.sh
@@ -23,7 +23,7 @@ fi
 base_dir=$(dirname $0)
 
 if [ "x$KAFKA_LOG4J_OPTS" = "x" ]; then
-    export KAFKA_LOG4J_OPTS="-Dlog4j.configuration=file:$base_dir/../config/connect-log4j.properties"
+    export KAFKA_LOG4J_OPTS="-Dlog4j.configuration=file:@PKG_SYSCONFDIR@/connect-log4j.properties"
 fi
 
 if [ "x$KAFKA_HEAP_OPTS" = "x" ]; then
