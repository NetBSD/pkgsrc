$NetBSD: patch-lib_Crypt_OpenSSL_DSA.pm,v 1.1 2012/10/02 07:58:00 he Exp $

Document that the verify and do_verify methods will croak on library errors.

--- lib/Crypt/OpenSSL/DSA.pm.orig	2005-10-15 21:38:04.000000000 +0000
+++ lib/Crypt/OpenSSL/DSA.pm
@@ -124,10 +124,14 @@ Verifies that the $sig signature for $me
 
 $dsa is the signer's public key.
 
+Note: it croaks if the underlying library call returns error (-1).
+
 =item $valid = $dsa->do_verify( $message, $sig_obj );
 
 Similar to C<verify>, but uses a L<Crypt::OpenSSL::DSA::Signature> object.
 
+Note: it croaks if the underlying library call returns error (-1).
+
 =item $dsa->write_params( $filename );
 
 Writes the parameters into a PEM file.
