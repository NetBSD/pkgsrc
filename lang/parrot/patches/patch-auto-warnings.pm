$NetBSD: patch-auto-warnings.pm,v 1.1 2016/10/10 21:11:08 joerg Exp $

--- config/auto/warnings.pm.orig	2016-10-09 11:44:20.000000000 +0000
+++ config/auto/warnings.pm
@@ -154,7 +154,6 @@ sub _init {
         -Wstrict-aliasing=2
         -Wswitch
         -Wswitch-default
-        -Werror=undef
         -Wno-unused
         -Wvariadic-macros
         -Wwrite-strings
