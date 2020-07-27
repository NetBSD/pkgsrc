$NetBSD: patch-conf_cassandra-env.sh,v 1.1 2020/07/27 17:21:40 rillig Exp $

Fix hard-coded path to /var.

--- conf/cassandra-env.sh.orig	2018-02-12 17:50:00.000000000 +0000
+++ conf/cassandra-env.sh
@@ -258,7 +258,7 @@ JVM_OPTS="$JVM_OPTS -XX:+UseGCLogFileRot
 JVM_OPTS="$JVM_OPTS -XX:NumberOfGCLogFiles=10"
 JVM_OPTS="$JVM_OPTS -XX:GCLogFileSize=10M"
 # if using version before JDK 6u34 or 7u2 use this instead of log rotation
-# JVM_OPTS="$JVM_OPTS -Xloggc:/var/log/cassandra/gc-`date +%s`.log"
+# JVM_OPTS="$JVM_OPTS -Xloggc:@VARBASE@/log/cassandra/gc-`date +%s`.log"
 
 # uncomment to have Cassandra JVM listen for remote debuggers/profilers on port 1414
 # JVM_OPTS="$JVM_OPTS -agentlib:jdwp=transport=dt_socket,server=y,suspend=n,address=1414"
