$NetBSD: patch-xzlib.c,v 1.3 2018/06/20 18:22:45 tez Exp $

Fix for CVE-2018-9251 from https://bugzilla.gnome.org/show_bug.cgi?id=794914

--- xzlib.c.orig	2018-06-20 16:11:09.322482100 +0000
+++ xzlib.c
@@ -575,6 +575,10 @@ xz_decomp(xz_statep state)
         } else                  /* state->how == LZMA */
 #endif
             ret = lzma_code(strm, action);
+        if (ret == LZMA_MEMLIMIT_ERROR) {
+            xz_error(state, LZMA_MEMLIMIT_ERROR, "memory limit error");
+            return -1;
+        }
         if (ret == LZMA_MEM_ERROR) {
             xz_error(state, LZMA_MEM_ERROR, "out of memory");
             return -1;
