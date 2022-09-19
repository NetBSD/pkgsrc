$NetBSD: patch-lib_mergelib.sh,v 1.1 2022/09/19 15:15:49 schmonz Exp $

Work around Xcode 14 errors linking libnullmailer.a into e.g.
protocols/smtp:

archive member '__.SYMDEF SORTED' is not mach-o or llvm bitcode file

(likewise for '__.SYMDEF')

--- lib/mergelib.sh.orig	2017-10-24 00:12:30.000000000 +0000
+++ lib/mergelib.sh
@@ -10,6 +10,7 @@ for input in "$@"; do
 	mkdir "$dir"
 	cd "$dir"
 	"${AR:-ar}" x ../../"$input"
+	rm -f "__.SYMDEF SORTED" "__.SYMDEF"
 	cd ..
 done
 "${AR:-ar}" rc ../"$archive" */*
