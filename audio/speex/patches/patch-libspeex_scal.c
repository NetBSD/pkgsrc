$NetBSD: patch-libspeex_scal.c,v 1.1 2014/01/01 03:03:02 ryoon Exp $

Fix build on Fedora 22.
From upstream,
http://git.xiph.org/?p=speex.git;a=commitdiff_plain;h=42ef4a1d79eb85d450686e633500bc85450d8036

--- libspeex/scal.c.orig	2008-06-05 09:27:47.000000000 +0000
+++ libspeex/scal.c
@@ -52,6 +52,10 @@ The algorithm implemented here is descri
 #include <math.h>
 #include <stdlib.h>
 
+#ifndef M_PI
+#define M_PI	3.14159265358979323846  /* pi */
+#endif
+
 #define ALLPASS_ORDER 20
 
 struct SpeexDecorrState_ {
