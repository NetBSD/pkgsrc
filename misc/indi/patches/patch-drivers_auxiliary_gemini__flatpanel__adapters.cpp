$NetBSD: patch-drivers_auxiliary_gemini__flatpanel__adapters.cpp,v 1.1 2025/10/08 15:20:16 adam Exp $

Fix build.

--- drivers/auxiliary/gemini_flatpanel_adapters.cpp.orig	2025-10-08 15:16:11.907088749 +0000
+++ drivers/auxiliary/gemini_flatpanel_adapters.cpp
@@ -4,6 +4,7 @@
 #include <termios.h>
 #include <cstring>
 #include <cstdio>
+#include <cstdlib>
 
 //////////////////////////////////////////////////////////////////////////////
 // GeminiFlatpanelRev1Adapter Implementation
