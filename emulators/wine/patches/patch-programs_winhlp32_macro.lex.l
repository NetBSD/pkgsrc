$NetBSD: patch-programs_winhlp32_macro.lex.l,v 1.1 2017/01/04 11:52:24 jperkin Exp $

Ensure the local yywrap is used.

--- programs/winhlp32/macro.lex.l.orig	2014-01-10 20:37:29.000000000 +0000
+++ programs/winhlp32/macro.lex.l
@@ -35,6 +35,7 @@
 #include "winhelp.h"
 
 #include "wine/debug.h"
+#undef yywrap
 
 WINE_DEFAULT_DEBUG_CHANNEL(winhelp);
 
