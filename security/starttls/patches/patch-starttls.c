$NetBSD: patch-starttls.c,v 1.1 2012/07/15 11:12:21 cheusov Exp $

starttls(1): fix for segfault when run without arguments
--- starttls.c.orig	2004-03-21 23:40:58.000000000 +0000
+++ starttls.c
@@ -55,6 +55,8 @@
 #define _GNU_SOURCE
 #include "getopt.h"
 
+char *basename (char *);
+
 static SSL_CTX *tls_ctx = NULL;
 static SSL *tls_conn = NULL;
 static int tls_fd;
