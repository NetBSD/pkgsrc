$NetBSD: patch-src_include_refcount__ptr.h,v 1.2 2014/12/08 20:55:19 ryoon Exp $

--- src/include/refcount_ptr.h.orig	2014-08-17 08:45:13.000000000 +0000
+++ src/include/refcount_ptr.h
@@ -33,6 +33,8 @@ template <class T>
 class refcount_ptr;
 
 
+#include <stddef.h>
+
 /**
  * \brief Base class for reference countable objects.
  *
