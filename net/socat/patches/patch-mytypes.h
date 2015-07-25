$NetBSD: patch-mytypes.h,v 1.3 2015/07/25 14:43:23 bsiegert Exp $

Use stdbool.

--- mytypes.h.orig	2010-10-06 07:25:30.000000000 +0000
+++ mytypes.h
@@ -10,6 +10,7 @@
 #ifndef HAVE_TYPE_BOOL
 #  undef bool
 typedef enum { false, true } bool;
+#include <stdbool.h>
 #endif
 
 #ifndef Min
