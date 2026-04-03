$NetBSD: patch-luatexdir_luaffi_test__includes.sh,v 1.1 2026/04/03 03:42:35 markd Exp $

test fix

--- luatexdir/luaffi/test_includes.sh.orig	2026-02-02 21:53:30.000000000 +0000
+++ luatexdir/luaffi/test_includes.sh
@@ -5,7 +5,7 @@ mkdir -p test_includes
 for f in /usr/include/*.h
 do
   gcc -E -c "${f}" > tmp 2>/dev/null
-  if [ $? == 0 ]
+  if [ $? = 0 ]
   then
     echo "${f}";
     lua -e '
