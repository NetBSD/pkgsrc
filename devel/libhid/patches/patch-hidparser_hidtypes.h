$NetBSD: patch-hidparser_hidtypes.h,v 1.1 2016/06/15 18:38:07 rumko Exp $

ulong is not defined on FreeBSD

--- hidparser/hidtypes.h.orig	2005-09-01 12:39:04.000000000 +0000
+++ hidparser/hidtypes.h
@@ -21,7 +21,7 @@ extern "C" {
 typedef unsigned char  uchar;
 #endif
 
-#if HPUX || __APPLE__
+#if HPUX || __APPLE__ || __FreeBSD__
 typedef unsigned long  ulong;
 #endif
 
