$NetBSD: patch-src_providerifcs_cmpi_common_cmpiInstance.cpp,v 1.1 2013/03/26 23:34:35 joerg Exp $

--- src/providerifcs/cmpi/common/cmpiInstance.cpp.orig	2013-03-25 15:27:54.000000000 +0000
+++ src/providerifcs/cmpi/common/cmpiInstance.cpp
@@ -19,6 +19,7 @@
  *
  */
 
+#include <cstring>
 #include "cmpisrv.h"
 #include "OW_CIMInstance.hpp"
 
