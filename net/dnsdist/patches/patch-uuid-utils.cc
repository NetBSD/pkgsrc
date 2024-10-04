$NetBSD: patch-uuid-utils.cc,v 1.1 2024/10/04 04:09:29 ryoon Exp $

* Fix build with boost-1.86.0.
  From: https://github.com/PowerDNS/pdns/commit/eed56000b1d68ac083b8e8bea4ff0ea30a1579c4

--- uuid-utils.cc.orig	2024-10-02 02:33:19.524896798 +0000
+++ uuid-utils.cc
@@ -30,6 +30,7 @@
 #endif /* BOOST_PENDING_INTEGER_LOG2_HPP */
 #endif /* BOOST_VERSION */
 
+#include <boost/random/mersenne_twister.hpp>
 #include <boost/uuid/uuid_generators.hpp>
 
 // The default of:
