$NetBSD: patch-src_lib.c,v 1.1 2025/12/28 05:42:55 ryoon Exp $

* Fix ctype(3) abuse.

--- src/lib.c.orig	2025-12-24 09:55:32.955684412 +0000
+++ src/lib.c
@@ -411,7 +411,7 @@ static lib_t lib_find_at(const char *nam
 
    struct dirent *e;
    while ((e = readdir(d))) {
-      if (!isalpha(e->d_name[0]))
+      if (!isalpha((unsigned char)(e->d_name[0])))
          continue;
 
       const char *dot = strchr(e->d_name, '.');
