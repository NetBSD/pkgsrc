$NetBSD: patch-code_tools_lcc_cpp_unix.c,v 1.1 2020/01/25 16:07:15 jmcneill Exp $

Use built-in memmove on NetBSD.

--- code/tools/lcc/cpp/unix.c.orig	2008-04-23 17:39:39.000000000 +0000
+++ code/tools/lcc/cpp/unix.c
@@ -99,7 +99,7 @@ char *basepath( char *fname )
 /* memmove is defined here because some vendors don't provide it at
    all and others do a terrible job (like calling malloc) */
 // -- ouch, that hurts -- ln
-#ifndef MACOS_X   /* always use the system memmove() on Mac OS X. --ryan. */
+#if !defined(MACOS_X) && !defined(__NetBSD__)   /* always use the system memmove() */
 #ifdef memmove
 #undef memmove
 #endif
