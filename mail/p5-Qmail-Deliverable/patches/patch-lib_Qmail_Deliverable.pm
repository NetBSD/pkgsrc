$NetBSD: patch-lib_Qmail_Deliverable.pm,v 1.1 2024/01/10 11:51:46 schmonz Exp $

Honor pkgsrc-specified QMAILDIR.

--- lib/Qmail/Deliverable.pm.orig	2024-01-10 11:42:48.671762270 +0000
+++ lib/Qmail/Deliverable.pm
@@ -66,21 +66,21 @@ sub reread_config {
     %virtualdomains = ();
     %users_exact    = ();
     %users_wild     = ();
-    my $locals_fn = -e "/var/qmail/control/locals"
-        ? "/var/qmail/control/locals"
-        : "/var/qmail/control/me";
+    my $locals_fn = -e "@QMAILDIR@/control/locals"
+        ? "@QMAILDIR@/control/locals"
+        : "@QMAILDIR@/control/me";
     for (_slurp $locals_fn) {
         chomp;
         ($_) = lc =~ /$ascii/ or do { warn "Invalid character"; next; };
         $locals{$_} = 1;
     }
-    for (_slurp "/var/qmail/control/virtualdomains") {
+    for (_slurp "@QMAILDIR@/control/virtualdomains") {
         chomp;
         ($_) = lc =~ /$ascii/ or do { warn "Invalid character"; next; };
         my ($domain, $prepend) = split /:/, $_, 2;
         $virtualdomains{$domain} = $prepend;
     }
-    for (_slurp "/var/qmail/users/assign") {
+    for (_slurp "@QMAILDIR@/users/assign") {
         chomp;
         ($_) = /$ascii/ or do { warn "Invalid character"; next; };
         if (s/^=([^:]+)://) {
@@ -98,7 +98,7 @@ sub reread_config {
 sub _qmail_getpw {
     my ($local) = @_;
     local $/ = "\0";
-    my @a = _readpipe "/var/qmail/bin/qmail-getpw", $local;
+    my @a = _readpipe "@QMAILDIR@/bin/qmail-getpw", $local;
     chomp @a;
     for (@a) {
         ($_) = /$ascii/ or do { warn "Invalid character"; return ""; }
@@ -361,16 +361,16 @@ returned. A single dot at the end is all
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
 
@@ -434,8 +434,8 @@ returned.
 
 =item reread_config
 
-Re-reads the config files /var/qmail/control/locals,
-/var/qmail/control/virtualdomains, and /var/qmail/users/assign.
+Re-reads the config files @QMAILDIR@/control/locals,
+@QMAILDIR@/control/virtualdomains, and @QMAILDIR@/users/assign.
 
 =back
 
@@ -473,7 +473,7 @@ checks per second for assigned/virtual u
 slower. For my needs, this is still plenty fast enough.
 
 To support local users automatically, C<qmail-getpw> is executed for local
-addresses that are not matched by /var/qmail/users/assign. If you need it
+addresses that are not matched by @QMAILDIR@/users/assign. If you need it
 faster, you can use C<qmail-pw2u> to build a users/assign file.
 
 To support vpopmail's vdelivermail instruction, C<valias> is executed for
