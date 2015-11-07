$NetBSD: patch-tools_mkmake_mkmake.y,v 1.2 2015/11/07 23:47:52 dholland Exp $

- use standard headers
- avoid symbol name collision on OpenBSD where clock() from time.h leaks in

--- tools/mkmake/mkmake.y.orig	2010-01-17 18:00:07.000000000 +0000
+++ tools/mkmake/mkmake.y
@@ -40,6 +40,7 @@ __RCSID("$NetBSD: mkmake.y,v 1.1.1.1 201
 #endif
 #endif /* not lint */
 #endif
+#include <stdlib.h>
 
 typedef struct string {
     int
@@ -308,6 +309,10 @@ white_space : WHITE_SPACE
 #include <string.h>
 #include <ctype.h>
 
+/* work around symbol collision on OpenBSD */
+#undef clock
+#define clock Clock
+
 /* mkmake.y */
 void yyerror(char *);
 void assign(same_t *, same_t *);
