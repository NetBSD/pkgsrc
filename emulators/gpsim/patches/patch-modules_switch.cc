$NetBSD: patch-modules_switch.cc,v 1.1 2013/06/14 20:29:38 dholland Exp $

Get rid of unused default argument that clang doesn't like.

--- modules/switch.cc~	2010-06-05 06:46:31.000000000 +0000
+++ modules/switch.cc
@@ -582,7 +582,7 @@ void SwitchAttribute::get(char *return_s
 
   //========================================================================
 
-  Switch::Switch(const char *_new_name=0)
+  Switch::Switch(const char *_new_name)
     : SwitchBase(_new_name, "\
 Two port switch\n\
  Attributes:\n\
