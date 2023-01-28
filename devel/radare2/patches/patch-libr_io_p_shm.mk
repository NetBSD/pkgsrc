$NetBSD: patch-libr_io_p_shm.mk,v 1.2 2023/01/28 01:28:42 khorben Exp $

Add library search path so this finds its dependencies.

--- libr/io/p/shm.mk.orig	2023-01-28 01:11:15.052990580 +0000
+++ libr/io/p/shm.mk
@@ -23,4 +23,4 @@ R_IO_SHM_LINKFLAGS+=-L.. -lr_io
 endif
 
 $(N) p/${TARGET_SHM}: p/${OBJ_SHM}
-	cd p && $(CC) $(CFLAGS) -shared -L.. $(CSRC_SHM) -fPIC -o $(TARGET_SHM) -I../../include -I../../../shlr/sdb/src $(R_IO_SHM_LINKFLAGS)
+	cd p && $(CC) $(CFLAGS) -shared -L.. $(CSRC_SHM) -fPIC -o $(TARGET_SHM) -I../../include -I../../../shlr/sdb/src -Wl,-R${PREFIX}/lib $(R_IO_SHM_LINKFLAGS)
