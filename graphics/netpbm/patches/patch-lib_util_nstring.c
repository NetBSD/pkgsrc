$NetBSD: patch-lib_util_nstring.c,v 1.1 2025/05/01 16:50:44 tnn Exp $

define _DARWIN_C_SOURCE for vasprintf

--- lib/util/nstring.c.orig	2025-05-01 16:46:16.713149476 +0000
+++ lib/util/nstring.c
@@ -26,6 +26,7 @@
 #define _DEFAULT_SOURCE /* New name for SVID & BSD source defines */
 #define _XOPEN_SOURCE 500  /* Make sure strdup() is in string.h */
 #define _BSD_SOURCE  /* Make sure strdup() is in string.h */
+#define _DARWIN_C_SOURCE  /* Make sure vasprintf(3) is in stdio.h */
 #define _GNU_SOURCE
    /* Because of conditional compilation, this is GNU source only if the C
       library is GNU.
