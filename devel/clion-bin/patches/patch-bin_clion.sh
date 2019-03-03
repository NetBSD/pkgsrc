$NetBSD: patch-bin_clion.sh,v 1.1 2019/03/03 17:42:40 youri Exp $

Add JVM options for a typical NetBSD setup.

--- bin/clion.sh.orig	2019-01-31 19:23:02.000000000 +0000
+++ bin/clion.sh
@@ -21,6 +21,7 @@ message()
   fi
 }
 
+CLION_JDK=@PKG_JAVA_HOME@
 UNAME=`which uname`
 GREP=`which egrep`
 GREP_OPTIONS=""
@@ -201,6 +202,9 @@ fi
 # ---------------------------------------------------------------------
 IFS="$(printf '\n\t')"
 "$JAVA_BIN" \
+  -Xmx4096 -Xms4096 \
+  -XX:-UseCompressedClassPointers \
+  -XX:-UseCompressedOops \
   -classpath "$CLASSPATH" \
   ${VM_OPTIONS} \
   "-XX:ErrorFile=$HOME/java_error_in_CLION_%p.log" \
