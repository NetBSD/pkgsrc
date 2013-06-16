$NetBSD: patch-src_lib_ecore_Ecore.h,v 1.2 2013/06/16 18:56:04 sno Exp $

DragonflyBSD needs that, too

--- src/lib/ecore/Ecore.h.orig	2013-01-09 13:46:27.000000000 +0000
+++ src/lib/ecore/Ecore.h
@@ -356,7 +356,7 @@ sudo make install
 
 #ifdef _WIN32
 # include <winsock2.h>
-#elif defined (__FreeBSD__) || defined (__OpenBSD__)
+#elif defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__DragonFly__)
 # include <sys/select.h>
 # include <signal.h>
 #elif defined (__ANDROID__)
