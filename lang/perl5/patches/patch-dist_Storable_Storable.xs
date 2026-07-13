$NetBSD: patch-dist_Storable_Storable.xs,v 1.1 2026/07/13 18:44:25 wiz Exp $

Storable versions before 3.41 for Perl have a signed integer overflow
when deserializing a crafted SX_HOOK record
https://github.com/Perl/perl5/commit/e4f681784bcdeaa91ff02a2fa4cdcae5c46779d7.patch

--- dist/Storable/Storable.xs.orig	2026-01-18 17:50:04.000000000 +0000
+++ dist/Storable/Storable.xs
@@ -5035,7 +5035,10 @@ static SV *retrieve_hook_common(pTHX_ stcxt_t *cxt, co
         }
         else
             GETMARK(len3);
-        if (len3) {
+        if (len3 == I32_MAX)
+            /* If len3 is exactly I32_MAX it will upset av_extend below */
+            CROAK(("Invalid count of hook data items"));
+        else if (len3) {
             av = newAV();
             av_extend(av, len3 + 1);    /* Leave room for [0] */
             AvFILLp(av) = len3;         /* About to be filled anyway */
