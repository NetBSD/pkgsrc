$NetBSD: patch-source_mini-unzip_ioapi.c,v 1.1 2024/03/22 09:00:43 nia Exp $

fopen64 is not available on non-Linux platforms in general.

--- source/mini-unzip/ioapi.c.orig	2024-03-22 08:28:31.586891184 +0000
+++ source/mini-unzip/ioapi.c
@@ -16,7 +16,7 @@
 
 #include "ioapi.h"
 
-#if defined(DARWIN) || defined(ANDROID)
+#if !defined(__linux__)
 #define fopen64 fopen
 #define ftello64 ftello
 #define fseeko64 fseeko
