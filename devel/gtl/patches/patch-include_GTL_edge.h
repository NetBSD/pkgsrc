$NetBSD: patch-include_GTL_edge.h,v 1.1 2011/11/25 21:44:06 joerg Exp $

--- include/GTL/edge.h.orig	2011-11-25 18:11:51.000000000 +0000
+++ include/GTL/edge.h
@@ -11,6 +11,7 @@
 
 #include <GTL/GTL.h>
 
+#include <ostream>
 #include <list>
 
 __GTL_BEGIN_NAMESPACE
