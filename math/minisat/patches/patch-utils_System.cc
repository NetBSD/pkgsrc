$NetBSD: patch-utils_System.cc,v 1.1.1.1 2013/10/28 04:15:11 asau Exp $

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
