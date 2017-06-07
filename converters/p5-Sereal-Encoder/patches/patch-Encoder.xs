$NetBSD: patch-Encoder.xs,v 1.1 2017/06/07 14:33:24 ryoon Exp $

* Fix build with Perl 5.26.0
  Like devel/p5-Params-Classify/patches/patch-lib_Params_Classify.xs

--- Encoder.xs.orig	2015-11-27 01:30:50.000000000 +0000
+++ Encoder.xs
@@ -20,6 +20,27 @@
 # define GvCV_set(gv, cv) (GvCV(gv) = (cv))
 #endif
 
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
+
 #if defined(cv_set_call_checker) && defined(XopENTRY_set)
 # define USE_CUSTOM_OPS 1
 #else
@@ -88,14 +109,14 @@ THX_ck_entersub_args_sereal_encode_with_
 
   entersubop = ck_entersub_args_proto(entersubop, namegv, ckobj);
   pushop = cUNOPx(entersubop)->op_first;
-  if (!pushop->op_sibling)
+  if (!OpHAS_SIBLING(pushop))
     pushop = cUNOPx(pushop)->op_first;
-  firstargop = pushop->op_sibling;
+  firstargop = OpSIBLING(pushop);
 
-  for (cvop = firstargop; cvop->op_sibling; cvop = cvop->op_sibling) ;
+  for (cvop = firstargop; OpHAS_SIBLING(cvop); cvop = OpSIBLING(cvop)) ;
 
   for (arity = 0, lastargop = pushop, argop = firstargop; argop != cvop;
-       lastargop = argop, argop = argop->op_sibling)
+       lastargop = argop, argop = OpSIBLING(argop))
   {
     arity++;
   }
@@ -106,8 +127,8 @@ THX_ck_entersub_args_sereal_encode_with_
   /* If we get here, we can replace the entersub with a suitable
    * sereal_encode_with_object custom OP. */
 
-  pushop->op_sibling = cvop;
-  lastargop->op_sibling = NULL;
+  OpLASTSIB_set(pushop, cvop);
+  OpLASTSIB_set(lastargop, NULL);
   op_free(entersubop);
   newop = newUNOP(OP_NULL, 0, firstargop);
   newop->op_type    = OP_CUSTOM;
