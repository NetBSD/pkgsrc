$NetBSD: patch-rsnapshot-program.pl,v 1.1 2013/06/04 18:48:48 wiz Exp $

Fix
pod2man -c '' -n 'rsnapshot' -r '' rsnapshot > rsnapshot.1
rsnapshot around line 6723: You forgot a '=back' before '=head1'
POD document had syntax errors at /usr/pkg/bin/pod2man line 71.

Reported upstream at
https://github.com/DrHyde/rsnapshot/issues/8

--- rsnapshot-program.pl.orig	2008-08-31 11:17:07.000000000 +0000
+++ rsnapshot-program.pl
@@ -6716,6 +6716,8 @@ Putting it all together (an example file
 
 =back
 
+=back
+
 =head1 USAGE
 
 B<rsnapshot> can be used by any user, but for system-wide backups
