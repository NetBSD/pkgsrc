$NetBSD: patch-src_include_fst_determinize.h,v 1.1 2012/07/03 17:42:05 joerg Exp $

--- src/include/fst/determinize.h.orig	2012-07-03 09:55:10.000000000 +0000
+++ src/include/fst/determinize.h
@@ -171,7 +171,7 @@ class DeterminizeFstImplBase : public Ca
     if (!HasStart()) {
       StateId start = ComputeStart();
       if (start != kNoStateId) {
-        SetStart(start);
+        this->SetStart(start);
       }
     }
     return CacheImpl<A>::Start();
@@ -180,7 +180,7 @@ class DeterminizeFstImplBase : public Ca
   Weight Final(StateId s) {
     if (!HasFinal(s)) {
       Weight final = ComputeFinal(s);
-      SetFinal(s, final);
+      this->SetFinal(s, final);
     }
     return CacheImpl<A>::Final(s);
   }
@@ -363,7 +363,7 @@ class DeterminizeFsaImpl : public Determ
          liter != label_map.end();
          ++liter)
       AddArc(s, liter->first, liter->second);
-    SetArcs(s);
+    this->SetArcs(s);
   }
 
  private:
