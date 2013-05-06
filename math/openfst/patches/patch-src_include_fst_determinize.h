$NetBSD: patch-src_include_fst_determinize.h,v 1.2 2013/05/06 14:52:54 joerg Exp $

--- src/include/fst/determinize.h.orig	2009-03-21 03:35:33.000000000 +0000
+++ src/include/fst/determinize.h
@@ -21,9 +21,17 @@
 #ifndef FST_LIB_DETERMINIZE_H__
 #define FST_LIB_DETERMINIZE_H__
 
-#include <algorithm>
+#include <ciso646>
+
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <unordered_map>
+using std::unordered_map;
+#else
 #include <tr1/unordered_map>
 using std::tr1::unordered_map;
+#endif
+
+#include <algorithm>
 #include <map>
 #include <fst/slist.h>
 #include <string>
@@ -171,7 +179,7 @@ class DeterminizeFstImplBase : public Ca
     if (!HasStart()) {
       StateId start = ComputeStart();
       if (start != kNoStateId) {
-        SetStart(start);
+        this->SetStart(start);
       }
     }
     return CacheImpl<A>::Start();
@@ -180,7 +188,7 @@ class DeterminizeFstImplBase : public Ca
   Weight Final(StateId s) {
     if (!HasFinal(s)) {
       Weight final = ComputeFinal(s);
-      SetFinal(s, final);
+      this->SetFinal(s, final);
     }
     return CacheImpl<A>::Final(s);
   }
@@ -363,7 +371,7 @@ class DeterminizeFsaImpl : public Determ
          liter != label_map.end();
          ++liter)
       AddArc(s, liter->first, liter->second);
-    SetArcs(s);
+    this->SetArcs(s);
   }
 
  private:
