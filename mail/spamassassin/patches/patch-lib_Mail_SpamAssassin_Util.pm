$NetBSD: patch-lib_Mail_SpamAssassin_Util.pm,v 1.1 2013/12/04 15:14:19 jperkin Exp $

Part of backport of bug#6937

--- lib/Mail/SpamAssassin/Util.pm.orig	2011-06-06 23:59:17.000000000 +0000
+++ lib/Mail/SpamAssassin/Util.pm
@@ -1582,7 +1582,7 @@ sub regexp_remove_delimiters {
     warn "cannot remove delimiters from null regexp";
     return undef;   # invalid
   }
-  elsif ($re =~ s/^m{//) {              # m{foo/bar}
+  elsif ($re =~ s/^m\{//) {              # m{foo/bar}
     $delim = '}';
   }
   elsif ($re =~ s/^m\(//) {             # m(foo/bar)
