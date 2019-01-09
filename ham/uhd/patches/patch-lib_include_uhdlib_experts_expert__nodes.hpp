$NetBSD: patch-lib_include_uhdlib_experts_expert__nodes.hpp,v 1.1 2019/01/09 01:28:45 gdt Exp $

https://github.com/EttusResearch/uhd/issues/240

--- lib/include/uhdlib/experts/expert_nodes.hpp.orig	2018-08-01 03:30:31.000000000 +0000
+++ lib/include/uhdlib/experts/expert_nodes.hpp
@@ -12,6 +12,7 @@
 #include <uhd/exception.hpp>
 #include <uhd/utils/dirty_tracked.hpp>
 #include <uhd/types/time_spec.hpp>
+#include <boost/core/noncopyable.hpp>
 #include <boost/function.hpp>
 #include <boost/thread/recursive_mutex.hpp>
 #include <boost/thread.hpp>
