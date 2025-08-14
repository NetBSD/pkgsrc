$NetBSD: patch-tools_thumbnail.c,v 1.1 2025/08/14 10:02:21 wiz Exp $

Fix for CVE-2025-8177.
https://gitlab.com/libtiff/libtiff/-/merge_requests/737

--- tools/thumbnail.c.orig	2024-08-15 21:16:14.000000000 +0000
+++ tools/thumbnail.c
@@ -620,7 +620,15 @@ static void setrow(uint8_t *row, uint32_
             }
             acc += bits[*src & mask1];
         }
-        *row++ = cmap[(255 * acc) / area];
+        if (255 * acc / area < 256)
+        {
+            *row++ = cmap[(255 * acc) / area];
+        }
+        else
+        {
+            fprintf(stderr, "acc=%d, area=%d\n", acc, area);
+            *row++ = cmap[0];
+        }
     }
 }
 
