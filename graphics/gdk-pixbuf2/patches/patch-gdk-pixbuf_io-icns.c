$NetBSD: patch-gdk-pixbuf_io-icns.c,v 1.1 2013/08/26 14:38:56 richard Exp $

* include config.h early to avoid redefinition warnings on solaris
* 
--- gdk-pixbuf/io-icns.c.orig	2011-08-16 01:45:14.000000000 +0000
+++ gdk-pixbuf/io-icns.c
@@ -22,6 +22,7 @@
 #ifndef _WIN32
 #define _GNU_SOURCE
 #endif
+#include "config.h"
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
