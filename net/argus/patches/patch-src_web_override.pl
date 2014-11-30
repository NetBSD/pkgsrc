$NetBSD: patch-src_web_override.pl,v 1.1 2014/11/30 10:09:09 markd Exp $

fix usage with CGI >= 4.09

--- src/web_override.pl.orig	2011-10-31 04:16:59.000000000 +0000
+++ src/web_override.pl
@@ -15,7 +15,7 @@ sub web_override {
     my $me = shift;
     my( $q, $st, $r, $obj );
     
-    $obj = decode( $me->{q}->param('object') );
+    $obj = decode( scalar $me->{q}->param('object') );
     return unless $me->check_acl_func($obj, 'override', 1);
     $q = $me->{q};
     
@@ -43,7 +43,7 @@ sub web_override {
 			       text => encode($txt),
 			       mode => $mode,
 			       expires => $q->param('expires') ? ($^T + $q->param('expires')) : 0,
-			       ticket => encode($q->param('ticket')),
+			       ticket => encode(scalar $q->param('ticket')),
 			       );
 	return $me->error( "unable to connect to server" ) unless $r;
 	return $me->error( "Unable to access <I>$obj</I><BR>$r->{resultcode} $r->{resultmsg}" )
@@ -56,7 +56,7 @@ sub web_override {
     $st = get_status($obj);
     my $tkt = $argusd->command( func => 'use_tkt', object => encode($obj) );
 
-    print $q->startform(-method=>'get'), "\n";
+    print $q->start_form(-method=>'get'), "\n";
     print "<INPUT TYPE=HIDDEN NAME=func VALUE=override>\n";
     print "<INPUT TYPE=HIDDEN NAME=phase VALUE=1>\n";
     print "<INPUT TYPE=HIDDEN NAME=object VALUE=", encode($obj), ">\n";
@@ -97,7 +97,7 @@ sub web_override {
                                       [ sort {$a<=>$b} keys %exp ], 4 * 60 * 60, \%exp );
     print "<P>\n";
     print $q->submit(), "\n";
-    print $q->endform(), "\n";
+    print $q->end_form(), "\n";
     print "<HR>\n<I>NB:";
     print l10n("auto mode - disengage override when status returns to up"), "<BR>\n";
     print l10n("manual mode - require override be disengaged manually"), "<BR>\n";
@@ -111,7 +111,7 @@ sub web_rmoverride {
     my $me = shift;
     my( $r, $obj );
     
-    $obj = decode( $me->{q}->param('object') );
+    $obj = decode( scalar $me->{q}->param('object') );
     return unless $me->check_acl_func($obj, 'override', 1);
 
     if( $me->can('override_policy') ){
@@ -134,7 +134,7 @@ sub web_annotate {
     my $me = shift;
     my( $obj, $r, $q );
 
-    $obj = decode( $me->{q}->param('object') );
+    $obj = decode( scalar $me->{q}->param('object') );
     return unless $me->check_acl_func($obj, 'annotate', 1);
     if( $me->{q}->param('phase') ){
 	my $txt = $me->{q}->param('text');
@@ -156,7 +156,7 @@ sub web_annotate {
     $me->startpage( title => l10n("Annotate") . " $obj" );
     $q = $me->{q}; 
 
-    print $q->startform(-method=>'get'), "\n";
+    print $q->start_form(-method=>'get'), "\n";
     print "<INPUT TYPE=HIDDEN NAME=func VALUE=annotate>\n";
     print "<INPUT TYPE=HIDDEN NAME=phase VALUE=1>\n";
     print "<INPUT TYPE=HIDDEN NAME=object VALUE=", encode($obj), ">\n";
@@ -165,7 +165,7 @@ sub web_annotate {
     # QQQ - include note that javascript is not properly installed/configured?
 
     print $q->submit(), "\n";
-    print $q->endform(), "\n";
+    print $q->end_form(), "\n";
     $me->endpage();
 }
 
