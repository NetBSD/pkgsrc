$NetBSD: patch-lex.l,v 1.2 2015/04/16 23:05:07 ryoon Exp $

'struct tm' has no member named 'tm_zone' on SunOS
--- lex.l.orig	2015-01-18 10:11:55.000000000 +0000
+++ lex.l
@@ -313,7 +313,7 @@ lex_date(const cvs_number* const n, yysc
     tm.tm_min = n->n[4];
     tm.tm_sec = n->n[5];
     tm.tm_isdst = 0;
-#ifndef __CYGWIN__
+#if !defined(__CYGWIN__) && !defined(__sun)
     tm.tm_zone = 0;
 #endif
     d = mktime(&tm);
