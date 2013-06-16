$NetBSD: patch-lily_mensural-ligature.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/mensural-ligature.cc.orig	2013-06-16 19:09:43.000000000 +0000
+++ lily/mensural-ligature.cc
@@ -168,7 +168,7 @@ internal_brew_primitive (Grob *me)
       duration_log--;
     case MLP_BREVIS:
       duration_log--;
-      suffix = to_string (duration_log) + color
+      suffix = ::to_string (duration_log) + color
                + (duration_log < -1 ? "lig" : "") + "mensural";
       index = prefix + "s";
       out = fm->find_by_name (index + "r" + suffix);
