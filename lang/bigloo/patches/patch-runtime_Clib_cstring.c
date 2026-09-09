$NetBSD: patch-runtime_Clib_cstring.c,v 1.1 2026/09/09 19:57:49 ktnb Exp $

Fixed for NetBSD 11

--- runtime/Clib/cstring.c.orig	2026-02-19 08:14:24.000000000 +0000
+++ runtime/Clib/cstring.c
@@ -1117,7 +1117,7 @@ create_string_for_read(obj_t bstring, int symbolp) {
       if (len > 8192) {
 	 dst = malloc((len * 4) + 1);
       } else {
-	 dst = alloca((len * 4) + 1);
+	 dst = (unsigned char*)alloca((len * 4) + 1);
       }
    } else {
       dst = buffer;
