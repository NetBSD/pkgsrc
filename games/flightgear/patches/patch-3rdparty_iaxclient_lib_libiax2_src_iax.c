$NetBSD: patch-3rdparty_iaxclient_lib_libiax2_src_iax.c,v 1.1 2018/12/04 03:56:27 nia Exp $

Support NetBSD.

--- 3rdparty/iaxclient/lib/libiax2/src/iax.c.orig	2018-06-03 18:56:53.000000000 +0000
+++ 3rdparty/iaxclient/lib/libiax2/src/iax.c
@@ -73,7 +73,7 @@
 #include <time.h>
 
 // FlightGear: Modified to include FreeBSD
-#if !defined(MACOSX) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
+#if !defined(MACOSX) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <malloc.h>
 #if !defined(SOLARIS)
 #include <error.h>
