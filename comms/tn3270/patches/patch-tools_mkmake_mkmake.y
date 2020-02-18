$NetBSD: patch-tools_mkmake_mkmake.y,v 1.3 2020/02/18 16:47:20 joerg Exp $

- use standard headers
- avoid symbol name collision on OpenBSD where clock() from time.h leaks in
- YYDEBUG is always defined in newer byacc versions, so check for non-0
  value instead

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
@@ -957,7 +962,7 @@ yylex()
 			    return token_type(buffer); \
 			}
 #define	save(c)	{ last_char = c; last_saved = 1; }
-#if	defined(YYDEBUG)
+#if	YYDEBUG - 0
 #define	Return(y,c)	if (yydebug) { \
 			    printf("[%d]", c); \
 			    fflush(stdout); \
@@ -1096,12 +1101,14 @@ do_dump()
     string_t *string;
     same_t *same, *same2;
 
+#if YYDEBUG - 0
     if (yydebug > 1) {
 	printf("strings...\n");
 	for (string = strings; string; string = string->next) {
 	    printf("\t%s\n", string->string);
 	}
     }
+#endif
 
     printf("# variables...\n");
     for (visit(variables, same); !visited(same); visit_next(same)) {
