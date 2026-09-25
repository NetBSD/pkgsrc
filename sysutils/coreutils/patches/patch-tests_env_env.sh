$NetBSD: patch-tests_env_env.sh,v 1.1 2026/09/25 07:14:32 wiz Exp $

env,printenv: only quote when outputting to terminals
To support albeit non-robust but existing use cases like:

  env | grep SPARK_JAVA_OPT_ | sort -t_ -k4 -n |
   sed 's/[^=]*=\(.*\)/\1/g' > java_opts.txt
  readarray -t SPARK_EXECUTOR_JAVA_OPTS < java_opts.txt
  ...
  CMD=("${JAVA_HOME}/bin/java" "${SPARK_EXECUTOR_JAVA_OPTS[@]}" ...)

https://github.com/coreutils/coreutils/commit/782a1e5bc2090212273bb731dceee2cc2a071e54

--- tests/env/env.sh.orig	2026-09-10 13:23:26.000000000 +0000
+++ tests/env/env.sh
@@ -91,18 +91,14 @@ compare exp out || fail=1
 compare exp out || fail=1
 
 # env shouldn't care what encoding name or value is
-cat <<\EOF >exp || framework_failure_
-NON_UTF8_TEST=''$'\240'
-EOF
+printf 'NON_UTF8_TEST=\240\n' > exp || framework_failure_
 env $(printf 'NON_UTF8_TEST=\240') env > all || fail=1
 grep '^NON_UTF8_TEST' all | LC_ALL=C sort > out || framework_failure_
 compare exp out || fail=1
 
-cat <<\EOF >exp || framework_failure_
-'NON_UTF8_TEST'$'\240'=1
-EOF
+printf 'NON_UTF8_TEST\240=1\n' > exp || framework_failure_
 env $(printf 'NON_UTF8_TEST\240=1') env > all || fail=1
-grep "^'NON_UTF8_TEST" all | LC_ALL=C sort > out || framework_failure_
+grep "^NON_UTF8_TEST" all | LC_ALL=C sort > out || framework_failure_
 compare exp out || fail=1
 
 # PATH modifications affect exec.
@@ -193,29 +189,16 @@ done
 compare err_exp err || fail=1
 done
 
-# QUOTING_STYLE affects redirected output.
-cat <<\EOF >exp-noargs-literal || framework_failure_
-a b=c d
-EOF
-cat <<\EOF >exp-noargs-shell || framework_failure_
-'a b'='c d'
-EOF
-tr "'" '"' <exp-noargs-shell >exp-noargs-c || framework_failure_
-for qs in literal shell c; do
+# QUOTING_STYLE does not affect redirected output.
+printf '%s\n' 'a b=c d' > exp || framework_failure_
+for qs in literal shell-always invalid; do
   env -i PATH="$PATH" QUOTING_STYLE=$qs 'a b'='c d' \
     env >out-t 2>err || fail=1
   grep -vE '^["'"'"']?'\
 '(__CF_USER_TEXT_ENCODING|QUOTING_STYLE|(LD_ORIGIN_)?PATH)["'"'"']?=' \
     out-t >out || framework_failure_
-  compare exp-noargs-$qs out || fail=1
+  compare exp out || fail=1
   compare /dev/null err || fail=1
 done
-
-# Check the behavior with an invalid value for QUOTING_STYLE.
-printf 'env: ignoring invalid value of environment variable %s\n' \
-  "QUOTING_STYLE: 'invalid'" >exp || framework_failure_
-env QUOTING_STYLE=invalid env >out 2>err || fail=1
-grep '^QUOTING_STYLE=invalid$' out || fail=1
-compare exp err || fail=1
 
 Exit $fail
