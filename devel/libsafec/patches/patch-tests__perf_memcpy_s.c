$NetBSD: patch-tests__perf_memcpy_s.c,v 1.1.1.1 2014/11/09 01:52:24 agc Exp $

set but unused rc

--- tests/perf_memcpy_s.c	2014/11/09 01:43:33	1.1
+++ tests/perf_memcpy_s.c	2014/11/09 01:45:02
@@ -28,7 +28,7 @@
 
 static void timing_loop (uint32_t len, uint32_t loops)
 {
-    errno_t rc;
+    /* errno_t rc; */
     uint32_t i;
 
     clock_t clock_start;
@@ -51,7 +51,7 @@
      */
     clock_start = clock();
     for (i=0;i<loops; i++) {
-       rc = memcpy_s(mem1, len, mem2, len);
+       /* rc = */memcpy_s(mem1, len, mem2, len);
     }
     clock_end = clock();
 
