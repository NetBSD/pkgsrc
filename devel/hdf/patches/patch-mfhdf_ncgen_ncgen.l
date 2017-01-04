$NetBSD: patch-mfhdf_ncgen_ncgen.l,v 1.1 2017/01/04 11:17:56 jperkin Exp $

Ensure the local yywrap is used.

--- mfhdf/ncgen/ncgen.l.orig	2003-12-10 21:15:54.000000000 +0000
+++ mfhdf/ncgen/ncgen.l
@@ -22,6 +22,7 @@ extern void yyerror();
 #include <ctype.h>
 #include <limits.h>
 #include "ncgentab.h"
+#undef yywrap
 %}
 
 escquote	\\\"
