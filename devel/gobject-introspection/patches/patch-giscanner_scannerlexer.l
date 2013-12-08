$NetBSD: patch-giscanner_scannerlexer.l,v 1.4 2013/12/08 13:28:27 prlw1 Exp $

Support __inline__ for older OSX.

--- giscanner/scannerlexer.l.orig	2013-07-10 16:13:23.000000000 +0000
+++ giscanner/scannerlexer.l
@@ -146,6 +146,7 @@ stringtext				([^\\\"])|(\\.)
 "__const"                               { return CONST; }
 "__extension__"                         { return EXTENSION; }
 "__inline"				{ return INLINE; }
+"__inline__"				{ return INLINE; }
 "__nonnull" 			        { if (!parse_ignored_macro()) REJECT; }
 "__signed__"				{ return SIGNED; }
 "__restrict"				{ return RESTRICT; }
