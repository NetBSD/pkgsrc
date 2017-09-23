$NetBSD: patch-regcomp.c,v 1.1 2017/09/23 05:29:07 maya Exp $

Fixes for CVE-2017-12837: heap buffer overflow in regular expression compiler
CVE-2017-12883 Buffer over-read in regular expression parser

From 2be4edede4ae226e2eebd4eff28cedd2041f300f Mon Sep 17 00:00:00 2001
From: Karl Williamson <khw@cpan.org>
Date: Fri, 25 Aug 2017 11:33:58 -0600
Subject: [PATCH] PATCH: [perl #131598]

The cause of this is that the vFAIL macro uses RExC_parse, and that
variable has just been changed in preparation for code after the vFAIL.
The solution is to not change RExC_parse until after the vFAIL.

This is a case where the macro hides stuff that can bite you.

From 96c83ed78aeea1a0496dd2b2d935869a822dc8a5 Mon Sep 17 00:00:00 2001
From: Karl Williamson <khw@cpan.org>
Date: Wed, 21 Jun 2017 11:33:37 -0600
Subject: [PATCH] regcomp [perl #131582]


--- regcomp.c.orig	2017-04-19 13:37:08.000000000 +0000
+++ regcomp.c
@@ -12159,14 +12159,16 @@ S_grok_bslash_N(pTHX_ RExC_state_t *pREx
 	}
         sv_catpv(substitute_parse, ")");
 
-        RExC_parse = RExC_start = RExC_adjusted_start = SvPV(substitute_parse,
-                                                             len);
+        len = SvCUR(substitute_parse);
 
 	/* Don't allow empty number */
 	if (len < (STRLEN) 8) {
             RExC_parse = endbrace;
 	    vFAIL("Invalid hexadecimal number in \\N{U+...}");
 	}
+
+        RExC_parse = RExC_start = RExC_adjusted_start
+                                              = SvPV_nolen(substitute_parse);
 	RExC_end = RExC_parse + len;
 
         /* The values are Unicode, and therefore not subject to recoding, but
@@ -13229,6 +13231,7 @@ S_regatom(pTHX_ RExC_state_t *pRExC_stat
                             goto loopdone;
                         }
                         p = RExC_parse;
+                        RExC_parse = parse_start;
                         if (ender > 0xff) {
                             REQUIRE_UTF8(flagp);
                         }
