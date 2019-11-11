$NetBSD: patch-Safe.pm,v 1.1 2019/11/11 21:32:12 maya Exp $

Use tr/// to force the loading of utf8_heavy, the current code no longer works.
https://github.com/Perl/perl5/issues/17271

--- dist/Safe/Safe.pm.orig	2019-11-11 21:17:50.484290191 +0000
+++ dist/Safe/Safe.pm
@@ -67,7 +67,7 @@ require utf8;
 # particular code points don't cause it to load.
 # (Swashes are cached internally by perl in PL_utf8_* variables
 # independent of being inside/outside of Safe. So once loaded they can be)
-do { my $a = pack('U',0x100); my $b = chr 0x101; utf8::upgrade $b; $a =~ /$b/i };
+do { my $a = pack('U',0x100); my $b = chr 0x101; utf8::upgrade $b; $a =~ tr/\x{202a}-\x{202e}//d };
 # now we can safely include utf8::SWASHNEW in $default_share defined below.
 
 my $default_root  = 0;
