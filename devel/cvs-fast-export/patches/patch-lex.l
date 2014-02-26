$NetBSD: patch-lex.l,v 1.1 2014/02/26 10:29:27 wiedi Exp $

'struct tm' has no member named 'tm_zone' on SunOS
--- lex.l.orig	2013-05-22 00:56:11.000000000 +0000
+++ lex.l
@@ -188,7 +188,7 @@ lex_date (cvs_number *n)
 	tm.tm_min = n->n[4];
 	tm.tm_sec = n->n[5];
 	tm.tm_isdst = 0;
-	#ifndef __CYGWIN__
+	#if !defined(__CYGWIN__) && !defined(__sun)
 	tm.tm_zone = 0;
 	#endif
 	d = mktime (&tm);
