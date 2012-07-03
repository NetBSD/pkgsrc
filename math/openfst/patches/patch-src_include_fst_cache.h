$NetBSD: patch-src_include_fst_cache.h,v 1.1 2012/07/03 17:42:05 joerg Exp $

--- src/include/fst/cache.h.orig	2012-07-03 09:45:36.000000000 +0000
+++ src/include/fst/cache.h
@@ -138,11 +138,11 @@ class CacheBaseImpl : public VectorFstBa
       while (NumStates() <= s)                     // Add state to main cache
         AddState(0);
       if (!VectorFstBaseImpl<S>::GetState(s)) {
-        SetState(s, new S);
+        this->SetState(s, new S);
         if (cache_first_state_id_ != kNoStateId) {  // Forget 1st cached state
           while (NumStates() <= cache_first_state_id_)
             AddState(0);
-          SetState(cache_first_state_id_, cache_first_state_);
+          this->SetState(cache_first_state_id_, cache_first_state_);
           if (cache_gc_) {
             cache_states_.push_back(cache_first_state_id_);
             cache_size_ += sizeof(S) +
@@ -296,7 +296,7 @@ class CacheBaseImpl : public VectorFstBa
           (free_recent || !(state->flags & kCacheRecent)) && s != current) {
         cache_size_ -= sizeof(S) + state->arcs.capacity() * sizeof(Arc);
         delete state;
-        SetState(s, 0);
+        this->SetState(s, 0);
         cache_states_.erase(siter++);
       } else {
         state->flags &= ~kCacheRecent;
