$NetBSD: patch-lib_Net_SSH_Perl_Kex.pm,v 1.1 2017/08/23 14:52:53 he Exp $

At least output a debug message if use of the key exchange algo fails.

--- lib/Net/SSH/Perl/Kex.pm.orig	2017-03-15 10:12:27.000000000 +0000
+++ lib/Net/SSH/Perl/Kex.pm
@@ -232,6 +232,9 @@ sub choose_kex {
     if (my $pkg = $kexmap{$name}) {
         $kex->{ssh}->debug("Using $name for key exchange");
         eval "use Net::SSH::Perl::Kex::$pkg";
+	if ($@) {
+	    $kex->{ssh}->debug("Problem doing use Net::SSH::Perl::Kex::$pkg: $@");
+	}
         $kex->{class_name} = __PACKAGE__ . '::' . $pkg;
     } else {
         croak "Bad kex algorithm $name";
