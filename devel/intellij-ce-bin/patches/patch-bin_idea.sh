$NetBSD: patch-bin_idea.sh,v 1.2 2022/02/15 21:21:24 rillig Exp $

Add a few JVM options to make it work in a common case.

--- bin/idea.sh.orig	2022-01-28 04:01:00.000000000 +0000
+++ bin/idea.sh
@@ -49,6 +49,7 @@ CONFIG_HOME="${XDG_CONFIG_HOME:-${HOME}/
 # ---------------------------------------------------------------------
 JRE=""
 
+IDEA_JDK=@PKG_JAVA_HOME@
 # shellcheck disable=SC2154
 if [ -n "$IDEA_JDK" ] && [ -x "$IDEA_JDK/bin/java" ]; then
   JRE="$IDEA_JDK"
@@ -148,6 +149,9 @@ fi
 IFS="$(printf '\n\t')"
 # shellcheck disable=SC2086
 "$JAVA_BIN" \
+  -Xmx4096 -Xms4096 \
+  -XX:-UseCompressedClassPointers \
+  -XX:-UseCompressedOops \
   -classpath "$CLASSPATH" \
   ${VM_OPTIONS} \
   "-XX:ErrorFile=$HOME/java_error_in_idea_%p.log" \
