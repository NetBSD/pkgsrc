$NetBSD: patch-Library_System_TclTk_tkRaster.h,v 1.1 2014/06/28 23:10:39 dholland Exp $

Fix build with tcl 8.6.

--- Library/System/TclTk/tkRaster.h.orig	2007-07-01 03:53:35.000000000 +0000
+++ Library/System/TclTk/tkRaster.h
@@ -166,7 +166,7 @@ typedef int RasterPrimDrawProc _ANSI_ARG
 					    Tk_Raster * raster,
 					    ClientData data,
 					    int argc, 
-					    char* argv [])); 
+					    const char **argv)); 
 
 typedef int RasterPrimInitProc _ANSI_ARGS_((Tcl_Interp * interp,
 					    Tk_Raster* raster,
@@ -196,7 +196,7 @@ EXTERN int RasterInit _ANSI_ARGS_((Tcl_I
  *
  */
 EXTERN int RasterCmd _ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp, 
-				  int argc,  char **argv));
+				  int argc,  const char **argv));
 
 
 /*---------------------------------------------------------------------------
