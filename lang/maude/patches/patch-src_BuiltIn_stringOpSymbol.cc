$NetBSD: patch-src_BuiltIn_stringOpSymbol.cc,v 1.2 2015/12/29 23:34:51 dholland Exp $

Don't use <rope> with clang, but fall back to <string>. Untested for
functionality.

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
