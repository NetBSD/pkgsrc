$NetBSD: patch-goo_gfile.h,v 1.1 2018/04/17 05:20:55 wiz Exp $

Include sys/time.h for struct timespec.
https://bugs.freedesktop.org/show_bug.cgi?id=106091

--- goo/gfile.h.orig	2018-03-18 18:23:49.000000000 +0000
+++ goo/gfile.h
@@ -37,6 +37,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <stddef.h>
+#include <sys/time.h>
 extern "C" {
 #if defined(_WIN32)
 #  include <sys/stat.h>
