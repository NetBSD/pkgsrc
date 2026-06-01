$NetBSD: patch-lib_Text_LineFold.pm,v 1.1 2026/06/01 14:10:34 wiz Exp $

Fix CVE-2026-8594
https://security.metacpan.org/patches/U/Unicode-LineBreak/2019.001/CVE-2026-8594-r1.patch

--- lib/Text/LineFold.pm.orig	2018-12-29 04:19:20.000000000 +0000
+++ lib/Text/LineFold.pm
@@ -410,7 +410,7 @@ sub fold {
         if ($s =~ $special_break) {
             $result .= $s;
         } else {
-            $result .= $self->break($str);
+            $result .= $self->break($s);
         }
     }
 
