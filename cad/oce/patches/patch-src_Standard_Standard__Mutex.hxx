$NetBSD: patch-src_Standard_Standard__Mutex.hxx,v 1.1 2017/01/20 11:00:50 fhajny Exp $

Portability.

--- src/Standard/Standard_Mutex.hxx.orig	2015-03-08 22:19:42.000000000 +0000
+++ src/Standard/Standard_Mutex.hxx
@@ -24,7 +24,7 @@
   #include <windows.h>
 #else
   #include <pthread.h>
-  #include <sys/errno.h>
+  #include <errno.h>
   #include <unistd.h>
   #include <time.h>
 #endif
