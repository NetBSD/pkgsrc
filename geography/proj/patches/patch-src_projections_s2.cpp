$NetBSD: patch-src_projections_s2.cpp,v 1.1 2024/06/10 09:41:52 jperkin Exp $

Fix C++ includes.

--- src/projections/s2.cpp.orig	2024-06-10 09:37:49.864562641 +0000
+++ src/projections/s2.cpp
@@ -52,6 +52,7 @@
 
 #include <errno.h>
 #include <cmath>
+#include <cstdint>
 
 #include "proj.h"
 #include "proj_internal.h"
