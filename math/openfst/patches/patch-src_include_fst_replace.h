$NetBSD: patch-src_include_fst_replace.h,v 1.1 2012/07/03 17:42:05 joerg Exp $

--- src/include/fst/replace.h.orig	2012-07-03 10:02:47.000000000 +0000
+++ src/include/fst/replace.h
@@ -424,16 +424,16 @@ class ReplaceFstImpl : public CacheImpl<
 
   // return final weight of state (kInfWeight means state is not final)
   Weight Final(StateId s) {
-    if (!HasFinal(s)) {
+    if (!this->HasFinal(s)) {
       const StateTuple& tuple  = state_table_->Tuple(s);
       const StackPrefix& stack = stackprefix_array_[tuple.prefix_id];
       const Fst<A>* fst = fst_array_[tuple.fst_id];
       StateId fst_state = tuple.fst_state;
 
       if (fst->Final(fst_state) != Weight::Zero() && stack.Depth() == 0)
-        SetFinal(s, fst->Final(fst_state));
+        this->SetFinal(s, fst->Final(fst_state));
       else
-        SetFinal(s, Weight::Zero());
+        this->SetFinal(s, Weight::Zero());
     }
     return CacheImpl<A>::Final(s);
   }
@@ -471,7 +471,7 @@ class ReplaceFstImpl : public CacheImpl<
     const Fst<A>* fst = fst_array_[tuple.fst_id];
     StateId fst_state = tuple.fst_state;
     if (fst_state == kNoStateId) {
-      SetArcs(s);
+      this->SetArcs(s);
       return;
     }
 
@@ -483,7 +483,7 @@ class ReplaceFstImpl : public CacheImpl<
 
       StateId nextstate = state_table_->FindState(
           StateTuple(prefix_id, top.fst_id, top.nextstate));
-      AddArc(s, A(0, 0, fst->Final(fst_state), nextstate));
+      this->AddArc(s, A(0, 0, fst->Final(fst_state), nextstate));
     }
 
     // extend arcs leaving the state
@@ -493,7 +493,7 @@ class ReplaceFstImpl : public CacheImpl<
       if (arc.olabel == 0) {  // expand local fst
         StateId nextstate = state_table_->FindState(
             StateTuple(tuple.prefix_id, tuple.fst_id, arc.nextstate));
-        AddArc(s, A(arc.ilabel, arc.olabel, arc.weight, nextstate));
+        this->AddArc(s, A(arc.ilabel, arc.olabel, arc.weight, nextstate));
       } else {
         // check for non terminal
         typename NonTerminalHash::const_iterator it =
@@ -511,17 +511,17 @@ class ReplaceFstImpl : public CacheImpl<
             StateId nt_nextstate = state_table_->FindState(
                 StateTuple(nt_prefix, nonterminal, nt_start));
             Label ilabel = (epsilon_on_replace_) ? 0 : arc.ilabel;
-            AddArc(s, A(ilabel, 0, arc.weight, nt_nextstate));
+            this->AddArc(s, A(ilabel, 0, arc.weight, nt_nextstate));
           }
         } else {
           StateId nextstate =  state_table_->FindState(
                 StateTuple(tuple.prefix_id, tuple.fst_id, arc.nextstate));
-          AddArc(s, A(arc.ilabel, arc.olabel, arc.weight, nextstate));
+          this->AddArc(s, A(arc.ilabel, arc.olabel, arc.weight, nextstate));
         }
       }
     }
 
-    SetArcs(s);
+    this->SetArcs(s);
   }
 
 
