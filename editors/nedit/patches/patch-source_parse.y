$NetBSD: patch-source_parse.y,v 1.2 2014/03/22 17:26:13 gdt Exp $

Silence gcc warnings about unsafe pointer casts.

--- source/parse.y.orig	2003-12-19 23:23:31.000000000 +0000
+++ source/parse.y
@@ -14,6 +14,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <ctype.h>
+#include <stdint.h>
 #include <X11/Intrinsic.h>
 #include <Xm/Xm.h>
 #ifdef VMS
@@ -178,69 +179,69 @@ simpstmt:   SYMBOL '=' expr {
                 ADD_OP(OP_BIT_OR); ADD_OP(OP_ASSIGN); ADD_SYM($1);
             }
             | DELETE arraylv '[' arglist ']' {
-                ADD_OP(OP_ARRAY_DELETE); ADD_IMMED((void *)$4);
+                ADD_OP(OP_ARRAY_DELETE); ADD_IMMED((void *)(intptr_t)$4);
             }
             | initarraylv '[' arglist ']' '=' expr {
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | initarraylv '[' arglist ']' ADDEQ expr {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)1); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)1); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_ADD);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | initarraylv '[' arglist ']' SUBEQ expr {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)1); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)1); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_SUB);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | initarraylv '[' arglist ']' MULEQ expr {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)1); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)1); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_MUL);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | initarraylv '[' arglist ']' DIVEQ expr {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)1); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)1); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_DIV);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | initarraylv '[' arglist ']' MODEQ expr {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)1); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)1); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_MOD);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | initarraylv '[' arglist ']' ANDEQ expr {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)1); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)1); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_BIT_AND);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | initarraylv '[' arglist ']' OREQ expr {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)1); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)1); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_BIT_OR);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | initarraylv '[' arglist ']' INCR {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)0); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)0); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_INCR);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | initarraylv '[' arglist ']' DECR {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)0); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)0); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_DECR);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$3);
             }
             | INCR initarraylv '[' arglist ']' {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)0); ADD_IMMED((void *)$4);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)0); ADD_IMMED((void *)(intptr_t)$4);
                 ADD_OP(OP_INCR);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$4);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$4);
             }
             | DECR initarraylv '[' arglist ']' {
-                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)0); ADD_IMMED((void *)$4);
+                ADD_OP(OP_ARRAY_REF_ASSIGN_SETUP); ADD_IMMED((void *)(intptr_t)0); ADD_IMMED((void *)(intptr_t)$4);
                 ADD_OP(OP_DECR);
-                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)$4);
+                ADD_OP(OP_ARRAY_ASSIGN); ADD_IMMED((void *)(intptr_t)$4);
             }
             | SYMBOL '(' arglist ')' {
                 ADD_OP(OP_SUBR_CALL);
-                ADD_SYM(PromoteToGlobal($1)); ADD_IMMED((void *)$3);
+                ADD_SYM(PromoteToGlobal($1)); ADD_IMMED((void *)(intptr_t)$3);
             }
             | INCR SYMBOL {
                 ADD_OP(OP_PUSH_SYM); ADD_SYM($2); ADD_OP(OP_INCR);
@@ -289,17 +290,17 @@ expr:       numexpr %prec CONCAT
             }
             ;
 initarraylv:    SYMBOL {
-                    ADD_OP(OP_PUSH_ARRAY_SYM); ADD_SYM($1); ADD_IMMED((void *)1);
+                    ADD_OP(OP_PUSH_ARRAY_SYM); ADD_SYM($1); ADD_IMMED((void *)(intptr_t)1);
                 }
                 | initarraylv '[' arglist ']' {
-                    ADD_OP(OP_ARRAY_REF); ADD_IMMED((void *)$3);
+                    ADD_OP(OP_ARRAY_REF); ADD_IMMED((void *)(intptr_t)$3);
                 }
                 ;
 arraylv:    SYMBOL {
-                ADD_OP(OP_PUSH_ARRAY_SYM); ADD_SYM($1); ADD_IMMED((void *)0);
+                ADD_OP(OP_PUSH_ARRAY_SYM); ADD_SYM($1); ADD_IMMED((void *)(intptr_t)0);
             }
             | arraylv '[' arglist ']' {
-                ADD_OP(OP_ARRAY_REF); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF); ADD_IMMED((void *)(intptr_t)$3);
             }
             ;
 arrayexpr:  numexpr {
@@ -317,7 +318,7 @@ numexpr:    NUMBER {
             }
             | SYMBOL '(' arglist ')' {
                 ADD_OP(OP_SUBR_CALL);
-                ADD_SYM(PromoteToGlobal($1)); ADD_IMMED((void *)$3);
+                ADD_SYM(PromoteToGlobal($1)); ADD_IMMED((void *)(intptr_t)$3);
                 ADD_OP(OP_FETCH_RET_VAL);
             }
             | '(' expr ')'
@@ -331,7 +332,7 @@ numexpr:    NUMBER {
                ADD_OP(OP_PUSH_ARG_ARRAY);
             }
             | numexpr '[' arglist ']' {
-                ADD_OP(OP_ARRAY_REF); ADD_IMMED((void *)$3);
+                ADD_OP(OP_ARRAY_REF); ADD_IMMED((void *)(intptr_t)$3);
             }
             | numexpr '+' numexpr {
                 ADD_OP(OP_ADD);
