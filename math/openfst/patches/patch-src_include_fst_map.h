$NetBSD: patch-src_include_fst_map.h,v 1.1 2012/07/03 17:42:05 joerg Exp $

--- src/include/fst/map.h.orig	2012-07-03 09:55:26.000000000 +0000
+++ src/include/fst/map.h
@@ -336,7 +336,7 @@ class MapFstImpl : public CacheImpl<B> {
 
   StateId Start() {
     if (!HasStart())
-      SetStart(FindOState(fst_->Start()));
+      this->SetStart(FindOState(fst_->Start()));
     return CacheImpl<B>::Start();
   }
 
@@ -348,24 +348,24 @@ class MapFstImpl : public CacheImpl<B> {
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
@@ -399,14 +399,14 @@ class MapFstImpl : public CacheImpl<B> {
 
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
@@ -422,7 +422,7 @@ class MapFstImpl : public CacheImpl<B> {
             if (superfinal_ == kNoStateId)
               superfinal_ = nstates_++;
             final_arc.nextstate = superfinal_;
-            AddArc(s, final_arc);
+            this->AddArc(s, final_arc);
           }
           break;
         }
@@ -431,12 +431,12 @@ class MapFstImpl : public CacheImpl<B> {
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
