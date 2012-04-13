$NetBSD: patch-src_http.c,v 1.1 2012/04/13 23:44:39 obache Exp $

* some header files are not included by libupnp>=1.6.7.

--- src/http.c.orig	2007-12-09 13:03:36.000000000 +0000
+++ src/http.c
@@ -27,6 +27,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
+#include <string.h>
 
 #include <upnp/upnp.h>
 #include <upnp/upnptools.h>
