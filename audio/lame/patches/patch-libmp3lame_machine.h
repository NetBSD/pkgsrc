$NetBSD: patch-libmp3lame_machine.h,v 1.1 2026/07/15 07:09:51 adam Exp $

Add <float.h> include.

--- libmp3lame/machine.h.orig	2026-07-10 18:16:21.000000000 +0000
+++ libmp3lame/machine.h
@@ -127,6 +127,7 @@ char   *strchr(), *strrchr();
 # include <float.h>
 # define FLOAT_MAX FLT_MAX
 #else
+# include <float.h>
 # ifndef FLOAT
 typedef float FLOAT;
 #  ifdef FLT_MAX
