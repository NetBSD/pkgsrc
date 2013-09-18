$NetBSD: patch-rak_functional__fun.h,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- rak/functional_fun.h.orig	2012-02-14 03:32:01.000000000 +0000
+++ rak/functional_fun.h
@@ -53,8 +53,14 @@
 
 #include <memory>
 #include <functional>
+#if __cplusplus >= 201103L
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/functional>
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 namespace rak {
 
@@ -98,13 +104,13 @@ public:
 
   bool                is_valid() const     { return m_base.get() != NULL; }
 
-  void                set(base_type* base) { m_base = std::tr1::shared_ptr<base_type>(base); }
+  void                set(base_type* base) { m_base = shared_ptr<base_type>(base); }
   base_type*          release()            { return m_base.release(); }
 
   Result operator () ()                    { return (*m_base)(); }
 
 private:
-  std::tr1::shared_ptr<base_type> m_base;
+  shared_ptr<base_type> m_base;
 };
 
 template <typename Result, typename Arg1>
@@ -115,13 +121,13 @@ public:
 
   bool                is_valid() const     { return m_base.get() != NULL; }
 
-  void                set(base_type* base) { m_base = std::tr1::shared_ptr<base_type>(base); }
+  void                set(base_type* base) { m_base = shared_ptr<base_type>(base); }
   base_type*          release()            { return m_base.release(); }
 
   Result operator () (Arg1 arg1)           { return (*m_base)(arg1); }
 
 private:
-  std::tr1::shared_ptr<base_type> m_base;
+  shared_ptr<base_type> m_base;
 };
 
 template <typename Result, typename Arg1, typename Arg2>
@@ -132,13 +138,13 @@ public:
 
   bool                is_valid() const     { return m_base.get() != NULL; }
 
-  void                set(base_type* base) { m_base = std::tr1::shared_ptr<base_type>(base); }
+  void                set(base_type* base) { m_base = shared_ptr<base_type>(base); }
   base_type*          release()            { return m_base.release(); }
 
   Result operator () (Arg1 arg1, Arg2 arg2) { return (*m_base)(arg1, arg2); }
 
 private:
-  std::tr1::shared_ptr<base_type> m_base;
+  shared_ptr<base_type> m_base;
 };
 
 template <typename Result, typename Arg2>
@@ -149,7 +155,7 @@ public:
 
   bool                is_valid() const     { return m_base.get() != NULL; }
 
-  void                set(base_type* base) { m_base = std::tr1::shared_ptr<base_type>(base); }
+  void                set(base_type* base) { m_base = shared_ptr<base_type>(base); }
   base_type*          release()            { return m_base.release(); }
 
   Result operator () (Arg2 arg2)           { return (*m_base)(arg2); }
@@ -158,7 +164,7 @@ public:
   Result operator () (Discard discard, Arg2 arg2) { return (*m_base)(arg2); }
 
 private:
-  std::tr1::shared_ptr<base_type> m_base;
+  shared_ptr<base_type> m_base;
 };
 
 template <typename Result, typename Arg1, typename Arg2, typename Arg3>
@@ -169,13 +175,13 @@ public:
 
   bool                is_valid() const     { return m_base.get() != NULL; }
 
-  void                set(base_type* base) { m_base = std::tr1::shared_ptr<base_type>(base); }
+  void                set(base_type* base) { m_base = shared_ptr<base_type>(base); }
   base_type*          release()            { return m_base.release(); }
 
   Result operator () (Arg1 arg1, Arg2 arg2, Arg3 arg3) { return (*m_base)(arg1, arg2, arg3); }
 
 private:
-  std::tr1::shared_ptr<base_type> m_base;
+  shared_ptr<base_type> m_base;
 };
 
 template <typename Result>
