$NetBSD: patch-storage_tokudb_PerconaFT_portability_file.cc,v 1.1 2021/05/08 19:47:16 jdolecek Exp $

Add directio support on SunOS.

--- storage/tokudb/PerconaFT/portability/file.cc.orig	2015-02-25 15:40:56.000000000 +0000
+++ storage/tokudb/PerconaFT/portability/file.cc
@@ -373,6 +373,9 @@ toku_os_open_direct(const char *path, in
             perror("setting F_NOCACHE");
         }
     }
+#elif defined(__sun)
+    rval = toku_os_open(path, oflag, mode);
+    directio(rval, DIRECTIO_ON);
 #else
 # error "No direct I/O implementation found."
 #endif
