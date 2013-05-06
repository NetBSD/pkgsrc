$NetBSD: patch-src_include_fst_map.h,v 1.2 2013/05/06 14:52:54 joerg Exp $

--- src/include/fst/map.h.orig	2009-03-21 03:35:34.000000000 +0000
+++ src/include/fst/map.h
@@ -21,8 +21,15 @@
 #ifndef FST_LIB_MAP_H__
 #define FST_LIB_MAP_H__
 
+#include <ciso646>
+
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <unordered_map>
+using std::unordered_map;
+#else
 #include <tr1/unordered_map>
 using std::tr1::unordered_map;
+#endif
 #include <string>
 #include <utility>
 #include <fst/cache.h>
@@ -336,7 +343,7 @@ class MapFstImpl : public CacheImpl<B> {
 
   StateId Start() {
     if (!HasStart())
-      SetStart(FindOState(fst_->Start()));
+      this->SetStart(FindOState(fst_->Start()));
     return CacheImpl<B>::Start();
   }
 
@@ -348,24 +355,24 @@ class MapFstImpl : public CacheImpl<B> {
           B final_arc = (*mapper_)(A(0, 0, fst_->Final(FindIState(s)),
                                         kNoStateId));
           CHECK(final_arc.ilabel == 0 && final_arc.olabel == 0);
-          SetFinal(s, final_arc.weight);
+          this->SetFinal(s, final_arc.weight);
           break;
         }
         case MAP_ALLOW_SUPERFINAL: {
           if (s == superfinal_) {
-            SetFinal(s, Weight::One());
+            this->SetFinal(s, Weight::One());
           } else {
             B final_arc = (*mapper_)(A(0, 0, fst_->Final(FindIState(s)),
                                           kNoStateId));
             if (final_arc.ilabel == 0 && final_arc.olabel == 0)
-              SetFinal(s, final_arc.weight);
+              this->SetFinal(s, final_arc.weight);
             else
-              SetFinal(s, Weight::Zero());
+              this->SetFinal(s, Weight::Zero());
           }
           break;
         }
         case MAP_REQUIRE_SUPERFINAL: {
-          SetFinal(s, s == superfinal_ ? Weight::One() : Weight::Zero());
+          this->SetFinal(s, s == superfinal_ ? Weight::One() : Weight::Zero());
           break;
         }
       }
@@ -399,14 +406,14 @@ class MapFstImpl : public CacheImpl<B> {
 
   void Expand(StateId s) {
     // Add exiting arcs.
-    if (s == superfinal_) { SetArcs(s); return; }
+    if (s == superfinal_) { this->SetArcs(s); return; }
 
     for (ArcIterator< Fst<A> > aiter(*fst_, FindIState(s));
          !aiter.Done(); aiter.Next()) {
       A aarc(aiter.Value());
       aarc.nextstate = FindOState(aarc.nextstate);
       const B& barc = (*mapper_)(aarc);
-      AddArc(s, barc);
+      this->AddArc(s, barc);
     }
 
     // Check for superfinal arcs.
@@ -422,7 +429,7 @@ class MapFstImpl : public CacheImpl<B> {
             if (superfinal_ == kNoStateId)
               superfinal_ = nstates_++;
             final_arc.nextstate = superfinal_;
-            AddArc(s, final_arc);
+            this->AddArc(s, final_arc);
           }
           break;
         }
@@ -431,12 +438,12 @@ class MapFstImpl : public CacheImpl<B> {
                                       kNoStateId));
         if (final_arc.ilabel != 0 || final_arc.olabel != 0 ||
             final_arc.weight != B::Weight::Zero())
-          AddArc(s, B(final_arc.ilabel, final_arc.olabel,
+          this->AddArc(s, B(final_arc.ilabel, final_arc.olabel,
                       final_arc.weight, superfinal_));
         break;
       }
     }
-    SetArcs(s);
+    this->SetArcs(s);
   }
 
  private:
