$NetBSD: patch-resources_jicofo.sh,v 1.1 2023/01/03 10:27:40 khorben Exp $

Fix quoting for additional command-line parameters

--- resources/jicofo.sh.orig	2021-11-10 19:11:46.070570369 +0000
+++ resources/jicofo.sh
@@ -29,4 +29,4 @@ fi
 
 if [ -z "$JICOFO_MAX_MEMORY" ]; then JICOFO_MAX_MEMORY=3072m; fi
 
-exec java -Xmx$JICOFO_MAX_MEMORY -XX:+HeapDumpOnOutOfMemoryError -XX:HeapDumpPath=/tmp -Djdk.tls.ephemeralDHKeySize=2048 $LOGGING_CONFIG_PARAM $JAVA_SYS_PROPS -cp $cp $mainClass $@
+exec java -Xmx$JICOFO_MAX_MEMORY -XX:+HeapDumpOnOutOfMemoryError -XX:HeapDumpPath=/tmp -Djdk.tls.ephemeralDHKeySize=2048 $LOGGING_CONFIG_PARAM $JAVA_SYS_PROPS -cp $cp $mainClass "$@"
