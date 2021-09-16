$NetBSD: patch-bin_clion.sh,v 1.2 2021/09/16 20:43:36 wiz Exp $

Add JVM options for a typical NetBSD setup.

--- bin/clion.sh.orig	2021-07-27 09:48:41.000000000 +0000
+++ bin/clion.sh
@@ -21,10 +21,10 @@ message()
   fi
 }
 
-if [ -z "$(command -v uname)" ] || [ -z "$(command -v realpath)" ] || [ -z "$(command -v dirname)" ] || [ -z "$(command -v cat)" ] || \
+if [ -z "$(command -v uname)" ] || [ -z "$(command -v dirname)" ] || [ -z "$(command -v cat)" ] || \
    [ -z "$(command -v egrep)" ]; then
   TOOLS_MSG="Required tools are missing:"
-  for tool in uname realpath egrep dirname cat ; do
+  for tool in uname egrep dirname cat ; do
      test -z "$(command -v $tool)" && TOOLS_MSG="$TOOLS_MSG $tool"
   done
   message "$TOOLS_MSG (SHELL=$SHELL PATH=$PATH)"
@@ -35,11 +35,12 @@ fi
 GREP_OPTIONS=''
 OS_TYPE=$(uname -s)
 OS_ARCH=$(uname -m)
+CLION_JDK=@PKG_JAVA_HOME@
 
 # ---------------------------------------------------------------------
 # Ensure $IDE_HOME points to the directory where the IDE is installed.
 # ---------------------------------------------------------------------
-IDE_BIN_HOME=$(dirname "$(realpath "$0")")
+IDE_BIN_HOME=$(dirname "$0")
 IDE_HOME=$(dirname "${IDE_BIN_HOME}")
 CONFIG_HOME="${XDG_CONFIG_HOME:-${HOME}/.config}"
 
