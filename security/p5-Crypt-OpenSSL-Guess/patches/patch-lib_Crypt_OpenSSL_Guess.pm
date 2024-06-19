$NetBSD: patch-lib_Crypt_OpenSSL_Guess.pm,v 1.1 2024/06/19 10:58:03 jperkin Exp $

Unless OPENSSL_PREFIX is set, return the OpenSSL prefix as configured by pkgsrc.

--- lib/Crypt/OpenSSL/Guess.pm.orig	2024-06-19 10:40:10.000000000 +0000
+++ lib/Crypt/OpenSSL/Guess.pm
@@ -118,6 +118,9 @@ sub find_openssl_prefix {
         return $ENV{OPENSSL_PREFIX};
     }
 
+    # Return the OpenSSL this was built with rather than searching.
+    return "@BUILDLINK_PREFIX.openssl@";
+
     # Homebrew (macOS) or LinuxBrew
     if ($^O ne 'MSWin32' and my $prefix = `brew --prefix --installed openssl 2>@{[File::Spec->devnull]}`) {
         chomp $prefix;
