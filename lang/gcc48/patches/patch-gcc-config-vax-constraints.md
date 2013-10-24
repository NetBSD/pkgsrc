$NetBSD: patch-gcc-config-vax-constraints.md,v 1.1 2013/10/24 18:31:12 martin Exp $

Upstream change rev. 202600

--- gcc/config/vax/constraints.md.orig	2013-01-10 21:38:27.000000000 +0100
+++ gcc/config/vax/constraints.md	2013-09-16 09:13:22.000000000 +0200
@@ -114,5 +114,6 @@
 
 (define_constraint "T"
     "@internal satisfies CONSTANT_P and, if pic is enabled, is not a SYMBOL_REF, LABEL_REF, or CONST."
-   (ior (not (match_code "const,symbol_ref,label_ref"))
-	(match_test "!flag_pic")))
+  (and (match_test ("CONSTANT_P (op)")) 
+       (ior (not (match_code "symbol_ref,label_ref,const")) 
+           (match_test "!flag_pic"))))
