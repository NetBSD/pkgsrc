$NetBSD: patch-poppler_CMap.cc,v 1.1 2018/04/17 05:20:55 wiz Exp $

Include sys/time.h for struct timespec.
https://bugs.freedesktop.org/show_bug.cgi?id=106091

--- poppler/CMap.cc.orig	2018-03-18 18:23:49.000000000 +0000
+++ poppler/CMap.cc
@@ -33,6 +33,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#include <sys/time.h>
 #include "goo/gmem.h"
 #include "goo/gfile.h"
 #include "goo/GooString.h"
