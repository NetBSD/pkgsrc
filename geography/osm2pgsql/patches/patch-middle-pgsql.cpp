$NetBSD: patch-middle-pgsql.cpp,v 1.1 2015/06/10 01:48:49 wiedi Exp $

Need alloca.h on SunOS

--- middle-pgsql.cpp.orig	2015-04-30 04:15:07.000000000 +0000
+++ middle-pgsql.cpp
@@ -33,6 +33,10 @@ using namespace std;
 #define alloca _alloca
 #endif
 
+#if defined(__sun)
+#include <alloca.h>
+#endif
+
 #include <libpq-fe.h>
 
 #include "osmtypes.hpp"
