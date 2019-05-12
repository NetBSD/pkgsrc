$NetBSD: patch-src_lisp_getters.hpp,v 1.2 2019/05/12 06:17:30 triaxx Exp $

* Legacy uncommented patch: I trust it...

--- src/lisp/getters.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/lisp/getters.hpp
@@ -30,7 +30,7 @@ static inline bool property_get(const Li
   if(lisp->get_list_size() != 2)
     return false;
   
-  const Lisp* el = lisp->get_list_elem(1);
+  const Lisp* el = lisp->get_list_elem(1).get();
   return get(el, val);
 }
 
