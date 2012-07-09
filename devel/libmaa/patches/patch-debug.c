$NetBSD: patch-debug.c,v 1.2 2012/07/09 19:09:09 joerg Exp $

--- debug.c.orig	2012-07-05 12:00:08.000000000 +0000
+++ debug.c
@@ -173,7 +173,7 @@ void dbg_unset_flag( dbg_Type flag )
 /* \doc This inlined function tests the |flag|, returning non-zero if the
    |flag| is set, and zero otherwise. */
 
-__inline__ int dbg_test( dbg_Type flag )
+int dbg_test( dbg_Type flag )
 {
    return TEST( flag, setFlags );
 }
$NetBSD: patch-debug.c,v 1.2 2012/07/09 19:09:09 joerg Exp $

--- debug.c.orig	2012-07-05 12:00:08.000000000 +0000
+++ debug.c
@@ -173,7 +173,7 @@ void dbg_unset_flag( dbg_Type flag )
 /* \doc This inlined function tests the |flag|, returning non-zero if the
    |flag| is set, and zero otherwise. */
 
-__inline__ int dbg_test( dbg_Type flag )
+int dbg_test( dbg_Type flag )
 {
    return TEST( flag, setFlags );
 }
