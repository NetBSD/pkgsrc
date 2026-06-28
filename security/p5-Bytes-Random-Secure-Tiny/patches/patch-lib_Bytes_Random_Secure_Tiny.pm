$NetBSD: patch-lib_Bytes_Random_Secure_Tiny.pm,v 1.1.2.2 2026/06/28 18:26:39 bsiegert Exp $

Fix CVE-2026-11702.
https://security.metacpan.org/patches/B/Bytes-Random-Secure-Tiny/1.011/CVE-2026-11702-r1.patch

--- lib/Bytes/Random/Secure/Tiny.pm.orig	2020-09-25 17:56:00.000000000 +0000
+++ lib/Bytes/Random/Secure/Tiny.pm
@@ -310,18 +310,46 @@ sub new {
     $bits = delete $args{bits} if exists $args{bits};
     croak "Number of bits must be 64 <= n <= 8192, and a multipe in 2^n: $bits"
         if $bits < 64 || $bits > 8192 || !_ispowerof2($bits);
-    return Hash::Util::lock_hashref bless {
-        bits => $bits,
-        _rng => Math::Random::ISAAC::Embedded->new(do{
-            my $source = Crypt::Random::Seed::Embedded->new(%args)
-                or croak 'Could not get a seed source.';
-            $source->random_values($bits/32);
-        }),
+    # Fork safety: the engine + the PID that seeded it live in a nested hash.
+    # lock_hashref (below) makes the top-level _state *reference* read-only, but
+    # the hash it points to stays mutable, so a forked child can swap in a fresh
+    # engine and record its own PID without unlocking. _seed_args/bits are kept
+    # so the child can re-seed identically.
+    $self = bless {
+        bits       => $bits,
+        _seed_args => {%args},
+        _state     => { pid => $$ },
     }, $class;
+    $self->{_state}{rng} = $self->_seed_rng;
+    return Hash::Util::lock_hashref $self;
 }
 
+sub _seed_rng {
+    my $self = shift;
+    return Math::Random::ISAAC::Embedded->new(do{
+        my $source = Crypt::Random::Seed::Embedded->new(%{$self->{_seed_args}})
+            or croak 'Could not get a seed source.';
+        $source->random_values($self->{bits}/32);
+    });
+}
+
 sub _ispowerof2 {my $n = shift; return ($n >= 0) && (($n & ($n-1)) ==0 )}
-sub irand {shift->{'_rng'}->irand}
+
+# All random output (bytes, bytes_hex, string_from, shuffle) funnels through
+# irand, so the fork guard lives here once. If the PID changed, this process is
+# a fork() child that inherited the parent's ISAAC state; re-seed from fresh
+# entropy and record the new PID so the re-seed happens at most once per fork.
+# Reading $$ is a cached variable (no syscall). Threads are out of scope (a new
+# thread keeps $$) and remain caller-responsibility per the POD.
+sub irand {
+    my $self  = shift;
+    my $state = $self->{'_state'};
+    if ($state->{pid} != $$) {
+        $state->{rng} = $self->_seed_rng;
+        $state->{pid} = $$;
+    }
+    return $state->{rng}->irand;
+}
 sub bytes_hex {unpack 'H*', shift->bytes(shift)} # lc Hex digits only, no '0x'
 
 sub bytes {
