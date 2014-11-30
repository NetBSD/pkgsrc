$NetBSD: patch-src_web_graph.pl,v 1.1 2014/11/30 10:09:09 markd Exp $

fix usage with CGI >= 4.09

--- src/web_graph.pl.orig	2012-10-02 01:38:26.000000000 +0000
+++ src/web_graph.pl
@@ -20,7 +20,7 @@ sub web_graph {
     my( $file, $ht, $r, $buf, $i );
 
     my $q   = $me->{q};
-    my $obj = decode( $q->param('object') );
+    my $obj = decode( scalar $q->param('object') );
     my $tag = $q->param('tag');
     my $which = $q->param('which');
     my $size  = $q->param('size');
@@ -142,7 +142,7 @@ sub web_graphpage {
     my $me = shift;
     my( $obj, $which, $size, $r, $back, @opt );
 
-    $obj = decode( $me->{q}->param('object') );
+    $obj = decode( scalar $me->{q}->param('object') );
     my $tag = $me->{q}->param('tag');
     my $url = $me->{q}->url();
 
