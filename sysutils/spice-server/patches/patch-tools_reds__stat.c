$NetBSD: patch-tools_reds__stat.c,v 1.3 2021/04/06 23:43:40 khorben Exp $

Add SunOS, NetBSD, and macOS support.

--- tools/reds_stat.c.orig	2020-02-27 11:26:12.000000000 +0000
+++ tools/reds_stat.c
@@ -144,7 +144,14 @@ int main(int argc, char **argv)
             num_of_nodes = reds_stat->num_of_nodes;
             shm_old_size = shm_size;
             shm_size = header_size + num_of_nodes * sizeof(SpiceStatNode);
+#if defined(__NetBSD__)
+            reds_stat = mremap(reds_stat, shm_old_size, NULL, shm_size, 0);
+#elif defined(__sun) || defined(__APPLE__)
+            munmap(reds_stat, shm_old_size);
+            reds_stat = (SpiceStat *)mmap(NULL, shm_size, PROT_READ, MAP_SHARED, fd, 0);
+#else
             reds_stat = mremap(reds_stat, shm_old_size, shm_size, MREMAP_MAYMOVE);
+#endif
             if (reds_stat == (SpiceStat *)MAP_FAILED) {
                 perror("mremap");
                 goto error;
