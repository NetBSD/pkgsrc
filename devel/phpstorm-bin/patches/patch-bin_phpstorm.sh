$NetBSD: patch-bin_phpstorm.sh,v 1.1 2019/03/03 19:06:31 youri Exp $

JVM options for typical NetBSD setups.

--- bin/phpstorm.sh.orig	2019-02-08 12:24:20.000000000 +0000
+++ bin/phpstorm.sh
@@ -21,6 +21,7 @@ message()
   fi
 }
 
+PHPSTORM_JDK=@PKG_JAVA_HOME@
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
   "-XX:ErrorFile=$HOME/java_error_in_PHPSTORM_%p.log" \
