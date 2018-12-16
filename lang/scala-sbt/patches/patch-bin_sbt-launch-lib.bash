$NetBSD: patch-bin_sbt-launch-lib.bash,v 1.1 2018/12/16 09:54:41 ryoon Exp $

* Use pkgsrc Java

--- bin/sbt-launch-lib.bash.orig	2018-11-30 20:39:42.000000000 +0000
+++ bin/sbt-launch-lib.bash
@@ -10,7 +10,7 @@ declare -a residual_args
 declare -a java_args
 declare -a scalac_args
 declare -a sbt_commands
-declare java_cmd=java
+declare java_cmd=@JAVA_BINPREFIX@-java
 declare java_version
 declare init_sbt_version="1.2.7"
 declare sbt_default_mem=1024
@@ -27,7 +27,7 @@ while [ -h "$SCRIPT" ] ; do
   fi
 done
 declare -r sbt_bin_dir="$(dirname "$SCRIPT")"
-declare -r sbt_home="$(dirname "$sbt_bin_dir")"
+declare -r sbt_home="@PREFIX@/share/sbt"
 
 echoerr () {
   echo 1>&2 "$@"
