$NetBSD: patch-xzlib.c,v 1.4 2018/10/13 09:05:42 leot Exp $

Fix for CVE-2018-9251 and CVE-2018-14567, upstream commit id
2240fbf5912054af025fb6e01e26375100275e74:

 <https://gitlab.gnome.org/GNOME/libxml2/commit/2240fbf5912054af025fb6e01e26375100275e74>

--- xzlib.c.orig	2017-12-02 08:58:10.000000000 +0000
+++ xzlib.c
@@ -562,6 +562,10 @@ xz_decomp(xz_statep state)
                          "internal error: inflate stream corrupt");
                 return -1;
             }
+            /*
+             * FIXME: Remapping a couple of error codes and falling through
+             * to the LZMA error handling looks fragile.
+             */
             if (ret == Z_MEM_ERROR)
                 ret = LZMA_MEM_ERROR;
             if (ret == Z_DATA_ERROR)
@@ -587,6 +591,11 @@ xz_decomp(xz_statep state)
             xz_error(state, LZMA_PROG_ERROR, "compression error");
             return -1;
         }
+        if ((state->how != GZIP) &&
+            (ret != LZMA_OK) && (ret != LZMA_STREAM_END)) {
+            xz_error(state, ret, "lzma error");
+            return -1;
+        }
     } while (strm->avail_out && ret != LZMA_STREAM_END);
 
     /* update available output and crc check value */
