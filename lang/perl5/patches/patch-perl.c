$NetBSD: patch-perl.c,v 1.3 2023/07/03 21:06:13 nikita Exp $

--- perl.c.orig	2023-05-08 22:16:08.305668988 +0200
+++ perl.c	2023-05-08 22:18:56.293971052 +0200
@@ -2015,6 +2015,7 @@
     PUSHs(Perl_newSVpvn_flags(aTHX_ non_bincompat_options,
                               sizeof(non_bincompat_options) - 1, SVs_TEMP));
 
+#define PERL_BUILD_DATE "Jan  1 1970 00:00:00"
 #ifndef PERL_BUILD_DATE
 #  ifdef __DATE__
 #    ifdef __TIME__
