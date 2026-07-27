$NetBSD: patch-libzsync_sha1.c,v 1.1 2026/07/27 15:38:30 ryoon Exp $

* Include endian.h for BYTE_ORDER.

--- libzsync/sha1.c.orig	2026-07-27 00:54:33.490255126 +0000
+++ libzsync/sha1.c
@@ -23,6 +23,7 @@ static const char rcsid[] = "$OpenBSD: sha1.c,v 1.19 2
 #include <sys/param.h>
 #include <stdint.h>
 #include <string.h>
+#include <endian.h>
 #include "sha1.h"
 
 #define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))
