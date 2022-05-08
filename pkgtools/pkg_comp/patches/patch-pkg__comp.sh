$NetBSD: patch-pkg__comp.sh,v 1.1 2022/05/08 20:26:52 schmonz Exp $

Avoid finding pkgsrc-installed bash, as it won't be in the sandbox.

--- pkg_comp.sh.orig	2019-01-12 10:54:23.000000000 +0000
+++ pkg_comp.sh
@@ -181,7 +181,8 @@ setup_bootstrap() {
         local dash_echo_test="$("${bootstrap_sh}" -c 'echo "\\100"')"
         if [ "$(uname -s)" != GNUkFreeBSD -a "${dash_echo_test}" = @ ]; then
             local bash
-            bash="$(which bash)"
+            # Avoid finding pkgsrc-installed bash, as it won't be in the sandbox
+            bash="$(PATH="$(echo ${PATH} | tr ':' '\n' | grep -v '^@PREFIX@/' | tr '\n' ':')" which bash)"
             if [ ${?} -eq 0 ]; then
                 bootstrap_sh="${bash}"
             else
