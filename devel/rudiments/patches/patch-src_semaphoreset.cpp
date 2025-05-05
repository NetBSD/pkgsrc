$NetBSD: patch-src_semaphoreset.cpp,v 1.1 2025/05/05 22:00:49 wiz Exp $

Add missing header for 'struct timespec'.

--- src/semaphoreset.cpp.orig	2025-05-05 21:56:55.178754274 +0000
+++ src/semaphoreset.cpp
@@ -20,6 +20,10 @@
 	#include <windows.h>
 #endif
 
+#ifdef RUDIMENTS_HAVE_SEMTIMEDOP
+	#include <sys/time.h>
+#endif
+
 #ifdef RUDIMENTS_HAVE_SYS_SEM_H
 	// for struct sembuf
 	#include <sys/sem.h>
