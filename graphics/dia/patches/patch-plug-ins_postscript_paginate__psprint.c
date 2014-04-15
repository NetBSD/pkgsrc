$NetBSD: patch-plug-ins_postscript_paginate__psprint.c,v 1.1 2014/04/15 20:34:36 asau Exp $

--- plug-ins/postscript/paginate_psprint.c.orig	2009-11-07 14:28:34.000000000 +0000
+++ plug-ins/postscript/paginate_psprint.c
@@ -31,6 +31,10 @@
 #include <errno.h>
 #include <sys/stat.h>
 
+#if defined(__FreeBSD__)
+#include <sys/types.h> /* clockid_t */
+#endif
+
 #include <glib/gstdio.h>
 
 #include "intl.h"
