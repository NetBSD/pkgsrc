$NetBSD: patch-jvb_resources_jvb.sh,v 1.1 2023/01/03 10:29:35 khorben Exp $

Fix quoting for additional command-line parameters

--- jvb/resources/jvb.sh.orig	2023-01-03 07:37:20.457556984 +0000
+++ jvb/resources/jvb.sh
@@ -19,4 +19,4 @@ fi
 if [ -z "$VIDEOBRIDGE_MAX_MEMORY" ]; then VIDEOBRIDGE_MAX_MEMORY=3072m; fi
 if [ -z "$VIDEOBRIDGE_GC_TYPE" ]; then VIDEOBRIDGE_GC_TYPE=G1GC; fi
 
-exec java -Xmx$VIDEOBRIDGE_MAX_MEMORY $VIDEOBRIDGE_DEBUG_OPTIONS -XX:+Use$VIDEOBRIDGE_GC_TYPE -XX:+HeapDumpOnOutOfMemoryError -XX:HeapDumpPath=/tmp -Djdk.tls.ephemeralDHKeySize=2048 $LOGGING_CONFIG_PARAM $JAVA_SYS_PROPS -cp $cp $mainClass $@
+exec java -Xmx$VIDEOBRIDGE_MAX_MEMORY $VIDEOBRIDGE_DEBUG_OPTIONS -XX:+Use$VIDEOBRIDGE_GC_TYPE -XX:+HeapDumpOnOutOfMemoryError -XX:HeapDumpPath=/tmp -Djdk.tls.ephemeralDHKeySize=2048 $LOGGING_CONFIG_PARAM $JAVA_SYS_PROPS -cp $cp $mainClass "$@"
