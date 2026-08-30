$NetBSD: patch-lessons.cpp,v 1.1 2026/08/30 09:14:25 he Exp $

Sprinkle "const" to deal with string constants and get rid of warnings.

--- lessons.cpp.orig	2026-08-30 09:05:20.511041785 +0000
+++ lessons.cpp
@@ -30,7 +30,7 @@
  * note that as of version 1.2 using ASCII files is possible too.
  */
 
-char *lessons[] =
+const char *lessons[] =
 {
     "UH: home row, index fingers",
 "\x2"
