$NetBSD: patch-src_providerifcs_npi_common_NPIExternal.hpp,v 1.1 2013/03/26 23:34:35 joerg Exp $

--- src/providerifcs/npi/common/NPIExternal.hpp.orig	2013-03-25 15:25:53.000000000 +0000
+++ src/providerifcs/npi/common/NPIExternal.hpp
@@ -17,6 +17,7 @@
 #ifndef NPIExternal_h
 #define NPIExternal_h
 #include "OW_FTABLERef.hpp"
+#include <cstdlib>
 
 namespace OW_NAMESPACE
 {
