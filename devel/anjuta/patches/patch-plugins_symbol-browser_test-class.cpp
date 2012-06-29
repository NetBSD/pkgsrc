$NetBSD: patch-plugins_symbol-browser_test-class.cpp,v 1.1 2012/06/29 12:32:23 joerg Exp $

--- plugins/symbol-browser/test-class.cpp.orig	2012-06-25 13:38:23.000000000 +0000
+++ plugins/symbol-browser/test-class.cpp
@@ -10,12 +10,11 @@ typedef struct _faa_1 {
  
 MyClass *klass;
 
- 
 //klass->
 
 int func_test1() {
 
-	YourClass klass();
+	YourClass klass;
 
 	
 
