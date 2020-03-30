$NetBSD: patch-redo_whichpython.do,v 1.1 2020/03/30 08:02:22 schmonz Exp $

Avoid finding pkg_alternatives(8) wrapper, or really any interpreter
besides the one explicitly depended on.

--- redo/whichpython.do.orig	2020-03-04 20:00:34.000000000 +0000
+++ redo/whichpython.do
@@ -1,5 +1,5 @@
 exec >&2
-for py in intentionally-missing python python3 python2 python2.7; do
+for py in intentionally-missing @PYTHONBIN@; do
 	echo "Trying: $py"
 	cmd=$(command -v "$py" || true)
 	out=$($cmd -c 'print("success")' 2>/dev/null) || true
