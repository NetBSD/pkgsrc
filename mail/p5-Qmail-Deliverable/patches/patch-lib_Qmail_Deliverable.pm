$NetBSD: patch-lib_Qmail_Deliverable.pm,v 1.2 2024/01/28 21:10:35 schmonz Exp $

Honor pkgsrc-specified QMAILDIR.

--- lib/Qmail/Deliverable.pm.orig	2024-01-27 19:55:05.000000000 +0000
+++ lib/Qmail/Deliverable.pm
@@ -9,7 +9,7 @@ our $VERSION = '1.09';
 our @EXPORT_OK = qw/reread_config qmail_local dot_qmail deliverable qmail_user/;
 our %EXPORT_TAGS = (all => \@EXPORT_OK);
 our $VPOPMAIL_EXT = 0;
-our $qmail_dir = '/var/qmail';
+our $qmail_dir = '@QMAILDIR@';
 
 # rfc2822's "atext"
 my $atext = "[A-Za-z0-9!#\$%&\'*+\/=?^_\`{|}~-]";
@@ -101,7 +101,7 @@ sub reread_config {
 sub _qmail_getpw {
     my ($local) = @_;
     local $/ = "\0";
-    my @a = _readpipe "/var/qmail/bin/qmail-getpw", $local;
+    my @a = _readpipe "@QMAILDIR@/bin/qmail-getpw", $local;
     chomp @a;
     for (@a) {
         ($_) = /$ascii/ or do { warn "Invalid character"; return ""; }
@@ -368,16 +368,16 @@ returned. A single dot at the end is all
 Returns the local qmail user for $address, or undef if the address is not local.
 
 Returns $address if it does not contain an @. Returns the left side of the @ if
-the right side is listed in /var/qmail/control/locals. Returns the left side of
+the right side is listed in @QMAILDIR@/control/locals. Returns the left side of
 the @, prepended with the right prepend string, if the right side is listed in
-/var/qmail/control/virtualdomains.
+@QMAILDIR@/control/virtualdomains.
 
 =item qmail_user $address
 
 =item qmail_user $local
 
 Returns a list of $user, $uid, $gid, $homedir, $dash, $ext according to
-/var/qmail/users/assign or qmail-getpw.
+@QMAILDIR@/users/assign or qmail-getpw.
 
 =item dot_qmail $address
 
@@ -442,8 +442,8 @@ returned.
 
 =item reread_config
 
-Re-reads the config files /var/qmail/control/locals,
-/var/qmail/control/virtualdomains, and /var/qmail/users/assign.
+Re-reads the config files @QMAILDIR@/control/locals,
+@QMAILDIR@/control/virtualdomains, and @QMAILDIR@/users/assign.
 
 =back
 
@@ -481,7 +481,7 @@ checks per second for assigned/virtual u
 slower. For my needs, this is still plenty fast enough.
 
 To support local users automatically, C<qmail-getpw> is executed for local
-addresses that are not matched by /var/qmail/users/assign. If you need it
+addresses that are not matched by @QMAILDIR@/users/assign. If you need it
 faster, you can use C<qmail-pw2u> to build a users/assign file.
 
 To support vpopmail's vdelivermail instruction, C<valias> is executed for
