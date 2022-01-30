$NetBSD: patch-vmhgfs-fuse_main.c,v 1.1 2022/01/30 16:22:20 pho Exp $

Workaround for an issue regarding write operations on vmhgfs. See:
https://github.com/vmware/open-vm-tools/issues/437

Ideally this should be worked around by setting fuse_conn_info.max_write to
65457, but it doesn't work on NetBSD because neither PUFFS nor ReFUSE
support it at the moment.

--- vmhgfs-fuse/main.c.orig	2022-01-30 16:00:53.301468031 +0000
+++ vmhgfs-fuse/main.c
@@ -1138,7 +1138,20 @@ hgfs_write(const char *path,          //
       }
    }
 
-   res = HgfsWrite(fi, buf, size, offset);
+   for (res = 0; res < size; ) {
+       int remaining = size - res;
+       int chunkLen  = remaining > 65457 ? 65457 : remaining;
+       int nWrote    = HgfsWrite(fi, buf + res, chunkLen, offset + res);
+
+       if (nWrote < 0) {
+           res = nWrote; /* An error occured. */
+           break;
+       }
+       else {
+           res += nWrote;
+       }
+   }
+
    if (res >= 0) {
       /*
        * Positive result indicates the number of bytes written.
