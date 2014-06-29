$NetBSD: patch-tmpl2c.pl,v 1.1 2014/06/29 16:19:38 schmonz Exp $

do SUBROUTINE(LIST) was long deprecated and is an error in 5.20.0.

--- tmpl2c.pl.orig	2014-06-29 16:09:52.000000000 +0000
+++ tmpl2c.pl
@@ -205,7 +205,7 @@ sub convert {
     return (undef, undef) unless $icode = $icode || &getcode(*_);
     $ocode = 'jis' unless $ocode;
     local(*convf) = $convf{$icode, $ocode};
-    do convf(*_);
+    convf(*_);
     (*convf, $icode);
 }
 
