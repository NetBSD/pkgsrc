$NetBSD: patch-uuid-utils.cc,v 1.1 2024/10/04 04:28:39 ryoon Exp $

--- uuid-utils.cc.orig	2024-10-02 21:34:37.539770071 +0000
+++ uuid-utils.cc
@@ -30,6 +30,7 @@
 #endif /* BOOST_PENDING_INTEGER_LOG2_HPP */
 #endif /* BOOST_VERSION */
 
+#include <boost/random/mersenne_twister.hpp>
 #include <boost/uuid/uuid_generators.hpp>
 
 // The default of:
