$NetBSD: patch-modelgen_mg__.h,v 1.1 2013/02/26 10:22:53 joerg Exp $

--- modelgen/mg_.h.orig	2013-02-25 18:16:05.000000000 +0000
+++ modelgen/mg_.h
@@ -77,6 +77,21 @@ inline CS&	     operator>>(CS& f, Base& 
 inline std::ostream& operator<<(std::ostream& f, const Base& d)
 						{d.print(f); return f;}
 /*--------------------------------------------------------------------------*/
+class C_Comment
+  :public Base
+{
+public:
+  void parse(CS& f);
+};
+/*--------------------------------------------------------------------------*/
+class Cxx_Comment
+  :public Base
+{
+public:
+  void parse(CS& f);
+};
+
+/*--------------------------------------------------------------------------*/
 template <class T>
 class List_Base
   :public Base
@@ -149,20 +164,6 @@ public:
   }
 };
 /*--------------------------------------------------------------------------*/
-class C_Comment
-  :public Base
-{
-public:
-  void parse(CS& f);
-};
-/*--------------------------------------------------------------------------*/
-class Cxx_Comment
-  :public Base
-{
-public:
-  void parse(CS& f);
-};
-/*--------------------------------------------------------------------------*/
 class Key
 {
   std::string _name;
