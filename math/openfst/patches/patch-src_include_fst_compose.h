$NetBSD: patch-src_include_fst_compose.h,v 1.1 2012/07/03 17:42:05 joerg Exp $

--- src/include/fst/compose.h.orig	2012-07-03 09:50:13.000000000 +0000
+++ src/include/fst/compose.h
@@ -114,7 +114,7 @@ class ComposeFstImplBase : public CacheI
     if (!HasStart()) {
       StateId start = ComputeStart();
       if (start != kNoStateId) {
-        SetStart(start);
+        this->SetStart(start);
       }
     }
     return CacheImpl<A>::Start();
@@ -123,7 +123,7 @@ class ComposeFstImplBase : public CacheI
   Weight Final(StateId s) {
     if (!HasFinal(s)) {
       Weight final = ComputeFinal(s);
-      SetFinal(s, final);
+      this->SetFinal(s, final);
     }
     return CacheImpl<A>::Final(s);
   }
@@ -266,7 +266,7 @@ class ComposeFstImpl : public ComposeFst
     for (ArcIterator< Fst<A> > iterb(*fstb, sb); !iterb.Done(); iterb.Next())
       MatchArc(s, matchera, iterb.Value(), match_input);
 
-    SetArcs(s);
+    this->SetArcs(s);
   }
 
   // Matches a single transition from 'fstb' against 'fata' at 's'.
