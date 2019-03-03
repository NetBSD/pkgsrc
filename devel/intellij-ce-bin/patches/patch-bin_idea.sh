$NetBSD: patch-bin_idea.sh,v 1.1 2019/03/03 16:34:27 youri Exp $

Add a few JVM options to make it work in a common case.

--- bin/idea.sh.orig	2019-02-26 12:34:54.000000000 +0000
+++ bin/idea.sh
@@ -21,6 +21,7 @@ message()
   fi
 }
 
+IDEA_JDK=@PKG_JAVA_HOME@
 UNAME=`which uname`
 GREP=`which egrep`
 GREP_OPTIONS=""
@@ -202,6 +203,9 @@ fi
 # ---------------------------------------------------------------------
 IFS="$(printf '\n\t')"
 "$JAVA_BIN" \
+  -Xmx4096 -Xms4096 \
+  -XX:-UseCompressedClassPointers \
+  -XX:-UseCompressedOops \
   -classpath "$CLASSPATH" \
   ${VM_OPTIONS} \
   "-XX:ErrorFile=$HOME/java_error_in_IDEA_%p.log" \
