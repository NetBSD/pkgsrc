$NetBSD: patch-posix_JackPosixSemaphore.cpp,v 1.2 2023/01/07 21:20:19 triaxx Exp $

NetBSD requires POSIX semaphores to be prefixed with
a slash, see sem_open(3).

--- posix/JackPosixSemaphore.cpp.orig	2022-04-15 19:14:06.000000000 +0000
+++ posix/JackPosixSemaphore.cpp
@@ -29,7 +29,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include "promiscuous.h"
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #define JACK_SEM_PREFIX "/jack_sem"
 #define SEM_DEFAULT_O 0
 #else
