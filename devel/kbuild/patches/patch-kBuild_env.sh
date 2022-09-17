$NetBSD: patch-kBuild_env.sh,v 1.1 2022/09/17 16:13:10 he Exp $

On NetBSD, use `uname -p` to find the processor family.
`uname -m` might give e.g. "macppc", which is the "machine hardware".

--- kBuild/env.sh.orig	2017-11-22 20:15:12.000000000 +0000
+++ kBuild/env.sh
@@ -332,7 +332,11 @@ if test -z "$KBUILD_HOST_ARCH"; then
         KBUILD_HOST_ARCH=`isainfo | cut -f 1 -d ' '`
 
     else
-        KBUILD_HOST_ARCH=`uname -m`
+	if test $KBUILD_HOST = netbsd; then
+	    KBUILD_HOST_ARCH=`uname -p`
+	else
+            KBUILD_HOST_ARCH=`uname -m`
+	fi
     fi
     case "$KBUILD_HOST_ARCH" in
         x86_64|AMD64|amd64|k8|k8l|k9|k10)
