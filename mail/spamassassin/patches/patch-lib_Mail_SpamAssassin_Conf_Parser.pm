$NetBSD: patch-lib_Mail_SpamAssassin_Conf_Parser.pm,v 1.1 2013/12/04 15:14:19 jperkin Exp $

Part of backport of bug#6937

--- lib/Mail/SpamAssassin/Conf/Parser.pm.orig	2011-06-06 23:59:17.000000000 +0000
+++ lib/Mail/SpamAssassin/Conf/Parser.pm
@@ -1248,7 +1248,7 @@ sub is_regexp_valid {
   my $safere = $re;
   my $mods = '';
   local ($1,$2);
-  if ($re =~ s/^m{//) {
+  if ($re =~ s/^m\{//) {
     $re =~ s/}([a-z]*)$//; $mods = $1;
   }
   elsif ($re =~ s/^m\(//) {
