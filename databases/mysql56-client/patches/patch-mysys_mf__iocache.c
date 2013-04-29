$NetBSD: patch-mysys_mf__iocache.c,v 1.1 2013/04/29 21:16:56 joerg Exp $

--- mysys/mf_iocache.c.orig	2013-04-28 13:55:46.000000000 +0000
+++ mysys/mf_iocache.c
@@ -180,7 +180,7 @@ int init_io_cache(IO_CACHE *info, File f
       DBUG_ASSERT(seek_offset == 0);
     }
     else
-      info->seek_not_done= test(seek_offset != pos);
+      info->seek_not_done= my_test(seek_offset != pos);
   }
 
   info->disk_writes= 0;
