$NetBSD: patch-pan_usenet-utils_rules-info.cc,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/usenet-utils/rules-info.cc.orig	2013-06-16 10:37:35.000000000 +0000
+++ pan/usenet-utils/rules-info.cc
@@ -39,7 +39,7 @@ void
 RulesInfo :: clear ()
 {
   _type = RulesInfo::TYPE__ERR;
-  _aggregates.clear ();
+  _aggregates->clear ();
   _lb = _hb = 0;
   _ge = 0;
   _negate = false;
