$NetBSD: patch-liboctave_wrappers_iconv-wrappers.h,v 1.1 2019/03/05 11:11:12 ryoon Exp $

* Do not conflict between header and body

--- liboctave/wrappers/iconv-wrappers.h.orig	2019-02-23 17:33:37.000000000 +0000
+++ liboctave/wrappers/iconv-wrappers.h
@@ -23,15 +23,17 @@ along with Octave; see the file COPYING.
 #if ! defined (octave_iconv_wrappers_h)
 #define octave_iconv_wrappers_h 1
 
+#include <iconv.h>
+
 #if defined __cplusplus
 extern "C" {
 #endif
 
-extern void *
+extern iconv_t
 octave_iconv_open_wrapper (const char *tocode, const char *fromcode);
 
 extern int
-octave_iconv_close_wrapper (void *cd);
+octave_iconv_close_wrapper (iconv_t cd);
 
 #if defined __cplusplus
 }
