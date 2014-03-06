$NetBSD: patch-src_dirfns.cc,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- src/dirfns.cc.orig	2013-02-21 20:19:24.000000000 +0000
+++ src/dirfns.cc
@@ -555,9 +555,9 @@ them, or an empty cell array if no patte
 interpreted as filename globbing patterns (as they are used by Unix shells).\n\
 Within a pattern\n\
 @table @code\n\
-@itemx *\n\
+@item *\n\
 matches any string, including the null string,\n\
-@itemx ?\n\
+@item ?\n\
 matches any single character, and\n\
 \n\
 @item [@dots{}]\n\
