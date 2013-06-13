$NetBSD: patch-xen_include_xen_lib.h,v 1.1 2013/06/13 21:49:59 joerg Exp $

--- xen/include/xen/lib.h.orig	2013-06-13 19:59:04.000000000 +0000
+++ xen/include/xen/lib.h
@@ -42,7 +42,7 @@ do {                                    
 #define ASSERT(p) \
     do { if ( unlikely(!(p)) ) assert_failed(#p); } while (0)
 #else
-#define ASSERT(p) do { if ( 0 && (p) ); } while (0)
+#define ASSERT(p) do { if ( 0 && (p) ) (void)0; } while (0)
 #endif
 
 #define ABS(_x) ({                              \
