$NetBSD: patch-libxl_xl__cmdimpl.c,v 1.1 2016/12/29 23:12:24 wiz Exp $

--- libxl/xl_cmdimpl.c.orig	2013-05-05 19:37:21.000000000 +0000
+++ libxl/xl_cmdimpl.c
@@ -922,7 +922,7 @@ skip:
 
             for (p = strtok(buf2, ","); p; p = strtok(NULL, ",")) {
                 char* val;
-                while (isblank(*p))
+                while (isblank((unsigned char)*p))
                     p++;
                 val = strchr(p, '=');
                 if (val == NULL)
