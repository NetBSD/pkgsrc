$NetBSD: patch-build_make_gen_asm_deps.sh,v 1.1.2.2 2013/01/27 13:23:06 spz Exp $

Fix build problems under Mac OS X with Xcode 4.4 and newer. Patch
taken from here:

https://github.com/mxcl/homebrew/issues/12567#issuecomment-6434000

--- build/make/gen_asm_deps.sh.old	2012-05-09 00:14:00.000000000 +0100
+++ build/make/gen_asm_deps.sh	2013-01-24 10:02:54.000000000 +0000
@@ -42,7 +42,7 @@
 
 [ -n "$srcfile" ] || show_help
 sfx=${sfx:-asm}
-includes=$(LC_ALL=C egrep -i "include +\"?+[a-z0-9_/]+\.${sfx}" $srcfile |
+includes=$(LC_ALL=C egrep -i "include +\"[a-z0-9_/]+\.${sfx}" $srcfile |
            perl -p -e "s;.*?([a-z0-9_/]+.${sfx}).*;\1;")
 #" restore editor state
 for inc in ${includes}; do
