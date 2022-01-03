$NetBSD: patch-src_camel_camel-hostname-utils.c,v 1.1 2022/01/03 08:13:23 cirnatdan Exp $

Add missing unicode header

--- src/camel/camel-hostname-utils.c.orig	2021-10-29 07:18:27.000000000 +0000
+++ src/camel/camel-hostname-utils.c
@@ -24,6 +24,7 @@
 
 #include <unicode/uchar.h>
 #include <unicode/uscript.h>
+#include <unicode/ustring.h>
 
 #include "camel-string-utils.h"
 #include "camel-hostname-utils.h"
