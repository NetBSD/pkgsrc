$NetBSD: patch-liblangtag_lt-xml.c,v 1.1 2016/04/30 05:27:18 richard Exp $

index() may need <strings.h>

--- liblangtag/lt-xml.c.orig	2016-03-23 02:56:45.000000000 +0000
+++ liblangtag/lt-xml.c
@@ -15,6 +15,9 @@
 #endif
 
 #include <stddef.h>
+#ifdef HAVE_STRINGS_H
+#include <strings.h>
+#endif
 #include <string.h>
 #include <sys/stat.h>
 #include <libxml/parser.h>
