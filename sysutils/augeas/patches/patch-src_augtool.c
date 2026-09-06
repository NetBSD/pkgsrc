$NetBSD: patch-src_augtool.c,v 1.1 2026/09/06 18:44:02 bsiegert Exp $

Print elapsed time with a format that matches time_t.

time_t is 64 bits on NetBSD while long is 32 bits on the 32 bit ports, so
"%ld" is the wrong conversion and gcc says so:

  augtool.c:469:21: warning: format '%ld' expects argument of type 'long int',
  but argument 2 has type 'time_t {aka long long int}' [-Wformat=]

Cast rather than assume time_t is long long.  Still present upstream, with
no issue or pull request open about it; OpenBSD carries the same fix.

--- src/augtool.c.orig
+++ src/augtool.c
@@ -466,7 +466,7 @@
                              const struct timeval *stop) {
     time_t elapsed = (stop->tv_sec - start->tv_sec)*1000
                    + (stop->tv_usec - start->tv_usec)/1000;
-    printf("Time: %ld ms\n", elapsed);
+    printf("Time: %lld ms\n", (long long) elapsed);
 }
 
 static int run_command(const char *line, bool with_timing) {
