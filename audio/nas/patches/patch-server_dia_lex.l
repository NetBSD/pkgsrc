$NetBSD: patch-server_dia_lex.l,v 1.1 2017/01/04 10:34:10 jperkin Exp $

Ensure the local yywrap is used.

--- server/dia/lex.l.orig	2013-04-27 00:41:06.000000000 +0000
+++ server/dia/lex.l
@@ -5,6 +5,7 @@
 #include "auservertype.h"
 #include "gram.h"
 #include "nasconf.h"
+#undef yywrap
 
 int Lineno = 1; /* current line number of the scanner */
 
