$NetBSD: patch-src_regex.c,v 1.1 2026/03/16 14:32:52 nia Exp $

Fix implicit function declaration of malloc.

--- src/regex.c.orig	2026-03-16 14:22:55.133051888 +0000
+++ src/regex.c
@@ -756,6 +756,7 @@ PREFIX(extract_number_and_incr) (destina
 
 /* We use standard I/O for debugging.  */
 #   include <stdio.h>
+#   include <stdlib.h>
 
 /* It is useful to test things that ``must'' be true when debugging.  */
 #   include <assert.h>
