$NetBSD: patch-imap.c,v 1.1 2026/05/15 19:04:22 ktnb Exp $

Include missing header

--- imap.c.orig	2017-08-13 21:55:52.000000000 +0000
+++ imap.c
@@ -14,6 +14,7 @@
 #include <openssl/ssl.h>
 #include <openssl/err.h>
 #endif
+#include <sys/socket.h>
 #include "imap.h"
 
 struct imap_ll {
