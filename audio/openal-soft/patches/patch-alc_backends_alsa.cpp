$NetBSD: patch-alc_backends_alsa.cpp,v 1.2 2026/05/19 05:18:45 adam Exp $

Support building on non-Linux.

--- alc/backends/alsa.cpp.orig	2026-05-12 02:21:07.000000000 +0000
+++ alc/backends/alsa.cpp
@@ -54,6 +54,9 @@ import logging;
 #include "core/logging.h"
 #endif
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
 
 namespace {
 
