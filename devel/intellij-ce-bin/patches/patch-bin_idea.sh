$NetBSD: patch-bin_idea.sh,v 1.5 2025/08/19 03:58:22 schmonz Exp $

Run under pkgsrc-determined Java.

--- bin/idea.sh.orig	2025-08-19 03:07:10.444759052 +0000
+++ bin/idea.sh
@@ -47,7 +47,7 @@ CONFIG_HOME="${XDG_CONFIG_HOME:-${HOME}/
 # Locate a JRE installation directory command -v will be used to run the IDE.
 # Try (in order): $IDEA_JDK, .../idea.jdk, .../jbr, $JDK_HOME, $JAVA_HOME, "java" in $PATH.
 # ---------------------------------------------------------------------
-JRE=""
+JRE="@PKG_JAVA_HOME@"
 
 # shellcheck disable=SC2154
 if [ -n "$IDEA_JDK" ] && [ -x "$IDEA_JDK/bin/java" ]; then
