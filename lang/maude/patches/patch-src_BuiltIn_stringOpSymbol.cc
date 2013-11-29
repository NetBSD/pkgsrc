$NetBSD: patch-src_BuiltIn_stringOpSymbol.cc,v 1.1 2013/11/29 18:30:10 joerg Exp $

--- src/BuiltIn/stringOpSymbol.cc.orig	2013-11-28 00:39:08.000000000 +0000
+++ src/BuiltIn/stringOpSymbol.cc
@@ -472,7 +472,7 @@ StringOpSymbol::eqRewrite(DagNode* subje
 		const mpz_class& n0 = succSymbol->getNat(a0);
 		if (n0 <= 255)
 		  {
-		    char c = n0.get_si();
+		    char c[2] = { n0.get_si(), 0 };
 		    return rewriteToString(subject, context, crope(c));
 		  }
 	      }
