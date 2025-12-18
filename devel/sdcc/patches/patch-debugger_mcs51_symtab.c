$NetBSD: patch-debugger_mcs51_symtab.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- debugger/mcs51/symtab.c.orig	2025-12-18 05:34:38.865493060 +0000
+++ debugger/mcs51/symtab.c
@@ -31,7 +31,7 @@ DEFSETFUNC(symWithRName);
 /*------------------------------------------------------------------*/
 /* getSize - returns size of a type chain in bits                   */
 /*------------------------------------------------------------------*/
-unsigned int   getSize ( link *p )
+unsigned int   getSize ( linkt_t *p )
 {
     /* if nothing return 0 */
     if ( ! p )
@@ -127,8 +127,8 @@ static char  *parseTypeInfo (symbol *sym
     /* bp now points to '}' ... go past it */
     s = ++bp;
     while (*s != ')') { /* till we reach the end */
-        link *type;
-        type = Safe_calloc(1,sizeof(link));
+        linkt_t *type;
+        type = Safe_calloc(1,sizeof(linkt_t));
         if (*s == ',') s++;
 
         /* is a declarator */
