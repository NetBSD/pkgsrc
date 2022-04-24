$NetBSD: patch-mfhdf_ncgen_ncgen.l,v 1.2 2022/04/24 21:50:48 tnn Exp $

Ensure the local yywrap is used.

--- mfhdf/ncgen/ncgen.l.orig	2020-03-03 17:40:50.000000000 +0000
+++ mfhdf/ncgen/ncgen.l
@@ -17,6 +17,7 @@ void expand_escapes();
 #include <ctype.h>
 #include <limits.h>
 #include "ncgentab.h"
+#undef yywrap
 %}
 
 escquote    \\\"
