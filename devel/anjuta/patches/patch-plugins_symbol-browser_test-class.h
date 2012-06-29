$NetBSD: patch-plugins_symbol-browser_test-class.h,v 1.1 2012/06/29 12:32:23 joerg Exp $

--- plugins/symbol-browser/test-class.h.orig	2012-06-25 13:40:35.000000000 +0000
+++ plugins/symbol-browser/test-class.h
@@ -72,7 +72,7 @@ class YourClass {
 
 
 public:
-	YourClass ();
+	YourClass () {};
 	YourClass (int par1, char* par2);
 
 	void yc_first_function( int par1, char** par2);
