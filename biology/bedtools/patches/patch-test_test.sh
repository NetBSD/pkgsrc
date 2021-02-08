$NetBSD: patch-test_test.sh,v 1.1 2021/02/08 01:49:25 bacon Exp $

# Warning for impending failed tests

--- test/test.sh.orig	2021-02-07 19:54:21.793084552 +0000
+++ test/test.sh
@@ -1,5 +1,13 @@
 set -e; # Alert user to any uncaught error
 
+if [ $(uname) = FreeBSD ] || [ $(uname) = NetBSD ]; then
+    if ! df | fgrep -q fdesc; then
+        echo "fdesc FS must be mounted in order to run $0."
+        echo "It uses bash process substitutions, e.g. <(ls)."
+        exit 1
+    fi
+fi
+
 ulimit -c unlimited
 
 STARTWD=$(pwd);
