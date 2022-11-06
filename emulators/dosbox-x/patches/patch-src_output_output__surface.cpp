$NetBSD: patch-src_output_output__surface.cpp,v 1.1 2022/11/06 21:31:57 triaxx Exp $

Fix linking error on FreeBSD (from FreeBSD ports).

--- src/output/output_surface.cpp.orig	2022-09-01 22:55:29.000000000 +0000
+++ src/output/output_surface.cpp
@@ -24,7 +24,9 @@ void OUTPUT_SURFACE_Initialize()
     // blitting the wrong dimensions to the window and trigger an X11 BadValue error.
     // Set up an error handler that prints the error to STDERR and then returns,
     // instead of the default handler which prints an error and exit()s this program.
+#if !defined(__FreeBSD__)
     X11_ErrorHandlerInstall();
+#endif
 #endif
 }
 
