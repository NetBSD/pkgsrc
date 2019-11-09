$NetBSD: patch-bin_all.do,v 1.2 2019/11/09 15:00:55 schmonz Exp $

Add info to help debug bulk build failures.

--- bin/all.do.orig	2019-07-24 07:27:12.000000000 +0000
+++ bin/all.do
@@ -1,3 +1,6 @@
 exec >&2
 redo-ifchange ../redo/version/all ../redo/py ../redo/sh list
+echo "pkgsrc: PATH = $PATH"
+echo "pkgsrc: xargs = $(type xargs)"
+echo "pkgsrc: list = $(cat list)"
 xargs redo-ifchange <list
