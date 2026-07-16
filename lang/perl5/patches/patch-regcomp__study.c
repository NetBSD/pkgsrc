$NetBSD: patch-regcomp__study.c,v 1.1.4.1 2026/07/16 21:08:19 maya Exp $

Perl versions through 5.43.9 produce silently incorrect regular
expression matches when an alternation of more than 65535 fixed string
branches is compiled into a trie in Perl_study_chunk
https://github.com/Perl/perl5/commit/03f74bbbd3a68350d926ee93d56ee4808c28c4c7.patch

Perl/perl-security#147: test against the actual character lengths
https://github.com/Perl/perl5/commit/5e7f119eb2bb1181be908701f22bf7068e722f1c

--- regcomp_study.c.orig	2026-01-18 17:50:04.000000000 +0000
+++ regcomp_study.c
@@ -1841,6 +1841,16 @@ Perl_study_chunk(pTHX_
                             tail = regnext( tail );
                         }
 
+                        /* The code below currently saves the difference from
+                         * start to finish in a 16-bit field, causing
+                         * GH #23388.  This defeats the design of batching
+                         * tries into chunks that each fit.  khw thinks it is
+                         * too late in the 5.44 cycle to relook at the design,
+                         * so for now anyway, don't make a trie that would
+                         * overflow */
+                        if (tail - startbranch >= U16_MAX) {
+                            continue;
+                        }
 
                         DEBUG_TRIE_COMPILE_r({
                             regprop(RExC_rx, RExC_mysv, tail, NULL, pRExC_state);
@@ -2770,6 +2780,13 @@ Perl_study_chunk(pTHX_
                                                (U8 *) SvEND(data->last_found))
                                 - (U8*)s;
                         l -= old;
+
+                        if (l > 0 &&
+                            (mincount >= SSize_t_MAX / (SSize_t)l
+                             || old > SSize_t_MAX - mincount * (SSize_t)l)) {
+                            FAIL("Regexp out of space");
+                        }
+
                         /* Get the added string: */
                         last_str = newSVpvn_utf8(s  + old, l, UTF);
                         last_chrs = UTF ? utf8_length((U8*)(s + old),
