$NetBSD: patch-util_perl_OpenSSL_config.pm,v 1.1 2023/12/27 15:55:58 spz Exp $

a strategic chomp makes openssl on NetBSD/i386 configure

--- ./util/perl/OpenSSL/config.pm.orig	2023-10-24 13:41:51.000000000 +0000
+++ ./util/perl/OpenSSL/config.pm
@@ -127,8 +127,9 @@ my $guess_patterns = [
     # Order is important, this has to appear before 'NetBSD:.*'
     [ 'NetBSD:.*?:.*?:.*386.*',
       sub {
           my $hw = `/usr/sbin/sysctl -n hw.model || /sbin/sysctl -n hw.model`;
           $hw =~  s@.*(.)86-class.*@i${1}86@;
+          chomp $hw;
           return "${hw}-whatever-netbsd";
       }
     ],
