$NetBSD: patch-libstdc++-v3_libsupc++_unwind-cxx.h,v 1.1 2020/04/14 22:02:21 js Exp $

--- libstdc++-v3/libsupc++/unwind-cxx.h.orig	2020-01-25 15:10:52.346666839 +0000
+++ libstdc++-v3/libsupc++/unwind-cxx.h
@@ -37,7 +37,7 @@
 #include <bits/atomic_word.h>
 #include <cxxabi.h>
 
-#ifdef _GLIBCXX_HAVE_SYS_SDT_H
+#if 0  // _GLIBCXX_HAVE_SYS_SDT_H wrongly detected
 #include <sys/sdt.h>
 /* We only want to use stap probes starting with v3.  Earlier versions
    added too much startup cost.  */
