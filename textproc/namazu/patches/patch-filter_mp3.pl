$NetBSD: patch-filter_mp3.pl,v 1.1 2015/03/15 01:20:24 taca Exp $

Use correct regular expression to stop warning on perl 5.20 and later.

--- filter/mp3.pl.orig	2008-05-09 08:37:44.000000000 +0000
+++ filter/mp3.pl
@@ -152,7 +152,7 @@ sub mp3_filter($$$$) {
     mp3::get_title($$contref, $weighted_str, $fields);
     mp3::get_author($$contref, $fields);
     mp3::get_album($$contref, $fields);
-    $$contref =~ s/^\w+:{1,1}?//gm;
+    $$contref =~ s/^\w+(:{1,1})?//gm;
 
     return;
 }
