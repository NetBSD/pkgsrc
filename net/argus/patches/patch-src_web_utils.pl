$NetBSD: patch-src_web_utils.pl,v 1.1 2014/11/30 10:09:09 markd Exp $

fix usage with CGI >= 4.09

--- src/web_utils.pl.orig	2011-10-30 21:00:29.000000000 +0000
+++ src/web_utils.pl
@@ -15,7 +15,7 @@ sub web_getconf {
     my $me = shift;
     my( $obj, $r, $k, $v );
 
-    $obj  = decode( $me->{q}->param('object') );
+    $obj  = decode( scalar $me->{q}->param('object') );
     return unless $me->check_acl_func($obj, 'getconf', 1);
     my $rd = $argusd->command( func => 'logindata' ) || {};
     return $me->error( "unable to connect to server" ) unless $rd;
@@ -59,7 +59,7 @@ sub web_getconf {
 sub web_flushcache {
     my $me = shift;
 
-    my $obj = decode( $me->{q}->param('object') );
+    my $obj = decode( scalar $me->{q}->param('object') );
     return unless $me->check_acl_func($obj, 'flush', 1);
     my $r = $argusd->command( func   => 'flushpage',
 			      object => encode($obj),
@@ -75,7 +75,7 @@ sub web_flushcache {
 sub web_checknow {
     my $me = shift;
 
-    my $obj = decode( $me->{q}->param('object') );
+    my $obj = decode( scalar $me->{q}->param('object') );
     return unless $me->check_acl_func($obj, 'checknow', 1);
     my $r = $argusd->command( func   => 'checknow',
 			      object => encode($obj),
