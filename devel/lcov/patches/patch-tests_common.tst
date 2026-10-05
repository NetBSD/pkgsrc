$NetBSD: patch-tests_common.tst,v 1.1 2026/10/05 19:39:02 wiz Exp $

Compatibility with NetBSD xargs.
https://github.com/linux-test-project/lcov/issues/553

--- tests/common.tst.orig	2026-10-05 19:22:58.094159094 +0000
+++ tests/common.tst
@@ -266,7 +266,7 @@ function check_tla_css()
     local rc=0
     local class
     for class in `find $dir -name '*.html' -print0 |
-                  xargs -0 --no-run-if-empty grep -h -o -E 'class="[^"]+"' |
+                  xargs -0 -r grep -h -o -E 'class="[^"]+"' |
                   sed -e 's/class="//' -e 's/"$//' | tr ' ' '\n' |
                   grep -E '^tla(Bg)?[A-Z]' | sort -u` ; do
         if ! grep -E -q "(^|[[:space:]])(td|span|a)\.$class([^A-Za-z0-9]|\$)" \
