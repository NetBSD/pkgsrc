$NetBSD: patch-src_zm__packet.h,v 1.1 2024/12/01 13:49:48 gdt Exp $

Add NetBSD to BSD conditional.

\todo File upstream PR.

--- src/zm_packet.h.orig	2024-01-14 21:29:59.095197872 +0000
+++ src/zm_packet.h
@@ -32,7 +32,7 @@ extern "C" {
 #include <libavformat/avformat.h>
 }
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/time.h>
 #endif // __FreeBSD__
 
