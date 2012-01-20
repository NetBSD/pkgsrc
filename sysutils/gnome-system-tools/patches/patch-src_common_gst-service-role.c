$NetBSD: patch-src_common_gst-service-role.c,v 1.1 2012/01/20 17:01:07 joerg Exp $

--- src/common/gst-service-role.c.orig	2012-01-18 23:58:15.000000000 +0000
+++ src/common/gst-service-role.c
@@ -19,6 +19,8 @@
  * Authors: Carlos Garnacho Parro <carlosg@gnome.org>.
  */
 
+#include <stdlib.h>
+#include <string.h>
 #include "gst-service-role.h"
 
 typedef struct _ServiceRole ServiceRole;
