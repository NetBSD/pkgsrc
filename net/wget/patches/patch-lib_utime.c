$NetBSD: patch-lib_utime.c,v 1.1 2021/01/08 16:14:56 schmonz Exp $

Apply upstream 6a76832 to fix compilation error on macOS and Solaris 9.

--- lib/utime.c.orig	2020-12-31 15:53:25.000000000 +0000
+++ lib/utime.c
@@ -261,6 +261,7 @@ utime (const char *name, const struct ut
 
 #else
 
+# include <errno.h>
 # include <sys/stat.h>
 # include "filename.h"
 
