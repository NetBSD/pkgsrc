$NetBSD: patch-include_cloog_isl_constraintset.h,v 1.1 2014/04/25 21:01:27 wiz Exp $

From: Taj Muhammad Khan <taj.khan@lri.fr>
Date: Thu, 5 Dec 2013 02:25:16 +0000 (+0530)
Subject: Use isl_val instead of isl_int
X-Git-Url: http://repo.or.cz/w/cloog.git/commitdiff_plain/2d8b7c6b43ee46fee978a57fa6877de49675f357?hp=d02b7193c157b61ddeabae55718793c078d73961

Use isl_val instead of isl_int

isl is moving from the macro-based isl_int to a more generic
integer type isl_val, so CLooG does with this patch.
Authors are Uday Bondhugula, Taj Muhammad Khan and Cedric Bastoul.

--- include/cloog/isl/constraintset.h.orig	2013-10-11 07:27:03.000000000 +0000
+++ include/cloog/isl/constraintset.h
@@ -27,6 +27,12 @@ CloogConstraintSet *cloog_constraint_set
 CloogConstraint *cloog_constraint_from_isl_constraint(struct isl_constraint *constraint);
 isl_constraint *cloog_constraint_to_isl(CloogConstraint *constraint);
 
+__isl_give isl_val *cloog_int_to_isl_val(isl_ctx* ctx, cloog_int_t c);
+void isl_val_to_cloog_int(__isl_keep isl_val *val, cloog_int_t *cint);
+
+__isl_give isl_val *cloog_constraint_coefficient_get_val(CloogConstraint *constraint,
+			int var);
+
 #if defined(__cplusplus)
   }
 #endif 
