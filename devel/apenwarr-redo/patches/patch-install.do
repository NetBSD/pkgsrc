$NetBSD: patch-install.do,v 1.1 2020/07/06 15:18:26 schmonz Exp $

Avoid CONFLICTS with other redo implementations.

--- install.do.orig	2020-06-15 06:20:02.000000000 +0000
+++ install.do
@@ -4,7 +4,7 @@ exec >&2
 : ${DESTDIR=NONE}
 : ${PREFIX:=/usr}
 : ${MANDIR:=$DESTDIR$PREFIX/share/man}
-: ${DOCDIR:=$DESTDIR$PREFIX/share/doc/redo}
+: ${DOCDIR:=$DESTDIR$PREFIX/share/doc/apenwarr-redo}
 : ${BINDIR:=$DESTDIR$PREFIX/bin}
 : ${LIBDIR:=$DESTDIR$PREFIX/lib/redo}
 
