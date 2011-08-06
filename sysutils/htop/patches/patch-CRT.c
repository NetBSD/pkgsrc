$NetBSD: patch-CRT.c,v 1.1 2011/08/06 16:36:41 cheusov Exp $

--- CRT.c.orig	2010-11-23 15:56:32.000000000 +0000
+++ CRT.c
@@ -11,7 +11,9 @@ in the source distribution for its full 
 #include <signal.h>
 #include <stdlib.h>
 #include <stdbool.h>
+#ifdef HAVE_EXECINFO_H
 #include <execinfo.h>
+#endif
 
 #include "String.h"
 
@@ -118,7 +120,9 @@ int CRT_colors[LAST_COLORELEMENT] = { 0 
 
 char* CRT_termType;
 
+#ifdef HAVE_EXECINFO_H
 void *backtraceArray[128];
+#endif
 
 static void CRT_handleSIGSEGV(int sgn) {
    (void) sgn;
@@ -128,9 +132,11 @@ static void CRT_handleSIGSEGV(int sgn) {
    #else
    fprintf(stderr, "\n\nhtop " VERSION " aborting. Unsupported platform.\n");
    #endif
+   #ifdef HAVE_EXECINFO_H
    size_t size = backtrace(backtraceArray, sizeof(backtraceArray));
    fprintf(stderr, "Backtrace: \n");
    backtrace_symbols_fd(backtraceArray, size, 2);
+   #endif
    abort();
 }
 
