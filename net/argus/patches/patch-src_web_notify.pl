$NetBSD: patch-src_web_notify.pl,v 1.1 2014/11/30 10:09:09 markd Exp $

fix usage with CGI >= 4.09

--- src/web_notify.pl.orig	2011-11-03 02:13:41.000000000 +0000
+++ src/web_notify.pl
@@ -60,7 +60,7 @@ sub notify_list {
                        mainclass => 'notifiesmain',
                        branding  => decode($r->{branding}) );
 
-    print $q->startform(-method=>'get'), "\n" if $ackp;
+    print $q->start_form(-method=>'get'), "\n" if $ackp;
     print "<TR><TD colspan=2><TABLE class=notifylist WIDTH=\"100%\" CELLSPACING=0 CELLPADDING=0>\n";
 
     foreach my $nd (@{$res->{data}}){
@@ -90,7 +90,7 @@ sub notify_list {
 	print "<BR><INPUT TYPE=HIDDEN NAME=func VALUE=ntfyack>\n";
 	print $q->submit(l10n("Ack Checked")), "\n";
 	print $q->submit(l10n("Ack All")), "\n";
-	print $q->endform(), "\n";
+	print $q->end_form(), "\n";
     }
 
     unless( $n ){
