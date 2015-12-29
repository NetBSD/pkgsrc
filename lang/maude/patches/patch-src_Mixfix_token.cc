$NetBSD: patch-src_Mixfix_token.cc,v 1.2 2015/12/29 23:34:51 dholland Exp $

Don't use <rope> with clang, but fall back to <string>. Untested for
functionality.

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
