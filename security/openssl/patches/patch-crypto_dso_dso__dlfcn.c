$NetBSD: patch-crypto_dso_dso__dlfcn.c,v 1.2 2014/05/13 02:23:11 rodent Exp $

* Debian GNU/kFreeBSD needs _GNU_SOURCE.

--- crypto/dso/dso_dlfcn.c.orig	Mon Mar 17 16:14:20 2014
+++ crypto/dso/dso_dlfcn.c
@@ -60,7 +60,7 @@
    that handle _GNU_SOURCE and other similar macros.  Defining it later
    is simply too late, because those headers are protected from re-
    inclusion.  */
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD_kernel__)
 # ifndef _GNU_SOURCE
 #  define _GNU_SOURCE	/* make sure dladdr is declared */
 # endif
