$NetBSD: patch-libiberty_pex-unix.c,v 1.1 2026/04/20 03:49:24 js Exp $

--- libiberty/pex-unix.c.orig	2025-06-15 13:09:05.276043172 +0000
+++ libiberty/pex-unix.c
@@ -42,9 +42,7 @@ extern int errno;
 
 #include <sys/types.h>
 
-#ifdef HAVE_FCNTL_H
 #include <fcntl.h>
-#endif
 #ifdef HAVE_SYS_WAIT_H
 #include <sys/wait.h>
 #endif
@@ -58,7 +56,7 @@ extern int errno;
 #ifdef HAVE_PROCESS_H
 #include <process.h>
 #endif
-#ifdef HAVE_SPAWN_H
+#if defined(HAVE_SPAWN_H) || defined(__linux__)
 #include <spawn.h>
 #endif
 
