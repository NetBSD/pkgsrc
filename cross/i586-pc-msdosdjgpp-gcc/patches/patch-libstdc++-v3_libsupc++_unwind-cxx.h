$NetBSD: patch-libstdc++-v3_libsupc++_unwind-cxx.h,v 1.1 2024/03/27 14:38:33 js Exp $

--- libstdc++-v3/libsupc++/unwind-cxx.h.orig	2024-03-27 12:19:06.576679924 +0000
+++ libstdc++-v3/libsupc++/unwind-cxx.h
@@ -37,7 +37,7 @@
 #include <bits/atomic_word.h>
 #include <cxxabi.h>
 
-#ifdef _GLIBCXX_HAVE_SYS_SDT_H
+#if defined(_GLIBCXX_HAVE_SYS_SDT_H) && !defined(__DJGPP__)
 #include <sys/sdt.h>
 /* We only want to use stap probes starting with v3.  Earlier versions
    added too much startup cost.  */
