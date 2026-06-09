$NetBSD: patch-regcomp__study.c,v 1.1.2.2 2026/06/09 22:30:58 maya Exp $

Perl/perl-security#147: test against the actual character lengths
https://github.com/Perl/perl5/commit/5e7f119eb2bb1181be908701f22bf7068e722f1c

--- regcomp_study.c.orig	2026-01-18 17:50:04.000000000 +0000
+++ regcomp_study.c
@@ -2770,6 +2770,13 @@ Perl_study_chunk(pTHX_
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
