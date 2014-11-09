$NetBSD: patch-tests__perf_memcpy32_s.c,v 1.1.1.1 2014/11/09 01:52:24 agc Exp $

set but unused rc

--- tests/perf_memcpy32_s.c	2014/11/09 01:43:33	1.1
+++ tests/perf_memcpy32_s.c	2014/11/09 01:44:41
@@ -31,7 +31,7 @@
 
 static void timing_loop (uint32_t len, uint32_t loops)
 {
-    errno_t rc;
+    /* errno_t rc; */
     uint32_t i;
 
     clock_t clock_start;
@@ -56,7 +56,7 @@
      */
     clock_start = clock();
     for (i=0;i<loops; i++) {
-       rc = memcpy32_s(mem1, len, mem2, len);
+       /* rc = */ memcpy32_s(mem1, len, mem2, len);
     }
     clock_end = clock();
 
@@ -73,7 +73,7 @@
      */
     clock_start = clock();
     for (i=0;i<loops; i++) {
-       rc = memcpy16_s(mem3, len, mem4, len);
+       /* rc = */ memcpy16_s(mem3, len, mem4, len);
        //memcpy(mem1, mem2, len);
     }
     clock_end = clock();
