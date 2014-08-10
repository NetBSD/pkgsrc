$NetBSD: patch-src_solx__devfs.c,v 1.3 2014/08/10 06:35:30 richard Exp $
Caching fd's for reuse is most effective when you actually stick
the newly opened fd in the cache, instead of letting it leak at
the end of the function.
http://cgit.freedesktop.org/xorg/lib/libpciaccess/commit/?id=1654a0462723b3b75d7a4a20bedfc653cc3e1f1a

--- src/solx_devfs.c.orig	2013-07-20 22:54:34.000000000 +0000
+++ src/solx_devfs.c
@@ -724,6 +724,9 @@ pci_device_solx_devfs_map_range(struct p
 			   strerror(errno));
 	    return err;
 	}
+#ifndef __sparc
+	xsvc_fd = map_fd;
+#endif
     }
 
     map->memory = mmap(NULL, map->size, prot, MAP_SHARED, map_fd, map->base);
