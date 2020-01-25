$NetBSD: patch-code_tools_lcc_cpp_unix.c,v 1.2 2020/01/25 20:13:50 jmcneill Exp $

Use built-in memmove on NetBSD.

--- code/tools/lcc/cpp/unix.c.orig	2020-01-25 19:19:26.823146950 +0000
+++ code/tools/lcc/cpp/unix.c
@@ -106,7 +106,7 @@ char *basepath( char *fname )
    all and others do a terrible job (like calling malloc) */
 // -- ouch, that hurts -- ln
 /* always use the system memmove() on Mac OS X. --ryan. */
-#if !defined(__APPLE__) && !defined(_MSC_VER)
+#if !defined(__APPLE__) && !defined(_MSC_VER) && !defined(__NetBSD__)
 #ifdef memmove
 #undef memmove
 #endif
