$NetBSD: patch-lib_Net_Server_Multiplex.pm,v 1.1 2025/06/30 11:23:50 kim Exp $

Avoid an error from calling import with a version argument.  Instead
implement the version requirement by calling VERSION.

- IO::Multiplex does not define an import method.
- The import method inherited from the UNIVERSAL class does not accept
  a version argument.

Ref: https://perldoc.perl.org/5.39.1/perl5391delta#Calling-the-import-method-of-an-unknown-package-produces-an-error

--- lib/Net/Server/Multiplex.pm.orig	2022-12-02 01:14:55.000000000 +0000
+++ lib/Net/Server/Multiplex.pm	2025-06-29 16:14:17.366034379 +0000
@@ -23,7 +23,7 @@
 use base qw(Net::Server);
 use Net::Server::SIG qw(register_sig check_sigs);
 use Carp qw(confess);
-eval { require IO::Multiplex; import IO::Multiplex 1.05; };
+eval { require IO::Multiplex; IO::Multiplex->VERSION(1.05); };
 $@ && warn "Module IO::Multiplex is required for Multiplex.";
 
 our $VERSION = $Net::Server::VERSION;
