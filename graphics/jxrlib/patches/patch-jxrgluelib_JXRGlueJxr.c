$NetBSD: patch-jxrgluelib_JXRGlueJxr.c,v 1.1 2019/11/25 21:07:19 nros Exp $
* fix missing declaration of wcslen
--- jxrgluelib/JXRGlueJxr.c.orig	2013-03-20 19:01:13.000000000 +0000
+++ jxrgluelib/JXRGlueJxr.c
@@ -27,6 +27,7 @@
 //
 //*@@@---@@@@******************************************************************
 #include <limits.h>
+#include <wchar.h>
 #include <JXRGlue.h>
 
 
