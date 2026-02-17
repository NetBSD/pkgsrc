$NetBSD: patch-src_rjcommon.h,v 1.1 2026/02/17 01:20:11 mef Exp $

NetBSD/amd64 9.4

gcc -I"/usr/pkg/lib/R/include" -DNDEBUG   -I/usr/pkg/include -I/usr/include -I/usr/pkg/include/glib-2.0 -I/usr/pkg/include/gio-unix-2.0 -I/usr/pkg/lib/glib-2.0/include -Dz_off_t=long -I/usr/X11R7/include -I/usr/pkg/include/freetype2 -I/usr/pkg/include/harfbuzz -I/usr/pkg/include/libxml2    -fpic  -O2 -pthread -I/usr/pkg/include -I/usr/include -I/usr/pkg/include/glib-2.0 -I/usr/pkg/include/gio-unix-2.0 -I/usr/pkg/lib/glib-2.0/include -Dz_off_t=long -I/usr/X11R7/include -I/usr/pkg/include/freetype2 -I/usr/pkg/include/harfbuzz -I/usr/pkg/include/libxml2  -c read.c -o read.o
In file included from rjcommon.h:24:0,
                 from read.c:1:
/tmp/graphics/R-jpeg/work/.buildlink/lib/R/include/Rinternals.h:491:1: error: unknown type name 'bool'; did you mean '_Bool'?
 bool Rf_asBool(SEXP x);
 ^~~~
 _Bool
*** Error code 1

--- src/rjcommon.h.orig	2022-11-29 18:23:07.000000000 +0900
+++ src/rjcommon.h	2026-02-17 09:56:07.128931431 +0900
@@ -7,6 +7,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <stdbool.h>
 
 #include <jpeglib.h>
 
