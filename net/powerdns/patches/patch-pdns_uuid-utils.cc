$NetBSD: patch-pdns_uuid-utils.cc,v 1.1 2024/10/04 04:27:20 ryoon Exp $

--- pdns/uuid-utils.cc.orig	2024-10-02 21:29:12.123938202 +0000
+++ pdns/uuid-utils.cc
@@ -30,6 +30,7 @@
 #endif /* BOOST_PENDING_INTEGER_LOG2_HPP */
 #endif /* BOOST_VERSION */
 
+#include <boost/random/mersenne_twister.hpp>
 #include <boost/uuid/uuid_generators.hpp>
 
 // The default of:
