$NetBSD: patch-libqalculate_MathStructure.cc,v 1.1 2016/07/16 03:56:40 markd Exp $

Build with gcc6 - from redhat

--- libqalculate/MathStructure.cc.orig	2010-01-05 15:15:27.000000000 +0000
+++ libqalculate/MathStructure.cc
@@ -7163,7 +7163,7 @@ bool sr_gcd(const MathStructure &m1, con
 	c.polynomialContent(xvar, cont_c, eo);
 	d.polynomialContent(xvar, cont_d, eo);
 	MathStructure gamma;
-	MathStructure::gcd(cont_c, cont_d, gamma, eo, false);
+	MathStructure::gcd(cont_c, cont_d, gamma, eo, NULL);
 	if(ddeg.isZero()) {
 		mgcd = gamma;
 		return true;
