$NetBSD: patch-bin_connect-distributed.sh,v 1.1 2017/02/28 08:17:28 fhajny Exp $

Paths.

--- bin/connect-distributed.sh.orig	2017-02-14 17:26:08.000000000 +0000
+++ bin/connect-distributed.sh
@@ -23,7 +23,7 @@ fi
 base_dir=$(dirname $0)
 
 if [ "x$KAFKA_LOG4J_OPTS" = "x" ]; then
-    export KAFKA_LOG4J_OPTS="-Dlog4j.configuration=file:$base_dir/../config/connect-log4j.properties"
+    export KAFKA_LOG4J_OPTS="-Dlog4j.configuration=file:@PKG_SYSCONFDIR@/connect-log4j.properties"
 fi
 
 EXTRA_ARGS=${EXTRA_ARGS-'-name connectDistributed'}
