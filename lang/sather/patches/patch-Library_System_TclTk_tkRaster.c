$NetBSD: patch-Library_System_TclTk_tkRaster.c,v 1.1 2014/06/28 23:10:39 dholland Exp $

Use standard headers.
Fix build with tcl 8.6.

--- Library/System/TclTk/tkRaster.c.orig	2007-07-01 03:53:35.000000000 +0000
+++ Library/System/TclTk/tkRaster.c
@@ -37,8 +37,21 @@
 #define LOW -32768
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <memory.h>
 #include <ctype.h>
+
+/*
+ * Hack for tcl/tk 8.6: enable access to Tcl_Interp->result.
+ *
+ * As far as I can tell the method this code uses to set the result
+ * (sprintf directly into an existing result pointer of who knows what
+ * size) is insupportable and incorrect, but it should be fixed to
+ * call Tcl_SetResult by someone who knows more about tcl than I do.
+ * XXX.
+ */
+#define USE_INTERP_RESULT
+
 #include <tk.h>
 #include "tkRaster.h"
 #include "tkRasterBuiltIn.h"
@@ -182,15 +195,15 @@ static int PrimitiveCount = 0;	      /* 
  */
 
 static int  ConfigureRaster _ANSI_ARGS_((Tcl_Interp *, Raster *,
-					int argc, char **argv, int flags));
+					int argc, const char **argv, int flags));
 static void DestroyRaster _ANSI_ARGS_((char *clientData));
 static void DisplayRaster _ANSI_ARGS_((ClientData clientData));
 static void RasterEventProc _ANSI_ARGS_((ClientData clientData,
 					 XEvent *eventPtr));
 static int  RasterWidgetCmd _ANSI_ARGS_((ClientData clientData, Tcl_Interp *, 
-					int argc, char **argv));
+					int argc, const char **argv));
 static int  RasterDraw _ANSI_ARGS_((Tcl_Interp*, Raster*, RasterImplement*,
-				   int argc, char ** argv));
+				   int argc, const char ** argv));
 static void arrangeDisplay _ANSI_ARGS_((Raster*, int x0, int y0, 
 					int x1, int y1));
 static void arrangeExpose _ANSI_ARGS_((Raster*, int x0, int y0, 
@@ -198,18 +211,18 @@ static void arrangeExpose _ANSI_ARGS_((R
 void RasterDisplay _ANSI_ARGS_ ((Tk_Raster *));
 
 static int  myOptionParse _ANSI_ARGS_((ClientData, Tcl_Interp *,
-				       Tk_Window, char*, char*, int));
-static char * myOptionPrint _ANSI_ARGS_((ClientData, Tk_Window, char*, 
+				       Tk_Window, const char*, char*, int));
+static const char * myOptionPrint _ANSI_ARGS_((ClientData, Tk_Window, char*, 
 					 int, Tcl_FreeProc ** ));
 
 static int ConfigDrawEnv _ANSI_ARGS_((Tcl_Interp*, Raster*, DrawEnvironment*,
-				      int argc, char * argv []));
+				      int argc, const char ** argv ));
 static int ConfigInfoDrawEnv _ANSI_ARGS_((Tcl_Interp*, Raster*, 
 					  DrawEnvironment*,
-					  int argc, char * argv []));
+					  int argc, const char ** argv ));
 
 static int CreateDrawEnv _ANSI_ARGS_((Tcl_Interp *, Raster*,
-				      int argc,  char* argv []));
+				      int argc,  const char ** argv));
 static void DestroyDrawEnv _ANSI_ARGS_((Raster*, DrawEnvironment*));
 
 /*
@@ -380,7 +393,7 @@ RasterCmd(clientData, interp, argc, argv
 				 * interpreter. */
     Tcl_Interp *interp;		/* Current interpreter. */
     int argc;			/* Number of arguments. */
-    char **argv;		/* Argument strings. */
+    const char **argv;		/* Argument strings. */
 {
     Tk_Window main = (Tk_Window) clientData;
     Raster *RasterPtr;
@@ -448,7 +461,7 @@ RasterCmd(clientData, interp, argc, argv
 
     /* A new drawing environment numbered "0" must be created
        and installed with the following command */
-    if (CreateDrawEnv (interp, RasterPtr, 0, (char**) NULL) != TCL_OK ||
+    if (CreateDrawEnv (interp, RasterPtr, 0, (const char**) NULL) != TCL_OK ||
 	DrawEnvIndex (interp, RasterPtr, 0, &newenv) != TCL_OK) {       
        return TCL_ERROR;
     }
@@ -552,7 +565,7 @@ RasterWidgetCmd(clientData, interp, argc
     ClientData clientData;		/* Information about Raster widget. */
     Tcl_Interp *interp;			/* Current interpreter. */
     int argc;				/* Number of arguments. */
-    char **argv;			/* Argument strings. */
+    const char **argv;			/* Argument strings. */
 {
     Raster *RasterPtr = (Raster *) clientData;
     int result = TCL_OK;
@@ -823,7 +836,7 @@ RasterDraw (interp, RasterPtr, implemPtr
      Raster* RasterPtr;
      RasterImplement* implemPtr;
      int argc;
-     char ** argv;
+     const char ** argv;
 {
    RasterPtr->px0 = HIGH;
    RasterPtr->py0 = HIGH;
@@ -905,7 +918,7 @@ ConfigureRaster(interp, RasterPtr, argc,
     Tcl_Interp *interp;			/* Used for error reporting. */
     Raster *RasterPtr;			/* Information about widget. */
     int argc;				/* Number of valid entries in argv. */
-    char **argv;			/* Arguments. */
+    const char **argv;			/* Arguments. */
     int flags;				/* Flags to pass to
 					 * Tk_ConfigureWidget. */
 {
@@ -1507,7 +1520,7 @@ static int ConfigDrawEnv (interp, Raster
      Raster* RasterPtr;
      DrawEnvironment* drawEnv;     
      int argc;
-     char * argv [];
+     const char ** argv;
 {
    if (Tk_ConfigureWidget(interp, RasterPtr->tkwin, DrawEnvSpecs,
 	argc, argv, (char *) drawEnv, TK_CONFIG_ARGV_ONLY) != TCL_OK) {
@@ -1572,7 +1585,7 @@ static int ConfigInfoDrawEnv (interp, Ra
      Raster* RasterPtr;
      DrawEnvironment* drawEnv;     
      int argc;
-     char * argv [];
+     const char ** argv;
 {
    if (argc == 0) {
       return Tk_ConfigureInfo (interp, RasterPtr->tkwin,
@@ -1660,7 +1673,7 @@ static int CreateDrawEnv (interp, Raster
      Tcl_Interp * interp;
      Raster* RasterPtr;
      int argc;
-     char* argv [];
+     const char **argv;
 {
    Tcl_HashEntry *entryPtr;
    DrawEnvironment *drawEnvPtr;
@@ -1733,7 +1746,7 @@ myOptionParse (clientData, interp, tkwin
      ClientData clientData;
      Tcl_Interp * interp;
      Tk_Window tkwin;
-     char* value;
+     const char *value;
      char* widgRec;
      int offset;
 {
@@ -1762,7 +1775,7 @@ myOptionParse (clientData, interp, tkwin
    return TCL_ERROR;
 }
 
-static char * 
+static const char * 
 myOptionPrint (clientData, tkwin, widgRec, offset, freeProcPtr)
      ClientData clientData;
      Tk_Window tkwin;
@@ -1776,7 +1789,7 @@ myOptionPrint (clientData, tkwin, widgRe
       if (ptr->optionvalue == value) return ptr->optionname;
       ptr++;
    }
-   return (char*) NULL;
+   return (const char*) NULL;
 }
 
 /*======================================================================
@@ -2175,7 +2188,7 @@ void RasterFillPolygon (raster, coord, n
 int
 CreateDrawEnviron(Tcl_Interp *interp, 
 		  Tk_Raster *RasterPtr, 
-		  int argc, char **argv)
+		  int argc, const char **argv)
 {
     int result;
 
