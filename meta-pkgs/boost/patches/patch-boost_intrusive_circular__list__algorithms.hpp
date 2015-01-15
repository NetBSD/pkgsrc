$NetBSD: patch-boost_intrusive_circular__list__algorithms.hpp,v 1.1 2015/01/15 13:01:44 joerg Exp $

--- boost/intrusive/circular_list_algorithms.hpp.orig	2015-01-13 12:09:16.000000000 +0000
+++ boost/intrusive/circular_list_algorithms.hpp
@@ -475,7 +475,7 @@ class circular_list_algorithms
             BOOST_CATCH(...){
                node_traits::set_next    (last_to_remove, new_f);
                node_traits::set_previous(new_f, last_to_remove);
-               throw;
+               BOOST_RETHROW
             }
             BOOST_CATCH_END
             node_traits::set_next(last_to_remove, new_f);
