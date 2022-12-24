$NetBSD: patch-libr_io_p_shm.mk,v 1.1 2022/12/24 12:44:15 wiz Exp $

Add library search path so this finds its dependencies.

--- libr/io/p/shm.mk.orig	2022-09-13 16:08:16.000000000 +0000
+++ libr/io/p/shm.mk
@@ -19,4 +19,4 @@ LINKFLAGS+=-L.. -lr_io
 endif
 
 $(N) p/${TARGET_SHM}: p/${OBJ_SHM}
-	cd p && $(CC) $(CFLAGS) -shared -L.. $(CSRC_SHM) -fPIC -o $(TARGET_SHM) -I../../include -I../../../shlr/sdb/src $(LINKFLAGS)
+	cd p && $(CC) $(CFLAGS) -shared -L.. $(CSRC_SHM) -fPIC -o $(TARGET_SHM) -I../../include -I../../../shlr/sdb/src -Wl,-R${PREFIX}/lib $(LINKFLAGS)
