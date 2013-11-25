$NetBSD: patch-xzlib.c,v 1.1 2013/11/25 23:30:23 wiz Exp $

Fix bug in gzip decompression.
https://bugzilla.gnome.org/show_bug.cgi?id=712528

--- xzlib.c.orig	2013-02-27 05:08:52.000000000 +0000
+++ xzlib.c
@@ -245,6 +245,20 @@ xz_avail(xz_statep state)
     return 0;
 }
 
+#ifdef HAVE_ZLIB_H
+static int
+xz_avail_zstrm(xz_statep state)
+{
+    int ret;
+    state->strm.avail_in = state->zstrm.avail_in;
+    state->strm.next_in = state->zstrm.next_in;
+    ret = xz_avail(state);
+    state->zstrm.avail_in = (uInt) state->strm.avail_in;
+    state->zstrm.next_in = (Bytef *) state->strm.next_in;
+    return ret;
+}
+#endif
+
 static int
 is_format_xz(xz_statep state)
 {
@@ -314,6 +328,10 @@ is_format_lzma(xz_statep state)
 #define NEXT() ((strm->avail_in == 0 && xz_avail(state) == -1) ? -1 : \
                 (strm->avail_in == 0 ? -1 : \
                  (strm->avail_in--, *(strm->next_in)++)))
+/* Same thing, but from zstrm */
+#define NEXTZ() ((strm->avail_in == 0 && xz_avail_zstrm(state) == -1) ? -1 : \
+                (strm->avail_in == 0 ? -1 : \
+                 (strm->avail_in--, *(strm->next_in)++)))
 
 /* Get a four-byte little-endian integer and return 0 on success and the value
    in *ret.  Otherwise -1 is returned and *ret is not modified. */
@@ -324,10 +342,10 @@ gz_next4(xz_statep state, unsigned long 
     unsigned long val;
     z_streamp strm = &(state->zstrm);
 
-    val = NEXT();
-    val += (unsigned) NEXT() << 8;
-    val += (unsigned long) NEXT() << 16;
-    ch = NEXT();
+    val = NEXTZ();
+    val += (unsigned) NEXTZ() << 8;
+    val += (unsigned long) NEXTZ() << 16;
+    ch = NEXTZ();
     if (ch == -1)
         return -1;
     val += (unsigned long) ch << 24;
