$NetBSD: patch-src_megacmdshell_megacmdshellcommunications.cpp,v 1.2 2025/02/15 07:40:14 wiz Exp $

* Fix include on BSDs

--- src/megacmdshell/megacmdshellcommunications.cpp.orig	2024-05-20 12:29:43.000000000 +0000
+++ src/megacmdshell/megacmdshellcommunications.cpp
@@ -55,7 +55,7 @@
 #include <limits.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <netinet/in.h>
 #endif
 
