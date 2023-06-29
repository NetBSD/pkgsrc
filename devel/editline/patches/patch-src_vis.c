$NetBSD: patch-src_vis.c,v 1.1 2023/06/29 16:18:56 hauke Exp $

OmniOS has MIN() in <utility.h>, which autoconf could check for.

--- src/vis.c.orig	2022-06-11 07:56:37.000000000 +0000
+++ src/vis.c
@@ -85,6 +85,10 @@ __weak_alias(strvisx,_strvisx)
 #include <stdio.h>
 #include <string.h>
 
+#ifndef MIN
+#define MIN(a,b)        (((a)<(b))?(a):(b))
+#endif
+
 /*
  * The reason for going through the trouble to deal with character encodings
  * in vis(3), is that we use this to safe encode output of commands. This
