$NetBSD: patch-bin_zkEnv.sh,v 1.1 2015/10/09 13:59:56 fhajny Exp $

Use a sane default prefix.
--- bin/zkEnv.sh.orig	2014-02-20 10:14:08.000000000 +0000
+++ bin/zkEnv.sh
@@ -23,7 +23,7 @@
 # or the conf directory that is
 # a sibling of this script's directory
 
-ZOOBINDIR="${ZOOBINDIR:-/usr/bin}"
+ZOOBINDIR="${ZOOBINDIR:-@PREFIX@}"
 ZOOKEEPER_PREFIX="${ZOOBINDIR}/.."
 
 if [ "x$ZOOCFGDIR" = "x" ]
@@ -112,4 +112,4 @@ then
     CLASSPATH=`cygpath -wp "$CLASSPATH"`
 fi
 
-#echo "CLASSPATH=$CLASSPATH"
\ No newline at end of file
+#echo "CLASSPATH=$CLASSPATH"
