$NetBSD: patch-storage_ndb_src_ndbapi_NdbEventOperationImpl.cpp,v 1.1 2025/05/05 22:22:11 wiz Exp $

Add missing header for std::numeric_limits.

--- storage/ndb/src/ndbapi/NdbEventOperationImpl.cpp.orig	2025-05-05 22:16:40.248400152 +0000
+++ storage/ndb/src/ndbapi/NdbEventOperationImpl.cpp
@@ -27,6 +27,7 @@
 #include <ndb_global.h>
 #include <NdbOut.hpp>
 #include <cstring>
+#include <limits>
 #include <vector>
 #include "API.hpp"
 #include "m_ctype.h"
