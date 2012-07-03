$NetBSD: patch-source_errors.h,v 1.1 2012/07/03 18:46:16 joerg Exp $

--- source/errors.h.orig	2006-05-13 13:05:00.000000000 +0000
+++ source/errors.h
@@ -73,7 +73,7 @@
         AssertionException ( const ASCString& check, const ASCString& file, int line ) : ASCmsgException ( ASCString("Assertion failed: ") + check + " at " + file + ":" + ASCString::toString(line)  ) {};
   };
 
-#define assertOrThrow(expr)  (static_cast<void> ( (expr) ? 0 : (throw AssertionException (#expr, __FILE__, __LINE__))))
+#define assertOrThrow(expr)  do { if (expr) {} else throw AssertionException (#expr, __FILE__, __LINE__); } while (0)
   
   
 
