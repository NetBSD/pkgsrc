$NetBSD: patch-deflate.c,v 1.1 2022/03/24 07:56:00 wiz Exp $

Fix a bug that can crash deflate on some input when using Z_FIXED.
https://github.com/madler/zlib/commit/5c44459c3b28a9bd3283aaceab7c615f8020c531

--- deflate.c.orig	2022-03-24 07:53:00.766822394 +0000
+++ deflate.c
@@ -252,11 +252,6 @@ int ZEXPORT deflateInit2_(strm, level, m
     int wrap = 1;
     static const char my_version[] = ZLIB_VERSION;
 
-    ushf *overlay;
-    /* We overlay pending_buf and d_buf+l_buf. This works since the average
-     * output size for (length,distance) codes is <= 24 bits.
-     */
-
     if (version == Z_NULL || version[0] != my_version[0] ||
         stream_size != sizeof(z_stream)) {
         return Z_VERSION_ERROR;
@@ -326,9 +321,47 @@ int ZEXPORT deflateInit2_(strm, level, m
 
     s->lit_bufsize = 1 << (memLevel + 6); /* 16K elements by default */
 
-    overlay = (ushf *) ZALLOC(strm, s->lit_bufsize, sizeof(ush)+2);
-    s->pending_buf = (uchf *) overlay;
-    s->pending_buf_size = (ulg)s->lit_bufsize * (sizeof(ush)+2L);
+    /* We overlay pending_buf and sym_buf. This works since the average size
+     * for length/distance pairs over any compressed block is assured to be 31
+     * bits or less.
+     *
+     * Analysis: The longest fixed codes are a length code of 8 bits plus 5
+     * extra bits, for lengths 131 to 257. The longest fixed distance codes are
+     * 5 bits plus 13 extra bits, for distances 16385 to 32768. The longest
+     * possible fixed-codes length/distance pair is then 31 bits total.
+     *
+     * sym_buf starts one-fourth of the way into pending_buf. So there are
+     * three bytes in sym_buf for every four bytes in pending_buf. Each symbol
+     * in sym_buf is three bytes -- two for the distance and one for the
+     * literal/length. As each symbol is consumed, the pointer to the next
+     * sym_buf value to read moves forward three bytes. From that symbol, up to
+     * 31 bits are written to pending_buf. The closest the written pending_buf
+     * bits gets to the next sym_buf symbol to read is just before the last
+     * code is written. At that time, 31*(n-2) bits have been written, just
+     * after 24*(n-2) bits have been consumed from sym_buf. sym_buf starts at
+     * 8*n bits into pending_buf. (Note that the symbol buffer fills when n-1
+     * symbols are written.) The closest the writing gets to what is unread is
+     * then n+14 bits. Here n is lit_bufsize, which is 16384 by default, and
+     * can range from 128 to 32768.
+     *
+     * Therefore, at a minimum, there are 142 bits of space between what is
+     * written and what is read in the overlain buffers, so the symbols cannot
+     * be overwritten by the compressed data. That space is actually 139 bits,
+     * due to the three-bit fixed-code block header.
+     *
+     * That covers the case where either Z_FIXED is specified, forcing fixed
+     * codes, or when the use of fixed codes is chosen, because that choice
+     * results in a smaller compressed block than dynamic codes. That latter
+     * condition then assures that the above analysis also covers all dynamic
+     * blocks. A dynamic-code block will only be chosen to be emitted if it has
+     * fewer bits than a fixed-code block would for the same set of symbols.
+     * Therefore its average symbol length is assured to be less than 31. So
+     * the compressed data for a dynamic block also cannot overwrite the
+     * symbols from which it is being constructed.
+     */
+
+    s->pending_buf = (uchf *) ZALLOC(strm, s->lit_bufsize, 4);
+    s->pending_buf_size = (ulg)s->lit_bufsize * 4;
 
     if (s->window == Z_NULL || s->prev == Z_NULL || s->head == Z_NULL ||
         s->pending_buf == Z_NULL) {
@@ -337,8 +370,12 @@ int ZEXPORT deflateInit2_(strm, level, m
         deflateEnd (strm);
         return Z_MEM_ERROR;
     }
-    s->d_buf = overlay + s->lit_bufsize/sizeof(ush);
-    s->l_buf = s->pending_buf + (1+sizeof(ush))*s->lit_bufsize;
+    s->sym_buf = s->pending_buf + s->lit_bufsize;
+    s->sym_end = (s->lit_bufsize - 1) * 3;
+    /* We avoid equality with lit_bufsize*3 because of wraparound at 64K
+     * on 16 bit machines and because stored blocks are restricted to
+     * 64K-1 bytes.
+     */
 
     s->level = level;
     s->strategy = strategy;
@@ -549,7 +586,7 @@ int ZEXPORT deflatePrime (strm, bits, va
 
     if (deflateStateCheck(strm)) return Z_STREAM_ERROR;
     s = strm->state;
-    if ((Bytef *)(s->d_buf) < s->pending_out + ((Buf_size + 7) >> 3))
+    if (s->sym_buf < s->pending_out + ((Buf_size + 7) >> 3))
         return Z_BUF_ERROR;
     do {
         put = Buf_size - s->bi_valid;
@@ -1108,7 +1145,6 @@ int ZEXPORT deflateCopy (dest, source)
 #else
     deflate_state *ds;
     deflate_state *ss;
-    ushf *overlay;
 
 
     if (deflateStateCheck(source) || dest == Z_NULL) {
@@ -1128,8 +1164,7 @@ int ZEXPORT deflateCopy (dest, source)
     ds->window = (Bytef *) ZALLOC(dest, ds->w_size, 2*sizeof(Byte));
     ds->prev   = (Posf *)  ZALLOC(dest, ds->w_size, sizeof(Pos));
     ds->head   = (Posf *)  ZALLOC(dest, ds->hash_size, sizeof(Pos));
-    overlay = (ushf *) ZALLOC(dest, ds->lit_bufsize, sizeof(ush)+2);
-    ds->pending_buf = (uchf *) overlay;
+    ds->pending_buf = (uchf *) ZALLOC(dest, ds->lit_bufsize, 4);
 
     if (ds->window == Z_NULL || ds->prev == Z_NULL || ds->head == Z_NULL ||
         ds->pending_buf == Z_NULL) {
@@ -1143,8 +1178,7 @@ int ZEXPORT deflateCopy (dest, source)
     zmemcpy(ds->pending_buf, ss->pending_buf, (uInt)ds->pending_buf_size);
 
     ds->pending_out = ds->pending_buf + (ss->pending_out - ss->pending_buf);
-    ds->d_buf = overlay + ds->lit_bufsize/sizeof(ush);
-    ds->l_buf = ds->pending_buf + (1+sizeof(ush))*ds->lit_bufsize;
+    ds->sym_buf = ds->pending_buf + ds->lit_bufsize;
 
     ds->l_desc.dyn_tree = ds->dyn_ltree;
     ds->d_desc.dyn_tree = ds->dyn_dtree;
@@ -1912,7 +1946,7 @@ local block_state deflate_fast(s, flush)
         FLUSH_BLOCK(s, 1);
         return finish_done;
     }
-    if (s->last_lit)
+    if (s->sym_next)
         FLUSH_BLOCK(s, 0);
     return block_done;
 }
@@ -2043,7 +2077,7 @@ local block_state deflate_slow(s, flush)
         FLUSH_BLOCK(s, 1);
         return finish_done;
     }
-    if (s->last_lit)
+    if (s->sym_next)
         FLUSH_BLOCK(s, 0);
     return block_done;
 }
@@ -2118,7 +2152,7 @@ local block_state deflate_rle(s, flush)
         FLUSH_BLOCK(s, 1);
         return finish_done;
     }
-    if (s->last_lit)
+    if (s->sym_next)
         FLUSH_BLOCK(s, 0);
     return block_done;
 }
@@ -2157,7 +2191,7 @@ local block_state deflate_huff(s, flush)
         FLUSH_BLOCK(s, 1);
         return finish_done;
     }
-    if (s->last_lit)
+    if (s->sym_next)
         FLUSH_BLOCK(s, 0);
     return block_done;
 }
