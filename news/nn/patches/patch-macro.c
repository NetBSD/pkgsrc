$NetBSD: patch-macro.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- macro.c.orig	2026-05-16 21:27:37.262483369 +0000
+++ macro.c
@@ -7,7 +7,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "db.h"
@@ -169,7 +169,7 @@ parse_word(char *w)
     register struct macro *m1;
 
     if (m && m->m_type == M_COMMAND && m->m_int == (GETC_COMMAND | K_MACRO)) {
-	if (isdigit(*w)) {
+	if (ISDIGIT(*w)) {
 	    m->m_int |= atoi(w);
 	    goto ok;
 	}
@@ -327,11 +327,11 @@ parse_line(char *lp)
 		lp++;
 	    while (*lp && *lp != '\'');
 	} else
-	    while (*lp && !isspace(*lp))
+	    while (*lp && !ISSPACE(*lp))
 		lp++;
 	if (*lp) {
 	    *lp++ = NUL;
-	    while (*lp && isspace(*lp))
+	    while (*lp && ISSPACE(*lp))
 		lp++;
 	}
 	if (parse_word(word))
@@ -391,7 +391,7 @@ m_define(char *id, FILE * f)
     initial_set_commands = (cur_m == NMACRO);
 
     while (fgets_multi(line, 1024, f)) {
-	for (lp = line; *lp && isspace(*lp); lp++);
+	for (lp = line; *lp && ISSPACE(*lp); lp++);
 	if (*lp == NUL)
 	    continue;
 	if (*lp == ')' || strncmp(lp, "end", 3) == 0)
