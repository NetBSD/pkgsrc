$NetBSD: patch-src_output_output__surface.cpp,v 1.2 2022/12/24 15:23:42 wiz Exp $

Match #ifdef with the one for the code definition.

--- src/output/output_surface.cpp.orig	2022-09-01 22:55:29.000000000 +0000
+++ src/output/output_surface.cpp
@@ -24,8 +24,10 @@ void OUTPUT_SURFACE_Initialize()
     // blitting the wrong dimensions to the window and trigger an X11 BadValue error.
     // Set up an error handler that prints the error to STDERR and then returns,
     // instead of the default handler which prints an error and exit()s this program.
+#ifdef LINUX
     X11_ErrorHandlerInstall();
 #endif
+#endif
 }
 
 void OUTPUT_SURFACE_Select()
