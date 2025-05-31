$NetBSD: patch-configure.com,v 1.1 2025/05/31 19:22:30 wiz Exp $

https://github.com/Perl/perl5/issues/23010
https://github.com/Perl/perl5/commit/918bfff86ca8d6d4e4ec5b30994451e0bd74aba9.patch

--- configure.com.orig	2025-03-30 10:35:38.000000000 +0000
+++ configure.com
@@ -6010,6 +6010,7 @@ $ WC "d_fd_set='" + d_fd_set + "'"
 $ WC "d_fd_macros='define'"
 $ WC "d_fdclose='undef'"
 $ WC "d_fdim='" + d_fdim + "'"
+$ WC "d_fdopendir='undef'"
 $ WC "d_fds_bits='define'"
 $ WC "d_fegetround='undef'"
 $ WC "d_ffs='undef'"
