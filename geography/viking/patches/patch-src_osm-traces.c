$NetBSD: patch-src_osm-traces.c,v 1.2 2011/07/30 19:25:55 gdt Exp $

curl has apparently withdraw a header file.

--- src/osm-traces.c.orig	2011-06-15 19:30:06.000000000 +0000
+++ src/osm-traces.c
@@ -27,7 +27,6 @@
 #include <errno.h>
 
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 
 #include <glib.h>
