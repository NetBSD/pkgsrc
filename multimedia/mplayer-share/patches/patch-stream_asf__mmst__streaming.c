$NetBSD: patch-stream_asf__mmst__streaming.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- stream/asf_mmst_streaming.c.orig	2025-10-08 03:53:42.593917217 +0000
+++ stream/asf_mmst_streaming.c
@@ -366,7 +366,7 @@ static int interp_header (uint8_t *heade
       printf ("unknown object (guid: %016llx, %016llx, len: %lld)\n", guid_1, guid_2, length);
       for (; b < length; b++)
       {
-        if (isascii(header[b]) || isalpha(header[b]))
+        if (isascii((unsigned char)(header[b])) || isalpha((unsigned char)(header[b])))
 	    printf("%c ", header[b]);
 	else
     	    printf("%x ", header[b]);
