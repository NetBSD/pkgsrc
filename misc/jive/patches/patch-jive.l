$NetBSD: patch-jive.l,v 1.1 2011/12/22 00:27:12 joerg Exp $

Newer flex no longer defines YY_PROTO.

--- jive.l.orig	2011-12-21 23:54:53.000000000 +0000
+++ jive.l
@@ -8,7 +8,7 @@ BW [ 	]
 EW [ 	.,;!?]
 
 %{
-#define YY_DECL char * yylex YY_PROTO(( void ))
+#define YY_DECL char * yylex(void)
 	char buf[128];
 %}
 
