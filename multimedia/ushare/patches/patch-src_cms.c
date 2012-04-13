$NetBSD: patch-src_cms.c,v 1.1 2012/04/13 23:44:39 obache Exp $

* some header files are not included by libupnp>=1.6.7.

--- src/cms.c.orig	2007-12-09 13:03:36.000000000 +0000
+++ src/cms.c
@@ -20,6 +20,7 @@
  */
 
 #include <stdlib.h>
+#include <string.h>
 #include <upnp/upnp.h>
 #include <upnp/upnptools.h>
 
