$NetBSD: patch-bin_rubymine.sh,v 1.1 2019/03/03 18:45:06 youri Exp $

Add JVM options for typical NetBSD setups.

--- bin/rubymine.sh.orig	2019-02-25 13:36:02.000000000 +0000
+++ bin/rubymine.sh
@@ -21,6 +21,7 @@ message()
   fi
 }
 
+RUBYMINE_JDK=@PKG_JAVA_HOME@
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
   "-XX:ErrorFile=$HOME/java_error_in_RUBYMINE_%p.log" \
