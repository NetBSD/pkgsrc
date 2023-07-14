$NetBSD: patch-bin_pycharm.sh,v 1.2 2023/07/14 12:36:13 hauke Exp $

Run IDE with pkgsrc choice of JVM

--- bin/pycharm.sh.orig	2022-07-20 20:50:22.000000000 +0000
+++ bin/pycharm.sh
@@ -49,6 +49,9 @@ CONFIG_HOME="${XDG_CONFIG_HOME:-${HOME}/
 # ---------------------------------------------------------------------
 JRE=""
 
+# pkgsrc choice
+PYCHARM_JDK="@PKG_JAVA_HOME@"
+
 # shellcheck disable=SC2154
 if [ -n "$PYCHARM_JDK" ] && [ -x "$PYCHARM_JDK/bin/java" ]; then
   JRE="$PYCHARM_JDK"
