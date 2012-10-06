$NetBSD: patch-src_lib_attr.c,v 1.1 2012/10/06 17:54:53 christos Exp $

use intmax_t instead of int64_t

--- src/lib/attr.c.orig	2012-09-13 04:51:19.000000000 -0400
+++ src/lib/attr.c	2012-10-04 23:51:53.000000000 -0400
@@ -120,7 +120,7 @@
    } else {
       pm_strcpy(attr->attrEx, p);     /* copy extended attributes, if any */
       if (attr->data_stream) {
-         int64_t val;
+         intmax_t val;
          while (*p++ != 0)            /* skip extended attributes */
             { }
          from_base64(&val, p);
