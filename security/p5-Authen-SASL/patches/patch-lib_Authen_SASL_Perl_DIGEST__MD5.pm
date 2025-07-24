$NetBSD: patch-lib_Authen_SASL_Perl_DIGEST__MD5.pm,v 1.1.2.2 2025/07/24 22:21:07 maya Exp $

https://security.metacpan.org/patches/A/Authen-SASL/2.1800/CVE-2025-40918-r1.patch

--- lib/Authen/SASL/Perl/DIGEST_MD5.pm.orig	2025-04-25 16:09:30.000000000 +0000
+++ lib/Authen/SASL/Perl/DIGEST_MD5.pm
@@ -10,6 +10,7 @@ $Authen::SASL::Perl::DIGEST_MD5::VERSION
 use strict;
 use warnings;
 use vars qw(@ISA $CNONCE $NONCE);
+use Crypt::URandom qw(urandom);
 use Digest::MD5 qw(md5_hex md5);
 use Digest::HMAC_MD5 qw(hmac_md5);
 
@@ -201,7 +202,7 @@ sub server_start {
 
   $self->{need_step} = 1;
   $self->{error}     = undef;
-  $self->{nonce}     = md5_hex($NONCE || join (":", $$, time, rand));
+  $self->{nonce}     = $NONCE? md5_hex($NONCE) : unpack('H32',urandom(16));
 
   $self->init_sec_layer;
 
@@ -260,7 +261,7 @@ sub client_step {   # $self, $server_sas
 
   my %response = (
     nonce        => $sparams{'nonce'},
-    cnonce       => md5_hex($CNONCE || join (":", $$, time, rand)),
+    cnonce       => $CNONCE? md5_hex($CNONCE) : unpack('H32',urandom(16)),
     'digest-uri' => $self->service . '/' . $self->host,
     # calc how often the server nonce has been seen; server expects "00000001"
     nc           => sprintf("%08d",     ++$self->{nonce_counts}{$sparams{'nonce'}}),
