$NetBSD: patch-lib_Text_Typography.pm,v 1.1 2013/07/17 21:18:23 schmonz Exp $

From <URL:https://rt.cpan.org/Public/Bug/Display.html?id=79229>:
fix "uninitialized value" warnings.

--- lib/Text/Typography.pm.orig	2006-01-10 04:31:02.000000000 +0000
+++ lib/Text/Typography.pm
@@ -540,7 +540,7 @@ sub EducateQuotes {
     } {$1&#8216;}xg;
     # Single closing quotes:
     s {
-        ($close_class)?
+        ($close_class?)
         '
         (?(1)|          # If $1 captured, then do nothing;
           (?=\s | s\b)  # otherwise, positive lookahead for a whitespace
@@ -569,7 +569,7 @@ sub EducateQuotes {
 
     # Double closing quotes:
     s {
-        ($close_class)?
+        ($close_class?)
         "
         (?(1)|(?=\s))   # If $1 captured, then do nothing;
                            # if not, then make sure the next char is whitespace.
