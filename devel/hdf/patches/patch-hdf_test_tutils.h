$NetBSD: patch-hdf_test_tutils.h,v 1.1 2022/04/24 21:50:48 tnn Exp $

--- hdf/test/tutils.h.orig	2020-03-03 17:40:50.000000000 +0000
+++ hdf/test/tutils.h
@@ -114,7 +114,7 @@ if(ret == FAIL) {printf("*** UNEXPECTED 
 #define H4_SKIPPED()       {puts(" -SKIP-");fflush(stdout);}
 
 /* Definition for JPEG tests */
-#ifdef DEC_ALPHA
+#if defined(DEC_ALPHA) || defined(__alpha__)
 #define JPEG_FUZZ 13
 #else
 #define JPEG_FUZZ 1
