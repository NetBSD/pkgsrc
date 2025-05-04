$NetBSD: patch-src_libvncclient_rfbclient.c,v 1.1 2025/05/04 09:47:18 nia Exp $

From ae7656ef8ab2f61f70a58fafd88e527f35b4e8de Mon Sep 17 00:00:00 2001
From: Jonathan Poelen <jonathan.poelen@gmail.com>
Date: Thu, 6 Feb 2025 17:36:46 +0100
Subject: [PATCH] libvncclient: fix memory leak in CompressClipData

--- src/libvncclient/rfbclient.c.orig	2024-12-22 09:54:53.000000000 +0000
+++ src/libvncclient/rfbclient.c
@@ -1815,26 +1815,26 @@ static int
 CompressClipData(Bytef *dest, uLongf *destLen, Bytef *source, uLong sourceLen)
 {
   int ret;
-  z_stream *zs = (z_stream*)malloc(sizeof(z_stream));
-  memset(zs, 0, sizeof(z_stream));
+  z_stream zs;
+  memset(&zs, 0, sizeof(z_stream));
 
-  zs->zfree = Z_NULL;
-  zs->zalloc = Z_NULL;
-  zs->opaque = Z_NULL;
-  ret = deflateInit(zs, Z_DEFAULT_COMPRESSION);
+  zs.zfree = Z_NULL;
+  zs.zalloc = Z_NULL;
+  zs.opaque = Z_NULL;
+  ret = deflateInit(&zs, Z_DEFAULT_COMPRESSION);
   if (ret == Z_OK) {
-    zs->avail_in = sourceLen;
-    zs->next_in = source;
-    zs->avail_out = *destLen;
-    zs->next_out = dest;
+    zs.avail_in = sourceLen;
+    zs.next_in = source;
+    zs.avail_out = *destLen;
+    zs.next_out = dest;
 
     do {
       // Using Z_SYNC_FLUSH instead of Z_FINISH is the key here.
-      ret = deflate(zs, Z_SYNC_FLUSH);
-    } while (ret >= 0 && zs->avail_in > 0);
+      ret = deflate(&zs, Z_SYNC_FLUSH);
+    } while (ret >= 0 && zs.avail_in > 0);
 
-    *destLen = zs->total_out;
-    deflateEnd(zs);
+    *destLen = zs.total_out;
+    deflateEnd(&zs);
   }
   return ret;
 }
