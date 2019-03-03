$NetBSD: patch-bin_pycharm.sh,v 1.1 2019/03/03 18:02:47 youri Exp $

Add JVM options for a typical NetBSD setup.

--- bin/pycharm.sh.orig	2019-02-26 09:00:10.000000000 +0000
+++ bin/pycharm.sh
@@ -21,6 +21,7 @@ message()
   fi
 }
 
+PYCHARM_JDK=@PKG_JAVA_HOME@
 UNAME=`which uname`
 GREP=`which egrep`
 GREP_OPTIONS=""
@@ -202,6 +203,9 @@ fi
 IFS="$(printf '\n\t')"
 "$JAVA_BIN" \
   -classpath "$CLASSPATH" \
+  -Xmx4096 -Xms4096 \
+  -XX:-UseCompressedClassPointers \
+  -XX:-UseCompressedOops \
   ${VM_OPTIONS} \
   "-XX:ErrorFile=$HOME/java_error_in_PYCHARM_%p.log" \
   "-XX:HeapDumpPath=$HOME/java_error_in_PYCHARM.hprof" \
