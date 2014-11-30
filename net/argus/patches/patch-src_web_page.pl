$NetBSD: patch-src_web_page.pl,v 1.1 2014/11/30 10:09:09 markd Exp $

fix usage with CGI >= 4.09

--- src/web_page.pl.orig	2012-10-02 01:38:26.000000000 +0000
+++ src/web_page.pl
@@ -19,7 +19,7 @@ sub web_page {
     my( $r, $file, $warning, $siren_icon, $cached );
 
     my $cakestale = $CAKESTALE;
-    my $obj  = decode( $me->{q}->param('object') );
+    my $obj  = decode( scalar $me->{q}->param('object') );
     my $topp = $me->{q}->param('top');
     my $url  = $me->{q}->url( -path_info => 1 );
     my $user = $me->{auth}{user};
