$NetBSD: patch-lib_Bytes_Random_Secure.pm,v 1.1.2.2 2026/06/28 18:25:36 bsiegert Exp $

Fix CVE-2026-11625.
https://security.metacpan.org/patches/B/Bytes-Random-Secure/0.29/CVE-2026-11625-r1.patch

--- lib/Bytes/Random/Secure.pm.orig	2015-07-13 04:38:06.000000000 +0000
+++ lib/Bytes/Random/Secure.pm
@@ -156,6 +156,7 @@ sub _build_attributes {
       $self->{$arg} = exists $args->{$arg} ? $args->{$arg} : $default;
     }
 
+    $self->{_pid} = $$;
     $self->{_RNG} = undef;    # Lazy initialization.
     return $self;
 }
@@ -171,6 +172,8 @@ sub _instantiate_rng {
     my @seeds = $self->_generate_seed( %seed_opts );
     $self->{_RNG} = Math::Random::ISAAC->new(@seeds);
 
+    $self->{_pid} = $$;
+
     return $self->{_RNG};
 }
 
@@ -224,7 +227,7 @@ sub bytes {
   $bytes = defined $bytes ? $bytes : 0; # Default to zero bytes.
   $self->_validate_int( $bytes ); # Throws on violation.
 
-  $self->_instantiate_rng unless defined $self->{_RNG};
+  $self->_instantiate_rng unless $$ == $self->{_pid} && defined $self->{_RNG};
 
   my $str = '';
 
@@ -302,7 +305,7 @@ sub _ranged_randoms {
     $count = defined $count ? $count : 0;
 
     # Lazily seed the RNG so we don't waste available strong entropy.
-    $self->_instantiate_rng unless defined $self->{_RNG};
+    $self->_instantiate_rng unless $$ == $self->{_pid} && defined $self->{_RNG};
 
     my $divisor = $self->_closest_divisor($range);
 
@@ -354,7 +357,7 @@ sub irand {
 
 sub irand {
   my( $self ) = @_;
-  $self->_instantiate_rng unless defined $self->{_RNG};
+  $self->_instantiate_rng unless $$ == $self->{_pid} && defined $self->{_RNG};
   return $self->{_RNG}->irand;
 }
 
