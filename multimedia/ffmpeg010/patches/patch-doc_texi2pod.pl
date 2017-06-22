$NetBSD: patch-doc_texi2pod.pl,v 1.1 2017/06/22 06:19:20 markd Exp $

Work with perl 5.26

--- doc/texi2pod.pl.orig	2017-06-22 02:47:15.538575568 +0000
+++ doc/texi2pod.pl
@@ -348,7 +348,7 @@ sub postprocess
     # @* is also impossible in .pod; we discard it and any newline that
     # follows it.  Similarly, our macro @gol must be discarded.
 
-    s/\@anchor{(?:[^\}]*)\}//g;
+    s/\@anchor\{(?:[^\}]*)\}//g;
     s/\(?\@xref\{(?:[^\}]*)\}(?:[^.<]|(?:<[^<>]*>))*\.\)?//g;
     s/\s+\(\@pxref\{(?:[^\}]*)\}\)//g;
     s/;\s+\@pxref\{(?:[^\}]*)\}//g;
