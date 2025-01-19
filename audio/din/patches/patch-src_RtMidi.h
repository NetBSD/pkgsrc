$NetBSD: patch-src_RtMidi.h,v 1.1 2025/01/19 21:32:47 fox Exp $

pthread_yield() is not in NetBSD's pthread. Provide sched_yield() instead.

--- src/RtMidi.h.orig	2024-08-05 22:04:30.000000000 +0000
+++ src/RtMidi.h
@@ -65,6 +65,10 @@
 #include <string>
 #include <vector>
 
+#if defined __NetBSD__ 
+#include <sched.h>
+#define pthread_yield()	sched_yield()
+#endif
 
 /************************************************************************/
 /*! \class RtMidiError
