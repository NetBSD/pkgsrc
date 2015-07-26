$NetBSD: patch-mytypes.h,v 1.2.8.1 2015/07/26 19:57:43 tron Exp $

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
