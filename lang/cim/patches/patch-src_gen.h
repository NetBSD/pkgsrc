$NetBSD: patch-src_gen.h,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.

--- src/gen.h.orig	2012-10-26 13:04:50.000000000 +0000
+++ src/gen.h
@@ -68,11 +68,11 @@ extern gentype ();
 extern genmodulemark();
 extern gen_adr_prot();
 
-extern genvalue();
+void genvalue (struct EXP *re);
 
 /* genpar.c */
 extern genprocparam ();
-extern genpredefproccall ();
+void genpredefproccall (struct EXP *re);
 extern gencproccall ();
 extern gen_thunk_simple_address ();
 extern gen_thunk_simple_value ();
