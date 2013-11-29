$NetBSD: patch-src_Mixfix_token.cc,v 1.1 2013/11/29 18:30:10 joerg Exp $

--- src/Mixfix/token.cc.orig	2013-11-28 00:50:24.000000000 +0000
+++ src/Mixfix/token.cc
@@ -632,7 +632,7 @@ Token::codeToRope(int code)
 	      }
 	  }
 	}
-      result.append(c);
+      result.push_back(c);
       seenBackslash = false;
     }
   CantHappen("bad end to string");
