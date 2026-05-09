$NetBSD: patch-src_RtMidi.h,v 1.2 2026/05/09 14:24:05 fox Exp $

pthread_yield() is not in NetBSD's pthread. Provide sched_yield() instead.

--- src/RtMidi.h.orig	2026-03-02 18:05:40.000000000 +0000
+++ src/RtMidi.h
@@ -49,6 +49,11 @@
 #include <string>
 #include <vector>
 
+#if defined __NetBSD__
+#include <sched.h>
+#define pthread_yield()	sched_yield()
+#endif
+
 class RtMidi
 {
  public:
