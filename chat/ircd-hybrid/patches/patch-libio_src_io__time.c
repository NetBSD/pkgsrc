$NetBSD: patch-libio_src_io__time.c,v 1.1 2025/01/23 11:22:24 fox Exp $

CLOCK_MONOTONIC_RAW is linux specifc.

--- libio/src/io_time.c.orig	2025-01-23 08:28:02.545767139 +0000
+++ libio/src/io_time.c
@@ -205,8 +205,10 @@ io_internal_gettime(clockid_t clock_id, 
         return IO_TIME_ERR_GET_REAL;
       case CLOCK_MONOTONIC:
         return IO_TIME_ERR_GET_MONO;
+#ifdef CLOCK_MONOTONIC_RAW
       case CLOCK_MONOTONIC_RAW:
         return IO_TIME_ERR_GET_MONO_RAW;
+#endif
       default:
         abort();  /* Invalid clock_id, abort the program. */
     }
