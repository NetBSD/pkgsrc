$NetBSD: patch-doc_doxyparse.pl,v 1.1 2015/06/18 13:04:29 jperkin Exp $

perl-5.22 compatibility.

--- doc/doxyparse.pl.orig	2014-01-10 21:04:41.000000000 +0000
+++ doc/doxyparse.pl
@@ -273,7 +273,7 @@ foreach (keys %manpages) {
 
 	print MAN $MAN_MIDDLE;
 
-	if (defined(@$also)) {
+	if (@$also) {
 		print MAN "\n.SH SEE ALSO\n\\fI";
 		print MAN join "\\fR, \\fI", @$also;
 		print MAN "\\fR.\nAnd ";
