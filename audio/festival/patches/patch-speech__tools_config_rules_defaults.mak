$NetBSD: patch-speech__tools_config_rules_defaults.mak,v 1.1 2019/11/11 19:28:04 nia Exp $

Use LDFLAGS.

--- speech_tools/config/rules/defaults.mak.orig	2017-09-04 15:54:03.000000000 +0000
+++ speech_tools/config/rules/defaults.mak
@@ -196,6 +196,6 @@ endif
 ## Link a program (not including libraries)
 
 ifndef LINK_COMMAND
-    LINK_COMMAND = $(CXX) $(LINKFLAGS) $(TEMPLATES) 
+    LINK_COMMAND = $(CXX) $(LDFLAGS) $(LINKFLAGS) $(TEMPLATES) 
 endif
 
