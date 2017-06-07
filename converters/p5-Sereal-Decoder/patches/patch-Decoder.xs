$NetBSD: patch-Decoder.xs,v 1.1 2017/06/07 14:33:23 ryoon Exp $

* Fix build with Perl 5.26.0
  Like devel/p5-Params-Classify/patches/patch-lib_Params_Classify.xs

--- Decoder.xs.orig	2015-11-27 00:15:01.000000000 +0000
+++ Decoder.xs
@@ -19,6 +19,26 @@
 #ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
 #define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)
 
+#ifndef OpHAS_SIBLING
+#  define OpHAS_SIBLING(o)		(cBOOL((o)->op_sibling))
+#endif
+
+#ifndef OpSIBLING
+#  define OpSIBLING(o)			(0 + (o)->op_sibling)
+#endif
+
+#ifndef OpMORESIB_set
+#  define OpMORESIB_set(o, sib)		((o)->op_sibling = (sib))
+#endif
+
+#ifndef OpLASTSIB_set
+#  define OpLASTSIB_set(o, parent)	((o)->op_sibling = NULL)
+#endif
+
+#ifndef OpMAYBESIB_set
+#  define OpMAYBESIB_set(o, sib, parent)	((o)->op_sibling = (sib))
+#endif
+
 /* prototype to pass -Wmissing-prototypes */
 STATIC void
 S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);
@@ -193,17 +213,17 @@ THX_ck_entersub_args_sereal_decoder(pTHX
 
     entersubop = ck_entersub_args_proto(entersubop, namegv, (SV*)cv);
     pushop = cUNOPx(entersubop)->op_first;
-    if ( ! pushop->op_sibling )
+    if ( ! OpHAS_SIBLING(pushop) )
         pushop = cUNOPx(pushop)->op_first;
-    firstargop = pushop->op_sibling;
+    firstargop = OpSIBLING(pushop);
 
-    for (cvop = firstargop; cvop->op_sibling; cvop = cvop->op_sibling) ;
+    for (cvop = firstargop; OpHAS_SIBLING(cvop); cvop = OpSIBLING(cvop)) ;
 
     lastargop = pushop;
     for (
         arity = 0, lastargop = pushop, argop = firstargop;
         argop != cvop;
-        lastargop = argop, argop = argop->op_sibling
+        lastargop = argop, argop = OpSIBLING(argop)
     ){
         arity++;
     }
@@ -222,8 +242,8 @@ THX_ck_entersub_args_sereal_decoder(pTHX
     if (arity > min_arity)
         opopt |= OPOPT_OUTARG_HEADER;
 
-    pushop->op_sibling = cvop;
-    lastargop->op_sibling = NULL;
+    OpLASTSIB_set(pushop, cvop);
+    OpLASTSIB_set(lastargop, NULL);
     op_free(entersubop);
     newop = newUNOP(OP_NULL, 0, firstargop);
     newop->op_type    = OP_CUSTOM;
