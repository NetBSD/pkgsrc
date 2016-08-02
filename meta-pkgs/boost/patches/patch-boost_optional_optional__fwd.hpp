$NetBSD: patch-boost_optional_optional__fwd.hpp,v 1.1 2016/08/02 08:49:46 wiz Exp $

Fix build issues when optional_fwd.hpp is used before including boost/config.hpp
https://github.com/boostorg/optional/pull/19/commits/844ca6a0d506e59daedabb2b94e1117ec4a7e71e

--- boost/optional/optional_fwd.hpp.orig	2016-05-05 21:13:30.000000000 +0000
+++ boost/optional/optional_fwd.hpp
@@ -16,7 +16,7 @@
 #ifndef BOOST_OPTIONAL_OPTIONAL_FWD_FLC_19NOV2002_HPP
 #define BOOST_OPTIONAL_OPTIONAL_FWD_FLC_19NOV2002_HPP
 
-#include <boost/config/suffix.hpp>
+#include <boost/config.hpp>
 
 namespace boost {
 
