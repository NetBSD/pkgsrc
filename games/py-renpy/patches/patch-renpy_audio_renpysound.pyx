$NetBSD: patch-renpy_audio_renpysound.pyx,v 1.1 2023/11/23 15:41:21 ryoon Exp $

--- renpy/audio/renpysound.pyx.orig	2023-11-21 07:42:22.846064601 +0000
+++ renpy/audio/renpysound.pyx
@@ -444,7 +444,7 @@ def set_generate_audio_c_function(fn):
         import ctypes
         fn = ctypes.cast(fn, ctypes.c_void_p).value
 
-    RPS_generate_audio_c_function = <void (*)(float *, int)> <uintptr_t> fn
+    RPS_generate_audio_c_function = <void (*)(float *, int) noexcept> <uintptr_t> fn
 
 # Store the sample surfaces so they stay alive.
 rgb_surface = None
