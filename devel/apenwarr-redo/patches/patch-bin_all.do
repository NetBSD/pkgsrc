$NetBSD: patch-bin_all.do,v 1.1 2019/09/02 18:20:50 schmonz Exp $

Add info to help debug bulk build failures.

--- bin/all.do.orig	2019-01-02 19:49:33.000000000 +0000
+++ bin/all.do
@@ -1,3 +1,6 @@
 exec >&2
 redo-ifchange ../redo/version/all ../redo/py list redo-sh
+echo "pkgsrc: PATH = $PATH"
+echo "pkgsrc: xargs = $(type xargs)"
+echo "pkgsrc: list = $(cat list)"
 xargs redo-ifchange <list
