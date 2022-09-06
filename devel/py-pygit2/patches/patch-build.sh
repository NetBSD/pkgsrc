$NetBSD: patch-build.sh,v 1.1 2022/09/06 09:26:28 wiz Exp $

Fix unportable test(1) operator.

--- build.sh.orig	2022-08-28 09:11:54.262747800 +0000
+++ build.sh
@@ -249,6 +249,6 @@ if [ "$1" = "stubtest" ]; then
     shift
     $PREFIX/bin/pip install mypy
     PYTHONPATH=. $PREFIX/bin/stubtest --mypy-config-file mypy-stubtest.ini pygit2._pygit2
-    [ $? == 0 ] && echo "stubtest OK"
+    [ $? = 0 ] && echo "stubtest OK"
 fi
 
