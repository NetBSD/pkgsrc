$NetBSD: patch-src_dialogueloader.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/dialogueloader.cpp.orig	2005-01-21 08:02:52.000000000 +0000
+++ src/dialogueloader.cpp
@@ -7,6 +7,7 @@
 #include "debug.h"
 #include "conversation.h"
 #include "dialogueloader.h"
+#include <stdlib.h>
 
 std::map<std::string, DialogueLoader *> *DialogueLoader::loaderMap = NULL;
 
