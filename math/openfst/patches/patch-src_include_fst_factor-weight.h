$NetBSD: patch-src_include_fst_factor-weight.h,v 1.2 2013/05/06 14:52:54 joerg Exp $

--- src/include/fst/factor-weight.h.orig	2009-03-21 03:35:33.000000000 +0000
+++ src/include/fst/factor-weight.h
@@ -20,9 +20,17 @@
 #ifndef FST_LIB_FACTOR_WEIGHT_H__
 #define FST_LIB_FACTOR_WEIGHT_H__
 
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
 #include <fst/slist.h>
 #include <string>
 #include <utility>
@@ -215,7 +223,7 @@ class FactorWeightFstImpl
       if (s == kNoStateId)
         return kNoStateId;
       StateId start = FindState(Element(fst_->Start(), Weight::One()));
-      SetStart(start);
+      this->SetStart(start);
     }
     return CacheImpl<A>::Start();
   }
@@ -229,9 +237,9 @@ class FactorWeightFstImpl
                  : (Weight) Times(e.weight, fst_->Final(e.state));
       FactorIterator f(w);
       if (!(mode_ & kFactorFinalWeights) || f.Done())
-        SetFinal(s, w);
+        this->SetFinal(s, w);
       else
-        SetFinal(s, Weight::Zero());
+        this->SetFinal(s, Weight::Zero());
     }
     return CacheImpl<A>::Final(s);
   }
@@ -298,13 +306,13 @@ class FactorWeightFstImpl
         FactorIterator fit(w);
         if (!(mode_ & kFactorArcWeights) || fit.Done()) {
           StateId d = FindState(Element(arc.nextstate, Weight::One()));
-          AddArc(s, Arc(arc.ilabel, arc.olabel, w, d));
+          this->AddArc(s, Arc(arc.ilabel, arc.olabel, w, d));
         } else {
           for (; !fit.Done(); fit.Next()) {
             const pair<Weight, Weight> &p = fit.Value();
             StateId d = FindState(Element(arc.nextstate,
                                           p.second.Quantize(delta_)));
-            AddArc(s, Arc(arc.ilabel, arc.olabel, p.first, d));
+            this->AddArc(s, Arc(arc.ilabel, arc.olabel, p.first, d));
           }
         }
       }
@@ -322,10 +330,10 @@ class FactorWeightFstImpl
         const pair<Weight, Weight> &p = fit.Value();
         StateId d = FindState(Element(kNoStateId,
                                       p.second.Quantize(delta_)));
-        AddArc(s, Arc(final_ilabel_, final_olabel_, p.first, d));
+        this->AddArc(s, Arc(final_ilabel_, final_olabel_, p.first, d));
       }
     }
-    SetArcs(s);
+    this->SetArcs(s);
   }
 
  private:
