$NetBSD: patch-lib_mergelib.sh,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Fix macOS "ld: multiple SYMDEF member files found in an archive".

--- lib/mergelib.sh.orig	2015-09-01 16:03:21.000000000 +0000
+++ lib/mergelib.sh
@@ -10,6 +10,7 @@ for input in "$@"; do
 	mkdir "$dir"
 	cd "$dir"
 	ar x ../../"$input"
+	rm -f __.SYMDEF*
 	cd ..
 done
 ar rc ../"$archive" */*
