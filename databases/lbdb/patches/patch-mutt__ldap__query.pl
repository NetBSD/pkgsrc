$NetBSD: patch-mutt__ldap__query.pl,v 1.1 2013/06/12 12:38:20 wiz Exp $

Fix bug in man page noted by perl-5.18's pod2man.

--- mutt_ldap_query.pl.orig	2013-06-12 12:13:03.000000000 +0000
+++ mutt_ldap_query.pl
@@ -539,6 +539,8 @@ multiple searches for email addresses ba
 just like this one 8-)
  http://www.spinnaker.de/lbdb/
 
+=back
+
 =head1 AUTHORS
 
 Marc de Courville <marc@courville.org> and the various other contributors... that kindly sent their patches.
