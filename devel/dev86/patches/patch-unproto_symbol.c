$NetBSD: patch-unproto_symbol.c,v 1.1 2025/12/17 10:55:54 prlw1 Exp $

Fix build:
- conflicting types for built-in function 'malloc'
- implicit declaration of function 'strlen', 'strcmp' and 'hash'

--- unproto/symbol.c.orig	2014-03-14 04:33:19.000000000 +0000
+++ unproto/symbol.c
@@ -42,8 +42,8 @@ static char symbol_sccsid[] = "@(#) symb
 
 /* C library */
 
-extern char *strcpy();
-extern char *malloc();
+#include <stdlib.h>
+#include <string.h>
 
 /* Application-specific stuff */
 
@@ -51,6 +51,8 @@ extern char *malloc();
 #include "token.h"
 #include "symbol.h"
 
+int hash(register char *, unsigned); /* hash.c */
+
 #define	SYM_TABSIZE	20
 
 static struct symbol *sym_tab[SYM_TABSIZE] = {0,};
