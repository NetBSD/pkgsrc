$NetBSD: patch-src_Backtrace.cc,v 1.1 2026/11/14 21:36:38 drixter Exp $

SunOS fix: Add alloca.h which is needed

--- src/Backtrace.cc.orig	Wed Oct 14 19:51:00 2026
+++ src/Backtrace.cc	Wed Oct 14 19:51:00 2026
@@ -32,6 +32,9 @@
 #include <sys/stat.h>

 #include "Common.hh"   // for HAVE_EXECINFO_H et al.
+#if defined(__sun)
+#include <alloca.h>
+#endif
 #ifdef HAVE_EXECINFO_H
 # include <execinfo.h>
 # include <cxxabi.h>
