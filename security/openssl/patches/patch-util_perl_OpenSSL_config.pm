$NetBSD: patch-util_perl_OpenSSL_config.pm,v 1.2 2024/04/09 17:16:45 wiz Exp $

a strategic chomp makes openssl on NetBSD/i386 configure

--- util/perl/OpenSSL/config.pm.orig	2024-04-09 12:12:22.000000000 +0000
+++ util/perl/OpenSSL/config.pm
@@ -130,6 +130,7 @@ my $guess_patterns = [
       sub {
           my $hw = `/usr/sbin/sysctl -n hw.model || /sbin/sysctl -n hw.model`;
           $hw =~  s@.*(.)86-class.*@i${1}86@;
+          chomp $hw;
           return "${hw}-whatever-netbsd";
       }
     ],
