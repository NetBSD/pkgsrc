$NetBSD: patch-src_include_fst_vector-fst.h,v 1.1 2012/07/03 17:42:05 joerg Exp $

--- src/include/fst/vector-fst.h.orig	2012-07-03 09:43:16.000000000 +0000
+++ src/include/fst/vector-fst.h
@@ -199,9 +199,9 @@ class VectorFstImpl : public VectorFstBa
 
   static VectorFstImpl<A> *Read(istream &strm, const FstReadOptions &opts);
 
-  size_t NumInputEpsilons(StateId s) const { return GetState(s)->niepsilons; }
+  size_t NumInputEpsilons(StateId s) const { return this->GetState(s)->niepsilons; }
 
-  size_t NumOutputEpsilons(StateId s) const { return GetState(s)->noepsilons; }
+  size_t NumOutputEpsilons(StateId s) const { return this->GetState(s)->noepsilons; }
 
   bool Write(ostream &strm, const FstWriteOptions &opts) const;
 
@@ -213,7 +213,7 @@ class VectorFstImpl : public VectorFstBa
   }
 
   void SetFinal(StateId s, Weight w) {
-    Weight ow = Final(s);
+    Weight ow = this->Final(s);
     if (ow != Weight::Zero() && ow != Weight::One())
       SetProperties(Properties() & ~kWeighted);
     BaseImpl::SetFinal(s, w);
@@ -232,7 +232,7 @@ class VectorFstImpl : public VectorFstBa
   }
 
   void AddArc(StateId s, const A &arc) {
-    VectorState<A> *state = GetState(s);
+    VectorState<A> *state = this->GetState(s);
     if (arc.ilabel != arc.olabel) {
       SetProperties(Properties() | kNotAcceptor);
       SetProperties(Properties() & ~kAcceptor);
@@ -290,21 +290,21 @@ class VectorFstImpl : public VectorFstBa
   }
 
   void DeleteArcs(StateId s, size_t n) {
-    const vector<A> &arcs = GetState(s)->arcs;
+    const vector<A> &arcs = this->GetState(s)->arcs;
     for (size_t i = 0; i < n; ++i) {
       size_t j = arcs.size() - i - 1;
       if (arcs[j].ilabel == 0)
-        --GetState(s)->niepsilons;
+        --this->GetState(s)->niepsilons;
       if (arcs[j].olabel == 0)
-        --GetState(s)->noepsilons;
+        --this->GetState(s)->noepsilons;
     }
     BaseImpl::DeleteArcs(s, n);
     SetProperties(Properties() & kDeleteArcsProperties);
   }
 
   void DeleteArcs(StateId s) {
-    GetState(s)->niepsilons = 0;
-    GetState(s)->noepsilons = 0;
+    this->GetState(s)->niepsilons = 0;
+    this->GetState(s)->noepsilons = 0;
     BaseImpl::DeleteArcs(s);
     SetProperties(Properties() & kDeleteArcsProperties);
   }
@@ -324,8 +324,8 @@ template <class A>
 VectorFstImpl<A>::VectorFstImpl(const Fst<A> &fst) {
   SetType("vector");
   SetProperties(fst.Properties(kCopyProperties, false) | kStaticProperties);
-  SetInputSymbols(fst.InputSymbols());
-  SetOutputSymbols(fst.OutputSymbols());
+  this->SetInputSymbols(fst.InputSymbols());
+  this->SetOutputSymbols(fst.OutputSymbols());
   BaseImpl::SetStart(fst.Start());
 
   for (StateIterator< Fst<A> > siter(fst);
@@ -334,16 +334,16 @@ VectorFstImpl<A>::VectorFstImpl(const Fs
     StateId s = siter.Value();
     BaseImpl::AddState();
     BaseImpl::SetFinal(s, fst.Final(s));
-    ReserveArcs(s, fst.NumArcs(s));
+    this->ReserveArcs(s, fst.NumArcs(s));
     for (ArcIterator< Fst<A> > aiter(fst, s);
          !aiter.Done();
          aiter.Next()) {
       const A &arc = aiter.Value();
       BaseImpl::AddArc(s, arc);
       if (arc.ilabel == 0)
-        ++GetState(s)->niepsilons;
+        ++this->GetState(s)->niepsilons;
       if (arc.olabel == 0)
-        ++GetState(s)->noepsilons;
+        ++this->GetState(s)->noepsilons;
     }
   }
 }
@@ -427,7 +427,7 @@ bool VectorFstImpl<A>::Write(ostream &st
   WriteHeader(strm, opts, kFileVersion, &hdr);
 
   for (StateId s = 0; s < NumStates(); ++s) {
-    const VectorState<A> *state = GetState(s);
+    const VectorState<A> *state = this->GetState(s);
     state->final.Write(strm);
     int64 narcs = state->arcs.size();
     WriteType(strm, narcs);
