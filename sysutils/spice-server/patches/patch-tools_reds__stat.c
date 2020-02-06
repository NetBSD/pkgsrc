$NetBSD: patch-tools_reds__stat.c,v 1.1 2020/02/06 21:57:42 kamil Exp $

Add NetBSD support.

--- tools/reds_stat.c.orig	2019-04-30 08:51:05.000000000 +0000
+++ tools/reds_stat.c
@@ -144,7 +144,11 @@ int main(int argc, char **argv)
             num_of_nodes = reds_stat->num_of_nodes;
             shm_old_size = shm_size;
             shm_size = header_size + num_of_nodes * sizeof(SpiceStatNode);
+#if defined(__NetBSD__)
+            reds_stat = mremap(reds_stat, shm_old_size, NULL, shm_size, 0);
+#else
             reds_stat = mremap(reds_stat, shm_old_size, shm_size, MREMAP_MAYMOVE);
+#endif
             if (reds_stat == (SpiceStat *)MAP_FAILED) {
                 perror("mremap");
                 goto error;
