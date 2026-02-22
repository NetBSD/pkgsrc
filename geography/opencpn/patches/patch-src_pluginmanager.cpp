$NetBSD: patch-src_pluginmanager.cpp,v 1.1 2026/02/22 22:23:16 bouyer Exp $

Avoid conflicting definitions between elf.h and libelf.h

--- src/pluginmanager.cpp.orig	2026-02-22 15:39:46.203344963 +0100
+++ src/pluginmanager.cpp	2026-02-22 15:40:14.895800822 +0100
@@ -44,7 +44,9 @@
 #include <errno.h>
 
 #ifdef USE_LIBELF
+#ifndef __NetBSD__
 #include <elf.h>
+#endif
 #include <libelf.h>
 #include <gelf.h>
 #endif
