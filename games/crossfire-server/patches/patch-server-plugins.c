$NetBSD: patch-server-plugins.c,v 1.1 2011/11/11 00:21:17 joerg Exp $

--- server/plugins.c.orig	2011-11-08 20:44:23.000000000 +0000
+++ server/plugins.c
@@ -3350,7 +3350,7 @@ void* cfapi_object_create(int* type, ...
         robj = va_arg(args, object**);
         va_end(args);
         *robj = get_object();
-        return;
+        return NULL;
         break;
 
     case 1: /* Named object. Nearly the old plugin behavior, but we don't add artifact suffixes */
@@ -3371,6 +3371,7 @@ void* cfapi_object_create(int* type, ...
             else
                 *robj = NULL;
         }
+        return NULL;
         break;
 
     default:
