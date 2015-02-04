$NetBSD: patch-include_mdds_multi__type__vector__types.hpp,v 1.1 2015/02/04 18:01:25 ryoon Exp $

https://code.google.com/p/multidimalgorithm/source/detail?r=c45e0499dded11dc2aacea40b470ab1431ea535a

--- include/mdds/multi_type_vector_types.hpp.orig	2014-12-18 20:05:56.000000000 +0000
+++ include/mdds/multi_type_vector_types.hpp
@@ -39,8 +39,9 @@
 #endif
 #include <boost/noncopyable.hpp>
 
-#if defined(MDDS_UNIT_TEST) || defined (MDDS_MULTI_TYPE_VECTOR_DEBUG)
 #include <algorithm>
+
+#if defined(MDDS_UNIT_TEST) || defined (MDDS_MULTI_TYPE_VECTOR_DEBUG)
 #include <iostream>
 #include <sstream>
 using std::cout;
