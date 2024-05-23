$NetBSD: patch-compatlib_imp__funopen.c,v 1.1 2024/05/23 19:16:01 cheusov Exp $

Resolve conflict with libbsd stdlib.h

--- compatlib/imp_funopen.c.orig	2024-05-23 18:17:48.244149500 +0000
+++ compatlib/imp_funopen.c
@@ -142,7 +142,7 @@ funopen(void *cookie,
 }
 #else
 FILE *
-funopen(void *cookie,
+funopen(const void *cookie,
         int (*readfn)(void *cookie, char *buf, int size),
         int (*writefn)(void *cookie, const char *buf, int size),
         off_t (*seekfn)(void *cookie, off_t offset, int whence),
