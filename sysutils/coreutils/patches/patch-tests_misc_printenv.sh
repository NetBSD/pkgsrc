$NetBSD: patch-tests_misc_printenv.sh,v 1.1 2026/09/25 07:14:32 wiz Exp $

env,printenv: only quote when outputting to terminals
To support albeit non-robust but existing use cases like:

  env | grep SPARK_JAVA_OPT_ | sort -t_ -k4 -n |
   sed 's/[^=]*=\(.*\)/\1/g' > java_opts.txt
  readarray -t SPARK_EXECUTOR_JAVA_OPTS < java_opts.txt
  ...
  CMD=("${JAVA_HOME}/bin/java" "${SPARK_EXECUTOR_JAVA_OPTS[@]}" ...)

https://github.com/coreutils/coreutils/commit/782a1e5bc2090212273bb731dceee2cc2a071e54

--- tests/misc/printenv.sh.orig	2026-09-11 07:23:57.000000000 +0000
+++ tests/misc/printenv.sh
@@ -80,48 +80,16 @@ compare /dev/null out || fail=1
 returns_ 1 env a=b=c printenv a=b > out || fail=1
 compare /dev/null out || fail=1
 
-# QUOTING_STYLE affects redirected output.
-cat <<\EOF >exp-noargs-literal || framework_failure_
-a b=c d
-EOF
-cat <<\EOF >exp-arg-literal || framework_failure_
-c d
-EOF
-cat <<\EOF >exp-args-literal || framework_failure_
-c d
-c d
-EOF
-cat <<\EOF >exp-noargs-shell || framework_failure_
-'a b'='c d'
-EOF
-cp exp-arg-literal exp-arg-shell &&
-cp exp-args-literal exp-args-shell || framework_failure_
-for t in noargs arg args; do
-  tr "'" '"' <exp-$t-shell >exp-$t-c || framework_failure_
-done
-for qs in literal shell c; do
+# QUOTING_STYLE does not affect redirected output.
+printf '%s\n' 'a b=c d' > exp || framework_failure_
+for qs in literal shell-always invalid; do
   env -i PATH="$PATH" QUOTING_STYLE=$qs 'a b'='c d' \
     printenv >out-t 2>err || fail=1
   grep -vE '^["'"'"']?'\
 '(__CF_USER_TEXT_ENCODING|QUOTING_STYLE|(LD_ORIGIN_)?PATH)["'"'"']?=' \
     out-t >out || framework_failure_
-  compare exp-noargs-$qs out || fail=1
+  compare exp out || fail=1
   compare /dev/null err || fail=1
-  env -i PATH="$PATH" QUOTING_STYLE=$qs 'a b'='c d' \
-    printenv 'a b' >out 2>err || fail=1
-  compare exp-arg-$qs out || fail=1
-  compare /dev/null err || fail=1
-  env -i PATH="$PATH" QUOTING_STYLE=$qs 'a b'='c d' \
-    printenv 'a b' 'a b' >out 2>err || fail=1
-  compare exp-args-$qs out || fail=1
-  compare /dev/null err || fail=1
 done
-
-# Check the behavior with an invalid value for QUOTING_STYLE.
-printf 'printenv: ignoring invalid value of environment variable %s\n' \
-  "QUOTING_STYLE: 'invalid'" >exp || framework_failure_
-env QUOTING_STYLE=invalid printenv >out 2>err || fail=1
-grep '^QUOTING_STYLE=invalid$' out || fail=1
-compare exp err || fail=1
 
 Exit $fail
