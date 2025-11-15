$NetBSD: patch-stream_stream__bd.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- stream/stream_bd.c.orig	2025-10-08 03:52:19.386482362 +0000
+++ stream/stream_bd.c
@@ -212,7 +212,7 @@ static int find_vuk(struct bd_priv *bd, 
         if (!vst)
             break;
         vst += 6;
-        while (isspace(*vst)) vst++;
+        while (isspace((unsigned char)(*vst))) vst++;
         if (vst[0] == '0' && vst[1] == 'x') vst += 2;
         if (sscanf(vst,      "%16"SCNx64, &bd->vuk.u64[0]) != 1)
             continue;
