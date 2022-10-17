$NetBSD: patch-gcc_c_c-typeck.c,v 1.1 2022/10/17 13:48:28 js Exp $

https://gcc.gnu.org/git/?p=gcc.git;a=commit;h=222dbebefbbc07f78e51d82ba605988ef57e5fc9

--- gcc/c/c-typeck.c.orig	2021-07-28 06:55:06.988283174 +0000
+++ gcc/c/c-typeck.c
@@ -11216,7 +11216,8 @@ c_finish_bc_stmt (location_t loc, tree l
 
   if (skip)
     return NULL_TREE;
-  else if (in_statement & IN_OBJC_FOREACH)
+  else if ((in_statement & IN_OBJC_FOREACH)
+          && !(is_break && (in_statement & IN_SWITCH_STMT)))
     {
       /* The foreach expander produces low-level code using gotos instead
 	 of a structured loop construct.  */
