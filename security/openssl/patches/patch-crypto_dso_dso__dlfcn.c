$NetBSD: patch-crypto_dso_dso__dlfcn.c,v 1.1 2013/07/26 11:27:02 ryoon Exp $

* Debian GNU/kFreeBSD needs _GNU_SOURCE.

--- crypto/dso/dso_dlfcn.c.orig	2013-02-11 15:26:04.000000000 +0000
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
