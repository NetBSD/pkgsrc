$NetBSD: patch-src_include_fst_compact-fst.h,v 1.1 2012/07/03 17:42:05 joerg Exp $

--- src/include/fst/compact-fst.h.orig	2012-07-03 09:45:14.000000000 +0000
+++ src/include/fst/compact-fst.h
@@ -484,7 +484,7 @@ class CompactFstImpl : public CacheImpl<
 
   StateId Start() {
     if (!HasStart()) {
-      SetStart(data_->Start());
+      this->SetStart(data_->Start());
     }
     return CacheImpl<A>::Start();
   }
@@ -497,7 +497,7 @@ class CompactFstImpl : public CacheImpl<
         arc = compactor_->Expand(s, data_->Compacts(compactor_->Size() == -1
                                                     ? data_->States(s)
                                                     : s * compactor_->Size()));
-      SetFinal(s, arc.ilabel == kNoLabel ? arc.weight : Weight::Zero());
+      this->SetFinal(s, arc.ilabel == kNoLabel ? arc.weight : Weight::Zero());
     }
     return CacheImpl<A>::Final(s);
   }
@@ -566,9 +566,9 @@ class CompactFstImpl : public CacheImpl<
     for (size_t i = begin; i < end; ++i) {
       const Arc &arc = compactor_->Expand(s, data_->Compacts(i));
       if (arc.ilabel == kNoLabel) continue;
-      AddArc(s, arc);
+      this->AddArc(s, arc);
     }
-    SetArcs(s);
+    this->SetArcs(s);
   }
 
  private:
