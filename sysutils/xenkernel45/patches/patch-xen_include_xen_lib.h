$NetBSD: patch-xen_include_xen_lib.h,v 1.2 2015/06/23 17:45:33 bouyer Exp $

--- xen/include/xen/lib.h.orig	2015-06-22 15:41:35.000000000 +0200
+++ xen/include/xen/lib.h	2015-06-23 18:32:26.000000000 +0200
@@ -44,7 +44,7 @@
 #define ASSERT_UNREACHABLE() assert_failed("unreachable")
 #define debug_build() 1
 #else
-#define ASSERT(p) do { if ( 0 && (p) ); } while (0)
+#define ASSERT(p) do { if ( 0 && (p) ) (void)0; } while (0)
 #define ASSERT_UNREACHABLE() do { } while (0)
 #define debug_build() 0
 #endif
