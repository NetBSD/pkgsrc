$NetBSD: patch-xen_include_xen_lib.h,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- xen/include/xen/lib.h.orig	2015-01-12 17:53:24.000000000 +0100
+++ xen/include/xen/lib.h	2015-01-19 12:30:35.000000000 +0100
@@ -43,7 +43,7 @@
     do { if ( unlikely(!(p)) ) assert_failed(#p); } while (0)
 #define debug_build() 1
 #else
-#define ASSERT(p) do { if ( 0 && (p) ); } while (0)
+#define ASSERT(p) do { if ( 0 && (p) ) (void)0; } while (0)
 #define debug_build() 0
 #endif
 
