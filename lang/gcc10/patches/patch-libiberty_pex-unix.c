$NetBSD: patch-libiberty_pex-unix.c,v 1.1 2024/04/01 14:33:58 js Exp $

QNX has spawnve and spawnvpe, which makes configure assume it's the same
spawnve / spawnvpe that exists on Windows.

--- libiberty/pex-unix.c.orig	2023-07-07 07:08:21.000000000 +0000
+++ libiberty/pex-unix.c
@@ -366,7 +366,7 @@ pex_unix_close (struct pex_obj *obj ATTR
 
 /* Execute a child.  */
 
-#if defined(HAVE_SPAWNVE) && defined(HAVE_SPAWNVPE)
+#if defined(HAVE_SPAWNVE) && defined(HAVE_SPAWNVPE) && !defined(__QNX__)
 /* Implementation of pex->exec_child using the Cygwin spawn operation.  */
 
 /* Subroutine of pex_unix_exec_child.  Move OLD_FD to a new file descriptor
