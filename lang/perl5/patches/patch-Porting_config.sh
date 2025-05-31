$NetBSD: patch-Porting_config.sh,v 1.1 2025/05/31 19:22:30 wiz Exp $

https://github.com/Perl/perl5/issues/23010
https://github.com/Perl/perl5/commit/918bfff86ca8d6d4e4ec5b30994451e0bd74aba9.patch

--- Porting/config.sh.orig	2025-03-30 10:35:38.000000000 +0000
+++ Porting/config.sh
@@ -223,6 +223,7 @@ d_fd_macros='define'
 d_fd_set='define'
 d_fdclose='undef'
 d_fdim='define'
+d_fdopendir='define'
 d_fds_bits='define'
 d_fegetround='define'
 d_ffs='define'
