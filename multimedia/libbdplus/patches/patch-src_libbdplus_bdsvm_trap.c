$NetBSD: patch-src_libbdplus_bdsvm_trap.c,v 1.1 2014/01/08 23:07:09 wiz Exp $

fseeko is a Linuxism.

--- src/libbdplus/bdsvm/trap.c.orig	2013-12-18 12:13:09.000000000 +0000
+++ src/libbdplus/bdsvm/trap.c
@@ -1310,7 +1310,7 @@ uint32_t TRAP_MediaCheck(const char *dev
         return j;
     }
 
-    if (fseeko(fd, seek, SEEK_SET)) {
+    if (fseek(fd, seek, SEEK_SET)) {
         DEBUG(DBG_BDPLUS|DBG_CRIT, "[TRAP] TRAP_MediaCheck: failed to seek %s to %"PRIu64"\n", (char *)FileName, seek);
         fclose(fd);
         return STATUS_INVALID_PARAMETER;
