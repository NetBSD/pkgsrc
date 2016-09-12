$NetBSD: patch-libdecnumber_decNumber.c,v 1.1 2016/09/12 22:13:54 maya Exp $

--- libdecnumber/decNumber.c.orig	2013-08-14 08:42:04.000000000 +0000
+++ libdecnumber/decNumber.c
@@ -770,7 +770,7 @@ decNumber * decNumberAbs(decNumber *res,
 decNumber * decNumberAdd(decNumber *res, const decNumber *lhs,
 			 const decNumber *rhs, decContext *set) {
   uInt status=0;			/* accumulator */
-  decAddOp(res, lhs, rhs, set, 0, &status);
+  decAddOp(res, lhs, rhs, set, (uByte)0, &status);
   if (status!=0) decStatus(res, status, set);
   #if DECCHECK
   decCheckInexact(res, set);
