$NetBSD: patch-src_web_login.pl,v 1.1 2014/11/30 10:09:09 markd Exp $

fix usage with CGI >= 4.09

--- src/web_login.pl.orig	2012-09-03 15:24:54.000000000 +0000
+++ src/web_login.pl
@@ -54,7 +54,7 @@ sub web_login {
 	return ;
     }
     
-    my @a = $me->authenticate( $user, $q->param('passwd') );
+    my @a = $me->authenticate( $user, scalar $q->param('passwd') );
 
     unless(@a){
 	my $emsg = l10n('Authentication Failed');
@@ -104,15 +104,15 @@ sub web_login_form {
     print "<H2><FONT COLOR=\"#FF0000\">", l10n('ERROR'), ": $emsg</FONT></H2>\n" if $emsg;
     print "<TABLE WIDTH=\"95%\" cellspacing=0 cellpadding=5>\n<TR><TD VALIGN=TOP>\n";
 
-    print $q->startform(), "\n";
+    print $q->start_form(), "\n";
     print "<INPUT TYPE=HIDDEN NAME=func VALUE=login>\n";
-    print "<INPUT TYPE=HIDDEN NAME=next VALUE=\"", $q->param('next'), "\">\n";
+    print "<INPUT TYPE=HIDDEN NAME=next VALUE=\"", scalar $q->param('next'), "\">\n";
     print "<TABLE>\n";
     print "<TR><TH>", l10n("Username"), ": </TH><TD>", $q->textfield('name', '', 32, 32), "</TD></TR>\n";
     print "<TR><TH>", l10n("Password"), ": </TH><TD>", $q->password_field('passwd', '', 32, 32), "</TD></TR>\n";
     print "<TR><TD COLSPAN=2>", $q->submit(-name=>l10n('Login')), "</TD></TR>\n";
     print "</TABLE><P>\n";
-    print $q->endform(), "\n";
+    print $q->end_form(), "\n";
     print "</TD></TR></TABLE>\n";
 
     print "</TD></TR>\n";
