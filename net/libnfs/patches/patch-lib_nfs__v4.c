$NetBSD: patch-lib_nfs__v4.c,v 1.1 2026/05/01 19:43:30 vins Exp $

Fix misuse of ctype(3) functions: char values must always be cast to
unsigned char.

--- lib/nfs_v4.c.orig	2025-11-14 14:16:21.037945741 +0000
+++ lib/nfs_v4.c
@@ -433,7 +433,7 @@ nfs_get_ugid(struct nfs_context *nfs, co
         const char *name = buf;
 
         while (slen) {
-                if (isdigit(*buf)) {
+                if (isdigit((unsigned char)*buf)) {
                         ugid *= 10;
                         ugid += *buf - '0';
                 } else {
