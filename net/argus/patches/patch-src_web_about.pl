$NetBSD: patch-src_web_about.pl,v 1.1 2014/11/30 10:09:09 markd Exp $

fix usage with CGI >= 4.09

--- src/web_about.pl.orig	2011-11-03 02:13:41.000000000 +0000
+++ src/web_about.pl
@@ -20,7 +20,7 @@ sub web_about {
     my $me = shift;
     my( $obj, $r, $k, $v );
 
-    $obj  = decode( $me->{q}->param('object') );
+    $obj  = decode( scalar $me->{q}->param('object') );
     return unless $me->check_acl_func($obj, 'about', 1);
 
     $r = $argusd->command( func => 'about',
