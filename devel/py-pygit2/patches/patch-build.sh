$NetBSD: patch-build.sh,v 1.2 2023/04/26 12:38:26 adam Exp $

Fix unportable test(1) operator.

--- build.sh.orig	2023-03-22 14:38:33.000000000 +0000
+++ build.sh
@@ -269,5 +269,5 @@ if [ "$1" = "stubtest" ]; then
     shift
     $PREFIX/bin/pip install mypy
     PYTHONPATH=. $PREFIX/bin/stubtest --mypy-config-file mypy-stubtest.ini pygit2._pygit2
-    [ $? == 0 ] && echo "stubtest OK"
+    [ $? = 0 ] && echo "stubtest OK"
 fi
