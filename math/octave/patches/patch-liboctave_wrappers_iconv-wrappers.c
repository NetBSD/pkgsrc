$NetBSD: patch-liboctave_wrappers_iconv-wrappers.c,v 1.2 2021/06/14 22:39:01 wiz Exp $

 * fix iconv_t void* confict pkg/56240
 from upstream:
 https://hg.savannah.gnu.org/hgweb/octave/rev/69087119ee84

--- liboctave/wrappers/iconv-wrappers.c.orig	2021-02-19 17:36:34.000000000 +0000
+++ liboctave/wrappers/iconv-wrappers.c
@@ -31,14 +31,14 @@
 
 #include "iconv-wrappers.h"
 
-iconv_t
+void *
 octave_iconv_open_wrapper (const char *tocode, const char *fromcode)
 {
-  return iconv_open (tocode, fromcode);
+  return (void *) iconv_open (tocode, fromcode);
 }
 
 int
-octave_iconv_close_wrapper (iconv_t cd)
+octave_iconv_close_wrapper (void * cd)
 {
-  return iconv_close (cd);
+  return iconv_close ((iconv_t) cd);
 }
