$NetBSD: patch-filters_wrap.c,v 1.1 2024/07/24 13:50:55 ktnb Exp $

Removing XOPEN_SOURCE on NetBSD gives us access to all the locale.h
types and defines. https://todo.sr.ht/~rjarry/aerc/268

--- filters/wrap.c.orig	2024-07-21 02:04:53.703418963 +0000
+++ filters/wrap.c
@@ -1,7 +1,9 @@
 /* SPDX-License-Identifier: MIT */
 /* Copyright (c) 2023 Robin Jarry */
 
+#ifndef __NetBSD__
 #define _XOPEN_SOURCE 700
+#endif
 #include <errno.h>
 #include <getopt.h>
 #include <langinfo.h>
