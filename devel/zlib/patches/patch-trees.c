$NetBSD: patch-trees.c,v 1.1 2022/03/24 07:56:01 wiz Exp $

Fix a bug that can crash deflate on some input when using Z_FIXED.
https://github.com/madler/zlib/commit/5c44459c3b28a9bd3283aaceab7c615f8020c531

--- trees.c.orig	2022-03-24 07:53:00.769186268 +0000
+++ trees.c
@@ -416,7 +416,7 @@ local void init_block(s)
 
     s->dyn_ltree[END_BLOCK].Freq = 1;
     s->opt_len = s->static_len = 0L;
-    s->last_lit = s->matches = 0;
+    s->sym_next = s->matches = 0;
 }
 
 #define SMALLEST 1
@@ -947,7 +947,7 @@ void ZLIB_INTERNAL _tr_flush_block(s, bu
 
         Tracev((stderr, "\nopt %lu(%lu) stat %lu(%lu) stored %lu lit %u ",
                 opt_lenb, s->opt_len, static_lenb, s->static_len, stored_len,
-                s->last_lit));
+                s->sym_next / 3));
 
         if (static_lenb <= opt_lenb) opt_lenb = static_lenb;
 
@@ -1016,8 +1016,9 @@ int ZLIB_INTERNAL _tr_tally (s, dist, lc
     unsigned dist;  /* distance of matched string */
     unsigned lc;    /* match length-MIN_MATCH or unmatched char (if dist==0) */
 {
-    s->d_buf[s->last_lit] = (ush)dist;
-    s->l_buf[s->last_lit++] = (uch)lc;
+    s->sym_buf[s->sym_next++] = dist;
+    s->sym_buf[s->sym_next++] = dist >> 8;
+    s->sym_buf[s->sym_next++] = lc;
     if (dist == 0) {
         /* lc is the unmatched char */
         s->dyn_ltree[lc].Freq++;
@@ -1032,30 +1033,7 @@ int ZLIB_INTERNAL _tr_tally (s, dist, lc
         s->dyn_ltree[_length_code[lc]+LITERALS+1].Freq++;
         s->dyn_dtree[d_code(dist)].Freq++;
     }
-
-#ifdef TRUNCATE_BLOCK
-    /* Try to guess if it is profitable to stop the current block here */
-    if ((s->last_lit & 0x1fff) == 0 && s->level > 2) {
-        /* Compute an upper bound for the compressed length */
-        ulg out_length = (ulg)s->last_lit*8L;
-        ulg in_length = (ulg)((long)s->strstart - s->block_start);
-        int dcode;
-        for (dcode = 0; dcode < D_CODES; dcode++) {
-            out_length += (ulg)s->dyn_dtree[dcode].Freq *
-                (5L+extra_dbits[dcode]);
-        }
-        out_length >>= 3;
-        Tracev((stderr,"\nlast_lit %u, in %ld, out ~%ld(%ld%%) ",
-               s->last_lit, in_length, out_length,
-               100L - out_length*100L/in_length));
-        if (s->matches < s->last_lit/2 && out_length < in_length/2) return 1;
-    }
-#endif
-    return (s->last_lit == s->lit_bufsize-1);
-    /* We avoid equality with lit_bufsize because of wraparound at 64K
-     * on 16 bit machines and because stored blocks are restricted to
-     * 64K-1 bytes.
-     */
+    return (s->sym_next == s->sym_end);
 }
 
 /* ===========================================================================
@@ -1068,13 +1046,14 @@ local void compress_block(s, ltree, dtre
 {
     unsigned dist;      /* distance of matched string */
     int lc;             /* match length or unmatched char (if dist == 0) */
-    unsigned lx = 0;    /* running index in l_buf */
+    unsigned sx = 0;    /* running index in sym_buf */
     unsigned code;      /* the code to send */
     int extra;          /* number of extra bits to send */
 
-    if (s->last_lit != 0) do {
-        dist = s->d_buf[lx];
-        lc = s->l_buf[lx++];
+    if (s->sym_next != 0) do {
+        dist = s->sym_buf[sx++] & 0xff;
+        dist += (unsigned)(s->sym_buf[sx++] & 0xff) << 8;
+        lc = s->sym_buf[sx++];
         if (dist == 0) {
             send_code(s, lc, ltree); /* send a literal byte */
             Tracecv(isgraph(lc), (stderr," '%c' ", lc));
@@ -1099,11 +1078,10 @@ local void compress_block(s, ltree, dtre
             }
         } /* literal or match pair ? */
 
-        /* Check that the overlay between pending_buf and d_buf+l_buf is ok: */
-        Assert((uInt)(s->pending) < s->lit_bufsize + 2*lx,
-               "pendingBuf overflow");
+        /* Check that the overlay between pending_buf and sym_buf is ok: */
+        Assert(s->pending < s->lit_bufsize + sx, "pendingBuf overflow");
 
-    } while (lx < s->last_lit);
+    } while (sx < s->sym_next);
 
     send_code(s, END_BLOCK, ltree);
 }
