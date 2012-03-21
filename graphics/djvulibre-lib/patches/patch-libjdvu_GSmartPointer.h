$NetBSD: patch-libjdvu_GSmartPointer.h,v 1.1 2012/03/21 20:03:31 hans Exp $

--- libdjvu/GSmartPointer.h.orig	2011-03-06 18:43:17.000000000 +0100
+++ libdjvu/GSmartPointer.h	2012-03-21 20:54:17.483636113 +0100
@@ -97,6 +97,10 @@
 #include "DjVuGlobal.h"
 #include "atomic.h"
 
+#if defined(HAVE_SYS_TYPES_H)
+#include <sys/types.h>
+#endif
+
 #ifdef HAVE_NAMESPACES
 namespace DJVU {
 # ifdef NOT_DEFINED // Just to fool emacs c++ mode
