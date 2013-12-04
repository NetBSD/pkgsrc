$NetBSD: patch-lib_Mail_SpamAssassin_Message.pm,v 1.1 2013/12/04 15:14:19 jperkin Exp $

Part of backport of bug#6937

--- lib/Mail/SpamAssassin/Message.pm.orig	2011-06-06 23:59:17.000000000 +0000
+++ lib/Mail/SpamAssassin/Message.pm
@@ -566,7 +566,7 @@ sub finish {
   while (my $part = shift @toclean) {
     # bug 5557: windows requires tmp file be closed before it can be rm'd
     if (ref $part->{'raw'} eq 'GLOB') {
-      close($part->{'raw'})  or die "error closing input file: $!";
+      close($part->{'raw'})  or warn "error closing input file: $!";
     }
 
     # bug 5858: avoid memory leak with deep MIME structure
