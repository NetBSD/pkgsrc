$NetBSD: patch-bin_kafka-server-start.sh,v 1.1 2017/02/28 08:17:28 fhajny Exp $

Paths.

--- bin/kafka-server-start.sh.orig	2015-02-26 22:12:05.000000000 +0000
+++ bin/kafka-server-start.sh
@@ -22,7 +22,7 @@ fi
 base_dir=$(dirname $0)
 
 if [ "x$KAFKA_LOG4J_OPTS" = "x" ]; then
-    export KAFKA_LOG4J_OPTS="-Dlog4j.configuration=file:$base_dir/../config/log4j.properties"
+    export KAFKA_LOG4J_OPTS="-Dlog4j.configuration=file:@PKG_SYSCONFDIR@/log4j.properties"
 fi
 
 if [ "x$KAFKA_HEAP_OPTS" = "x" ]; then
