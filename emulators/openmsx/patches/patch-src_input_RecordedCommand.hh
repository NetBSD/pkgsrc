$NetBSD: patch-src_input_RecordedCommand.hh,v 1.1 2011/11/24 14:12:21 joerg Exp $

--- src/input/RecordedCommand.hh.orig	2011-11-24 02:44:43.000000000 +0000
+++ src/input/RecordedCommand.hh
@@ -6,6 +6,8 @@
 #include "Command.hh"
 #include "MSXEventListener.hh"
 
+#include <memory>
+
 namespace openmsx {
 
 class MSXCommandController;
