$NetBSD: patch-utils_System.cc,v 1.2 2014/01/09 14:38:33 jperkin Exp $

Support NetBSD.

--- utils/System.cc.orig	2010-07-10 16:07:36.000000000 +0000
+++ utils/System.cc
@@ -72,13 +72,13 @@ double Minisat::memUsedPeak() {
     double peak = memReadPeak() / 1024;
     return peak == 0 ? memUsed() : peak; }
 
-#elif defined(__FreeBSD__)
+#elif defined(__NetBSD__) || defined(__FreeBSD__)
 
 double Minisat::memUsed(void) {
     struct rusage ru;
     getrusage(RUSAGE_SELF, &ru);
     return (double)ru.ru_maxrss / 1024; }
-double MiniSat::memUsedPeak(void) { return memUsed(); }
+double Minisat::memUsedPeak(void) { return memUsed(); }
 
 
 #elif defined(__APPLE__)
@@ -92,4 +92,6 @@ double Minisat::memUsed(void) {
 #else
 double Minisat::memUsed() { 
     return 0; }
+double Minisat::memUsedPeak() { 
+    return 0; }
 #endif
