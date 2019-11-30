$NetBSD: patch-alc_backends_alsa.cpp,v 1.1 2019/11/30 13:40:29 nia Exp $

Support building on non-Linux.

--- alc/backends/alsa.cpp.orig	2019-11-28 08:45:08.000000000 +0000
+++ alc/backends/alsa.cpp
@@ -53,6 +53,9 @@
 
 #include <alsa/asoundlib.h>
 
+#ifndef ESTRPIPE
+#define ESTRPIPE EPIPE
+#endif
 
 namespace {
 
