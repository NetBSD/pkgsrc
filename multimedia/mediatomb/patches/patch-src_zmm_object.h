$NetBSD: patch-src_zmm_object.h,v 1.1 2013/10/24 10:53:28 jperkin Exp $

Need cstddef on SunOS.

--- src/zmm/object.h.orig	2010-03-25 14:58:08.000000000 +0000
+++ src/zmm/object.h
@@ -33,6 +33,7 @@
 #define __ZMM_OBJECT_H__
 
 #include <new> // for size_t
+#include <cstddef>
 #include "atomic.h"
 
 namespace zmm
