$NetBSD: patch-src_dialogueloader__tlk.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Add missing header.

--- src/dialogueloader_tlk.cpp.orig	2005-01-21 08:02:52.000000000 +0000
+++ src/dialogueloader_tlk.cpp
@@ -7,6 +7,7 @@
 #include "conversation.h"
 #include "dialogueloader_tlk.h"
 #include "u4file.h"
+#include <string.h>
 
 DialogueLoader* U4TlkDialogueLoader::instance = DialogueLoader::registerLoader(new U4TlkDialogueLoader, "application/x-u4tlk");
 
