$NetBSD: patch-mozilla_mfbt_Atomics.h,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/mfbt/Atomics.h.orig	2013-10-23 22:09:13.000000000 +0000
+++ mozilla/mfbt/Atomics.h
@@ -37,7 +37,7 @@
     */
 #  if !defined(__linux__) && !defined(__OpenBSD__) && \
       (__cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)) && \
-      __has_include(<atomic>)
+      __has_include_next(<atomic>)
 #    define MOZ_HAVE_CXX11_ATOMICS
 #  endif
 /*
