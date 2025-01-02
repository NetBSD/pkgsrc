$NetBSD: patch-builtin.c,v 1.1 2025/01/02 15:24:13 jklos Exp $

--- builtin.c.orig	2025-01-01 21:26:38.327210188 +0000
+++ builtin.c
@@ -90,6 +90,7 @@ XS(XS_builtin_false)
     XSRETURN_NO;
 }
 
+#ifndef __vax__
 XS(XS_builtin_inf);
 XS(XS_builtin_inf)
 {
@@ -109,12 +110,15 @@ XS(XS_builtin_nan)
     EXTEND(SP, 1);
     XSRETURN_NV(NV_NAN);
 }
+#endif
 
 enum {
     BUILTIN_CONST_FALSE,
     BUILTIN_CONST_TRUE,
+#ifndef __vax__
     BUILTIN_CONST_INF,
     BUILTIN_CONST_NAN,
+#endif
 };
 
 static OP *ck_builtin_const(pTHX_ OP *entersubop, GV *namegv, SV *ckobj)
@@ -135,8 +139,10 @@ static OP *ck_builtin_const(pTHX_ OP *en
     switch(builtin->ckval) {
         case BUILTIN_CONST_FALSE: constval = &PL_sv_no; break;
         case BUILTIN_CONST_TRUE:  constval = &PL_sv_yes; break;
+#ifndef __vax__
         case BUILTIN_CONST_INF:   constval = newSVnv(NV_INF); break;
         case BUILTIN_CONST_NAN:   constval = newSVnv(NV_NAN); break;
+#endif
         default:
             DIE(aTHX_ "panic: unrecognised builtin_const value %" IVdf,
                       builtin->ckval);
@@ -546,8 +552,10 @@ static const struct BuiltinFuncDescripto
     /* constants */
     { "true",  SHORTVER(5,39), &XS_builtin_true,   &ck_builtin_const, BUILTIN_CONST_TRUE,  false },
     { "false", SHORTVER(5,39), &XS_builtin_false,  &ck_builtin_const, BUILTIN_CONST_FALSE, false },
+#ifndef __vax__
     { "inf",        NO_BUNDLE, &XS_builtin_inf,    &ck_builtin_const, BUILTIN_CONST_INF,   true },
     { "nan",        NO_BUNDLE, &XS_builtin_nan,    &ck_builtin_const, BUILTIN_CONST_NAN,   true },
+#endif
 
     /* unary functions */
     { "is_bool",         NO_BUNDLE, &XS_builtin_func1_scalar, &ck_builtin_func1, OP_IS_BOOL,    true  },
