$NetBSD: patch-zlib_inflate.c,v 1.1 2026/07/27 15:38:31 ryoon Exp $

--- zlib/inflate.c.orig	2010-09-16 17:17:49.000000000 +0000
+++ zlib/inflate.c
@@ -637,6 +637,7 @@ int flush;
             if (state->flags & 0x0200) CRC2(state->check, hold);
             INITBITS();
             state->mode = EXLEN;
+            /* FALLTHROUGH */
         case EXLEN:
             if (state->flags & 0x0400) {
                 NEEDBITS(16);
@@ -645,6 +646,7 @@ int flush;
                 INITBITS();
             }
             state->mode = EXTRA;
+            /* FALLTHROUGH */
         case EXTRA:
             if (state->flags & 0x0400) {
                 copy = state->length;
@@ -659,6 +661,7 @@ int flush;
                 if (state->length) goto inf_leave;
             }
             state->mode = NAME;
+            /* FALLTHROUGH */
         case NAME:
             if (state->flags & 0x0800) {
                 if (have == 0) goto inf_leave;
@@ -673,6 +676,7 @@ int flush;
                 if (len) goto inf_leave;
             }
             state->mode = COMMENT;
+            /* FALLTHROUGH */
         case COMMENT:
             if (state->flags & 0x1000) {
                 if (have == 0) goto inf_leave;
@@ -687,6 +691,7 @@ int flush;
                 if (len) goto inf_leave;
             }
             state->mode = HCRC;
+            /* FALLTHROUGH */
         case HCRC:
             if (state->flags & 0x0200) {
                 NEEDBITS(16);
@@ -706,6 +711,7 @@ int flush;
             strm->adler = state->check = REVERSE(hold);
             INITBITS();
             state->mode = DICT;
+            /* FALLTHROUGH */
         case DICT:
             if (state->havedict == 0) {
                 RESTORE();
@@ -713,8 +719,10 @@ int flush;
             }
             strm->adler = state->check = adler32(0L, Z_NULL, 0);
             state->mode = TYPE;
+            /* FALLTHROUGH */
         case TYPE:
             if (flush == Z_BLOCK) goto inf_leave;
+            /* FALLTHROUGH */
         case TYPEDO:
             if (state->last) {
                 BYTEBITS();
@@ -760,6 +768,7 @@ int flush;
                     state->length));
             INITBITS();
             state->mode = COPY;
+            /* FALLTHROUGH */
         case COPY:
             copy = state->length;
             if (copy) {
@@ -890,6 +899,7 @@ int flush;
             }
             Tracev((stderr, "inflate:       codes ok\n"));
             state->mode = LEN;
+            /* FALLTHROUGH */
         case LEN:
 	    state->mode = LENDO;
 	    goto inf_leave;
@@ -931,6 +941,7 @@ int flush;
             }
             state->extra = (unsigned)(this.op) & 15;
             state->mode = LENEXT;
+            /* FALLTHROUGH */
         case LENEXT:
             if (state->extra) {
                 NEEDBITS(state->extra);
@@ -939,6 +950,7 @@ int flush;
             }
             Tracevv((stderr, "inflate:         length %u\n", state->length));
             state->mode = DIST;
+            /* FALLTHROUGH */
         case DIST:
             for (;;) {
                 this = state->distcode[BITS(state->distbits)];
@@ -964,6 +976,7 @@ int flush;
             state->offset = (unsigned)this.val;
             state->extra = (unsigned)(this.op) & 15;
             state->mode = DISTEXT;
+            /* FALLTHROUGH */
         case DISTEXT:
             if (state->extra) {
                 NEEDBITS(state->extra);
@@ -977,6 +990,7 @@ int flush;
             }
             Tracevv((stderr, "inflate:         distance %u\n", state->offset));
             state->mode = MATCH;
+            /* FALLTHROUGH */
         case MATCH:
             if (left == 0) goto inf_leave;
             copy = out - left;
@@ -1032,6 +1046,7 @@ int flush;
             }
 #ifdef GUNZIP
             state->mode = LENGTH;
+            /* FALLTHROUGH */
         case LENGTH:
             if (state->wrap && state->flags) {
                 NEEDBITS(32);
@@ -1045,6 +1060,7 @@ int flush;
             }
 #endif
             state->mode = DONE;
+            /* FALLTHROUGH */
         case DONE:
             ret = Z_STREAM_END;
             goto inf_leave;
