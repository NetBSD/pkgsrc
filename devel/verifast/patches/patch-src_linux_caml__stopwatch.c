$NetBSD: patch-src_linux_caml__stopwatch.c,v 1.1 2017/09/09 21:57:46 dholland Exp $

Don't intrude on the implementation namespace. It breaks the clang build.

--- src/linux/caml_stopwatch.c~	2017-06-13 16:58:54.000000000 +0000
+++ src/linux/caml_stopwatch.c
@@ -10,7 +10,7 @@ value caml_stopwatch_getpid() {
 
 #if defined(__i386__)
 
-static __inline__ unsigned long long __rdtsc(void)
+static __inline__ unsigned long long do_rdtsc(void)
 {
     unsigned long long int x;
     __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
@@ -19,7 +19,7 @@ static __inline__ unsigned long long __r
 
 #elif defined(__x86_64__)
 
-static __inline__ unsigned long long __rdtsc(void)
+static __inline__ unsigned long long do_rdtsc(void)
 {
     unsigned hi, lo;
     __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
@@ -28,7 +28,7 @@ static __inline__ unsigned long long __r
 
 #else
 
-static __inline__ unsigned long long __rdtsc(void)
+static __inline__ unsigned long long do_rdtsc(void)
 {
     return 0;
 }
@@ -47,7 +47,7 @@ value caml_lock_process_to_processor_1()
 }
 
 value caml_stopwatch_processor_ticks() {
-    return copy_int64(__rdtsc());
+    return copy_int64(do_rdtsc());
 }
 
 struct stopwatch {
@@ -66,13 +66,13 @@ value caml_stopwatch_create() {
 
 value caml_stopwatch_start(value stopwatch) {
     struct stopwatch *s = (void *)stopwatch;
-    s->startTimestamp = __rdtsc();
+    s->startTimestamp = do_rdtsc();
     return Val_unit;
 }
 
 value caml_stopwatch_stop(value stopwatch) {
     struct stopwatch *s = (void *)stopwatch;
-    unsigned long long tsc = __rdtsc();
+    unsigned long long tsc = do_rdtsc();
     s->counter += tsc - s->startTimestamp;
     s->startTimestamp = NO_TIMESTAMP;
     return Val_unit;
