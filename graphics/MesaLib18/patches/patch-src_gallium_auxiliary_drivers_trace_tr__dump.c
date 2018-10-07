$NetBSD: patch-src_gallium_auxiliary_drivers_trace_tr__dump.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

atexit() is not a good idea in shared libraries.

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

--- src/gallium/auxiliary/driver_trace/tr_dump.c.orig	2018-09-07 21:18:07.000000000 +0000
+++ src/gallium/auxiliary/driver_trace/tr_dump.c
@@ -63,7 +63,6 @@ static mtx_t call_mutex = _MTX_INITIALIZ
 static long unsigned call_no = 0;
 static boolean dumping = FALSE;
 
-
 static inline void
 trace_dump_write(const char *buf, size_t size)
 {
@@ -171,9 +170,20 @@ trace_dump_trace_flush(void)
    }
 }
 
+#if defined(HAVE_NOATEXIT)
+static boolean trace_dump_has_begun = FALSE;
+
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 trace_dump_trace_close(void)
 {
+#if defined(HAVE_NOATEXIT)
+   if (!trace_dump_has_begun)
+      return;
+#endif
+
    if (stream) {
       trace_dump_writes("</trace>\n");
       if (close_stream) {
@@ -233,7 +243,11 @@ trace_dump_trace_begin(void)
        * screen multiple times, so we only write </trace> tag and close at exit
        * time.
        */
+#if defined(HAVE_NOATEXIT)
+      trace_dump_has_begun = TRUE;
+#else
       atexit(trace_dump_trace_close);
+#endif
    }
 
    return TRUE;
