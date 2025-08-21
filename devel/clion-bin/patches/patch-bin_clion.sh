$NetBSD: patch-bin_clion.sh,v 1.3 2025/08/21 00:25:45 schmonz Exp $

Run under pkgsrc-determined Java.

--- bin/clion.sh.orig	2025-08-19 12:21:33.322356497 +0000
+++ bin/clion.sh
@@ -47,7 +47,7 @@ CONFIG_HOME="${XDG_CONFIG_HOME:-${HOME}/
 # Locate a JRE installation directory command -v will be used to run the IDE.
 # Try (in order): $CLION_JDK, .../clion.jdk, .../jbr, $JDK_HOME, $JAVA_HOME, "java" in $PATH.
 # ---------------------------------------------------------------------
-JRE=""
+JRE="@PKG_JAVA_HOME@"
 
 # shellcheck disable=SC2154
 if [ -n "$CLION_JDK" ] && [ -x "$CLION_JDK/bin/java" ]; then
