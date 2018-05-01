$NetBSD: patch-boost_lockfree_spsc__queue.hpp,v 1.1 2018/05/01 15:43:08 minskim Exp $

Fix Boost ticket #13497 (https://svn.boost.org/trac10/ticket/13497).

Patch from https://github.com/boostorg/lockfree/commit/12726cda.

--- boost/lockfree/spsc_queue.hpp.orig	2018-04-11 13:49:04.000000000 +0000
+++ boost/lockfree/spsc_queue.hpp
@@ -17,6 +17,7 @@
 #include <boost/assert.hpp>
 #include <boost/static_assert.hpp>
 #include <boost/utility.hpp>
+#include <boost/next_prior.hpp>
 #include <boost/utility/enable_if.hpp>
 #include <boost/config.hpp> // for BOOST_LIKELY
 
