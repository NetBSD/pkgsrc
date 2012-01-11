$NetBSD: patch-src_global.cc,v 1.1 2012/01/11 19:20:13 hans Exp $

--- src/global.cc.orig	2009-01-24 16:25:10.000000000 +0100
+++ src/global.cc	2011-12-30 18:09:44.289850163 +0100
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <dirent.h>
