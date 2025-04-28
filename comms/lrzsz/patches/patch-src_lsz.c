$NetBSD: patch-src_lsz.c,v 1.1 2025/04/28 16:58:51 tnn Exp $

replace K&R prototypes

--- src/lsz.c.orig	2025-04-28 16:48:01.931477890 +0000
+++ src/lsz.c
@@ -51,9 +51,9 @@ void *mm_addr=NULL;
 #include "error.h"
 
 #ifndef STRICT_PROTOTYPES
-extern time_t time();
-extern char *strerror();
-extern char *strstr();
+extern time_t time(time_t *);
+extern char *strerror(int);
+extern char *strstr(const char*, const char*);
 #endif
 
 #ifndef HAVE_ERRNO_DECLARATION
