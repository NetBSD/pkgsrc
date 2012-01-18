$NetBSD: patch-libasync_vec.h,v 1.1 2012/01/18 14:32:10 adam Exp $

Fix C++ errors

--- libasync/vec.h.orig	2012-01-18 14:06:37.000000000 +0000
+++ libasync/vec.h
@@ -102,7 +102,7 @@ protected:
   static void destroy (elm_t &e) { e.~elm_t (); }
 
   void init () { lastp = firstp = basep = def_basep (); limp = def_limp (); }
-  void del () { while (firstp < lastp) firstp++->~elm_t (); bfree (basep); }
+  void del () { while (firstp < lastp) firstp++->~elm_t (); this->bfree (basep); }
 
 #define append(v)						\
 do {								\
@@ -143,7 +143,7 @@ public:
       elm_t *obasep = basep;
       move (static_cast<elm_t *> (txmalloc (nalloc * sizeof (elm_t))));
       limp = basep + nalloc;
-      bfree (obasep);
+      this->bfree (obasep);
     }
     else
       move (basep);
