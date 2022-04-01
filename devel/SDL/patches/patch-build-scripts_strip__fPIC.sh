$NetBSD: patch-build-scripts_strip__fPIC.sh,v 1.1.2.2 2022/04/01 19:05:15 bsiegert Exp $

strip -pie for nasm

--- build-scripts/strip_fPIC.sh.orig	2012-01-19 06:30:05.000000000 +0000
+++ build-scripts/strip_fPIC.sh
@@ -8,6 +8,12 @@ while [ $# -gt 0 ]; do
         -fPIC)
             # Ignore -fPIC option
             ;;
+        -pie)
+            # Ignore -pie option for nasm
+            if echo "${command}" | grep -v "^ [^ ]*nasm " > /dev/null; then
+              command="$command $1"
+            fi
+            ;;
         -fno-common)
             # Ignore -fPIC and -DPIC options
             ;;
