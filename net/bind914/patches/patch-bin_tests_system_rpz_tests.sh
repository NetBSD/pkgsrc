$NetBSD: patch-bin_tests_system_rpz_tests.sh,v 1.1 2019/04/30 03:34:34 taca Exp $

* Avoid using "==" for argument of test(1).

--- bin/tests/system/rpz/tests.sh.orig	2019-04-06 20:09:59.000000000 +0000
+++ bin/tests/system/rpz/tests.sh
@@ -209,7 +209,7 @@ restart () {
 	fi
     fi
     rm -f ns$1/*.jnl
-    if [ "$2" == "rebuild-bl-rpz" ]; then
+    if [ "$2" = "rebuild-bl-rpz" ]; then
         if test -f ns$1/base.db; then
 	    for NM in ns$1/bl*.db; do
 	        cp -f ns$1/base.db $NM
