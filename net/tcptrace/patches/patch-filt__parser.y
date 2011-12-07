$NetBSD: patch-filt__parser.y,v 1.1 2011/12/07 15:18:51 joerg Exp $

--- filt_parser.y.orig	2001-05-31 20:54:59.000000000 +0000
+++ filt_parser.y
@@ -72,7 +72,7 @@
     long signed_long;
     u_long unsigned_long;
     ipaddr *pipaddr;
-    Bool bool;
+    Bool boolean;
     enum optype op;
     struct filter_node *pf;
 }
@@ -99,7 +99,7 @@
 %token <string> VARIABLE STRING
 %token <signed_long> SIGNED
 %token <unsigned_long> UNSIGNED
-%token <bool> BOOL
+%token <boolean> BOOL
 %token <pipaddr> IPADDR
 %type <op> relop
 %type <pf> expr leaf number
