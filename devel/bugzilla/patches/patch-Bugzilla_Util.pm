$NetBSD: patch-Bugzilla_Util.pm,v 1.1 2019/11/11 20:36:04 maya Exp $

don't truncate bidi control characters, this breaks the build
with perl 5.30

--- Bugzilla/Util.pm.orig	2016-05-16 19:02:18.000000000 +0000
+++ Bugzilla/Util.pm
@@ -101,7 +101,7 @@ sub html_quote {
         # |U+200e|Left-To-Right Mark        |0xe2 0x80 0x8e      |
         # |U+200f|Right-To-Left Mark        |0xe2 0x80 0x8f      |
         # --------------------------------------------------------
-        $var =~ tr/\x{202a}-\x{202e}//d;
+	#$var =~ tr/\x{202a}-\x{202e}//d;
     }
     return $var;
 }
