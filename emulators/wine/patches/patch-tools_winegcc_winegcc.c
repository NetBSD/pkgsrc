$NetBSD: patch-tools_winegcc_winegcc.c,v 1.2 2024/11/01 14:10:47 triaxx Exp $

NetBSD libdl is part of the libc.

--- tools/winegcc/winegcc.c.orig	2024-01-16 20:55:47.000000000 +0000
+++ tools/winegcc/winegcc.c
@@ -1325,7 +1325,9 @@ static void build(struct options* opts)
 
     if (!opts->nostdlib && !is_pe)
     {
+#if !defined(__NetBSD__)
 	strarray_add(&link_args, "-ldl");
+#endif
 	strarray_add(&link_args, "-lm");
 	strarray_add(&link_args, "-lc");
     }
