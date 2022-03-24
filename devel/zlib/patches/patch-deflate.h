$NetBSD: patch-deflate.h,v 1.1 2022/03/24 07:56:00 wiz Exp $

Fix a bug that can crash deflate on some input when using Z_FIXED.
https://github.com/madler/zlib/commit/5c44459c3b28a9bd3283aaceab7c615f8020c531

--- deflate.h.orig	2022-03-24 07:53:00.766964104 +0000
+++ deflate.h
@@ -217,7 +217,7 @@ typedef struct internal_state {
     /* Depth of each subtree used as tie breaker for trees of equal frequency
      */
 
-    uchf *l_buf;          /* buffer for literals or lengths */
+    uchf *sym_buf;        /* buffer for distances and literals/lengths */
 
     uInt  lit_bufsize;
     /* Size of match buffer for literals/lengths.  There are 4 reasons for
@@ -239,13 +239,8 @@ typedef struct internal_state {
      *   - I can't count above 4
      */
 
-    uInt last_lit;      /* running index in l_buf */
-
-    ushf *d_buf;
-    /* Buffer for distances. To simplify the code, d_buf and l_buf have
-     * the same number of elements. To use different lengths, an extra flag
-     * array would be necessary.
-     */
+    uInt sym_next;      /* running index in sym_buf */
+    uInt sym_end;       /* symbol table full when sym_next reaches this */
 
     ulg opt_len;        /* bit length of current block with optimal trees */
     ulg static_len;     /* bit length of current block with static trees */
@@ -325,20 +320,22 @@ void ZLIB_INTERNAL _tr_stored_block OF((
 
 # define _tr_tally_lit(s, c, flush) \
   { uch cc = (c); \
-    s->d_buf[s->last_lit] = 0; \
-    s->l_buf[s->last_lit++] = cc; \
+    s->sym_buf[s->sym_next++] = 0; \
+    s->sym_buf[s->sym_next++] = 0; \
+    s->sym_buf[s->sym_next++] = cc; \
     s->dyn_ltree[cc].Freq++; \
-    flush = (s->last_lit == s->lit_bufsize-1); \
+    flush = (s->sym_next == s->sym_end); \
    }
 # define _tr_tally_dist(s, distance, length, flush) \
   { uch len = (uch)(length); \
     ush dist = (ush)(distance); \
-    s->d_buf[s->last_lit] = dist; \
-    s->l_buf[s->last_lit++] = len; \
+    s->sym_buf[s->sym_next++] = dist; \
+    s->sym_buf[s->sym_next++] = dist >> 8; \
+    s->sym_buf[s->sym_next++] = len; \
     dist--; \
     s->dyn_ltree[_length_code[len]+LITERALS+1].Freq++; \
     s->dyn_dtree[d_code(dist)].Freq++; \
-    flush = (s->last_lit == s->lit_bufsize-1); \
+    flush = (s->sym_next == s->sym_end); \
   }
 #else
 # define _tr_tally_lit(s, c, flush) flush = _tr_tally(s, 0, c)
