$NetBSD: patch-src_celengine_stardb.cpp,v 1.2 2012/07/03 17:40:36 joerg Exp $

--- src/celengine/stardb.cpp.orig	2005-11-18 07:53:39.000000000 +0000
+++ src/celengine/stardb.cpp
@@ -10,6 +10,7 @@
 #include <cmath>
 #include <cstdlib>
 #include <cstdio>
+#include <cstring>
 #include <cassert>
 #include <algorithm>
 #include <celmath/mathlib.h>
