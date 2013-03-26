$NetBSD: patch-src_common_OW__COWReference.hpp,v 1.1 2013/03/26 23:34:34 joerg Exp $

--- src/common/OW_COWReference.hpp.orig	2013-03-25 15:04:13.000000000 +0000
+++ src/common/OW_COWReference.hpp
@@ -35,6 +35,7 @@
 #ifndef OW_COWREFERENCE_HPP_INCLUDE_GUARD_
 #define OW_COWREFERENCE_HPP_INCLUDE_GUARD_
 #include "OW_config.h"
+#include "OW_vector.hpp"
 #include "OW_COWReferenceBase.hpp"
 
 namespace OW_NAMESPACE
