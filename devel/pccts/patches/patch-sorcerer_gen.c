$NetBSD: patch-sorcerer_gen.c,v 1.1 2025/10/11 21:14:32 mrg Exp $

Add missing types/prototypes for GCC 14.


--- sorcerer/gen.c.orig	2001-06-03 10:37:29.000000000 -0700
+++ sorcerer/gen.c	2025-10-11 14:09:44.968770301 -0700
@@ -56,7 +56,7 @@
 #include "sym.h"
 #include "proto.h"
 
-static outfile = -1;
+static int outfile = -1;
 static char *current_rule;
 static ListNode *labels_for_func = NULL;
 static AST *whichRule;
