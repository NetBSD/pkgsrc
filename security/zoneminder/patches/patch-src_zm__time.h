$NetBSD: patch-src_zm__time.h,v 1.1 2026/01/07 01:03:59 gdt Exp $

--- src/zm_time.h.orig	2026-01-06 23:42:08.960420562 +0000
+++ src/zm_time.h
@@ -155,13 +155,13 @@ inline struct timeval tvCheck( struct ti
 {
   if ( t.tv_usec >= USEC_PER_SEC )
   {
-    Warning( "Timestamp too large %ld.%ld\n", t.tv_sec, (long int) t.tv_usec );
+    Warning( "Timestamp too large %jd.%ld\n", (intmax_t)t.tv_sec, (long int) t.tv_usec );
     t.tv_sec += t.tv_usec / USEC_PER_SEC;
     t.tv_usec %= USEC_PER_SEC;
   }
   else if ( t.tv_usec < 0 )
   {
-    Warning( "Got negative timestamp %ld.%ld\n", t.tv_sec, (long int)t.tv_usec );
+    Warning( "Got negative timestamp %jd.%ld\n", (intmax_t)t.tv_sec, (long int)t.tv_usec );
     t.tv_usec = 0;
   }
   return( t );
