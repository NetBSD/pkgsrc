$NetBSD: patch-lib_cli++_main.cc,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Remove unused function.

--- lib/cli++/main.cc.orig	2024-02-22 18:32:27.213171111 +0000
+++ lib/cli++/main.cc
@@ -49,11 +49,6 @@ static void build_options()
   options[optionc-1] = &help_option;
 }
 
-static inline unsigned max(unsigned a, unsigned b)
-{
-  return (a>b) ? a : b;
-}
-
 static const char* fill(unsigned i)
 {
   static unsigned lastlen = 0;
