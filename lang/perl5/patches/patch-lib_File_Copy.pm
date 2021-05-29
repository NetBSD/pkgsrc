$NetBSD: patch-lib_File_Copy.pm,v 1.1 2021/05/29 13:04:21 rin Exp $

Compare inode numbers as string to fix pkg/55997. Cherry-picked from
upstream. See https://github.com/Perl/perl5/pull/18788 for more details.

--- lib/File/Copy.pm.orig	2020-12-18 19:04:36.000000000 +0900
+++ lib/File/Copy.pm	2021-05-13 17:06:58.528282999 +0900
@@ -104,7 +104,7 @@
 	my @fs = stat($from);
 	if (@fs) {
 	    my @ts = stat($to);
-	    if (@ts && $fs[0] == $ts[0] && $fs[1] == $ts[1] && !-p $from) {
+	    if (@ts && $fs[0] == $ts[0] && $fs[1] eq $ts[1] && !-p $from) {
 		carp("'$from' and '$to' are identical (not copied)");
                 return 0;
 	    }
