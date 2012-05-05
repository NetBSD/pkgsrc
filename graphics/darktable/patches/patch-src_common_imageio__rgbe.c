$NetBSD: patch-src_common_imageio__rgbe.c,v 1.1 2012/05/05 19:18:33 jakllsch Exp $

--- src/common/imageio_rgbe.c.orig	2012-04-27 20:25:52.000000000 +0000
+++ src/common/imageio_rgbe.c
@@ -189,7 +189,7 @@ int RGBE_ReadHeader(FILE *fp, int *width
     info->valid |= RGBE_VALID_PROGRAMTYPE;
     for(i=0; i<sizeof(info->programtype)-1; i++)
     {
-      if ((buf[i+2] == 0) || isspace(buf[i+2]))
+      if ((buf[i+2] == 0) || isspace((unsigned char)buf[i+2]))
         break;
       info->programtype[i] = buf[i+2];
     }
