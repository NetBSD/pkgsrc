$NetBSD: patch-Include_numarray_arraybase.h,v 1.1 2015/01/27 05:05:30 dbj Exp $

--- Include/numarray/arraybase.h.orig	2006-01-23 11:45:03.000000000 +0000
+++ Include/numarray/arraybase.h
@@ -42,7 +42,12 @@ typedef struct { Float64 r, i; } Complex
 
 #if LP64
 typedef long int                 Int64;
+#ifdef __APPLE__
+/* match the definition in MacTypes.h */
+typedef unsigned long long       UInt64;
+#else
 typedef unsigned long int        UInt64;
+#endif
 typedef Int64                    Long;
 #else                  /* 32-bit platforms */
 typedef Int32                    Long;
