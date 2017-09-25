$NetBSD: patch-lib_ZnapZend.pm,v 1.1 2017/09/25 10:50:28 wiedi Exp $

Fix Mojo::Util::slurp is DEPRECATED
https://github.com/oetiker/znapzend/pull/283
--- lib/ZnapZend.pm.orig	2017-02-08 07:38:40.000000000 +0000
+++ lib/ZnapZend.pm
@@ -2,7 +2,8 @@ package ZnapZend;
 
 use Mojo::Base -base;
 use Mojo::IOLoop::ForkCall;
-use Mojo::Util qw(slurp);
+use Mojo::File 'path';
+use Mojo::Util;
 use Mojo::Log;
 use ZnapZend::Config;
 use ZnapZend::ZFS;
@@ -573,7 +574,7 @@ my $daemonize = sub {
     my $pidFile = $self->pidfile || $self->defaultPidFile;
 
     if (-f $pidFile){
-        chomp(my $pid = slurp $pidFile);
+        chomp(my $pid = path($pidFile)->slurp);
         #pid is not empty and is numeric
         if ($pid && ($pid = int($pid)) && kill 0, $pid){
             die "I Quit! Another copy of znapzend ($pid) seems to be running. See $pidFile\n";
