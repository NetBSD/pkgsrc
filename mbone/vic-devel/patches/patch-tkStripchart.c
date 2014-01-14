$NetBSD: patch-tkStripchart.c,v 1.1 2014/01/14 17:07:37 prlw1 Exp $

--- tkStripchart.c.orig	2008-12-10 19:24:48.000000000 +0000
+++ tkStripchart.c
@@ -334,17 +334,17 @@ static Tk_ConfigSpec configSpecs[] =
 static void Callback(Stripchart* StripchartPtr);
 static void ComputeStripchartGeometry(Stripchart* StripchartPtr); //SV-XXX: FreeBSD
 static int ConfigureStripchart(Tcl_Interp* interp, Stripchart* StripchartPtr,
-				int argc, char** argv, int flags); //SV-XXX: FreeBSD
+				int argc, CONST84 char* argv[], int flags); //SV-XXX: FreeBSD
 static void DestroyStripchart(char* clientData);
 static void DisplayStripchart(ClientData clientData);
 static void DrawStripi(Stripchart* StripchartPtr, int i);
 static void EventuallyRedrawStripchart(Stripchart* StripchartPtr,
 				       int displaybits);
-static void ReplaceColours(Stripchart* StripchartPtr, int argc, char** argv); //SV-XXX: FreeBSD
+static void ReplaceColours(Stripchart* StripchartPtr, int argc, CONST84 char* argv[]); //SV-XXX: FreeBSD
 static void ScrollStrips(Stripchart* StripchartPtr);
 static void StripchartEventProc(ClientData clientData, XEvent* eventPtr);
 static int StripchartWidgetCmd(ClientData clientData, Tcl_Interp* interp,
-				int argc, char** argv); //SV-XXX: FreeBSD
+				int argc, CONST84 char* argv[]); //SV-XXX: FreeBSD
 static void SetStripchartValue(Stripchart* StripchartPtr, double value);
 static void SwapColours(Stripchart* StripchartPtr);
 
@@ -370,8 +370,9 @@ int
 Tk_StripchartCmd(ClientData clientData, Tcl_Interp *interp, int argc,
 		 char **argv)
 #else
+int
 Tk_StripchartCmd(ClientData clientData, Tcl_Interp *interp, int argc,
-		 const char **argv)
+		 CONST84 char *argv[])
 #endif
  {
 	Tk_Window tkwin = (Tk_Window) clientData;
@@ -427,7 +428,7 @@ Tk_StripchartCmd(ClientData clientData, 
  */
 static int
 StripchartWidgetCmd(ClientData clientData, Tcl_Interp *interp,
-		    int argc, char **argv) //SV-XXX: FreeBSD
+		    int argc, CONST84 char *argv[]) //SV-XXX: FreeBSD
 {
 	register Stripchart *StripchartPtr = (Stripchart*)clientData;
 	int result = TCL_OK;
@@ -637,7 +638,7 @@ DestroyStripchart(char* clientData)
  */
 static int
 ConfigureStripchart(Tcl_Interp *interp, Stripchart *StripchartPtr,
-		    int argc, char** argv, int flags) //SV-XXX: FreeBSD
+		    int argc, CONST84 char* argv[], int flags) //SV-XXX: FreeBSD
 {
 	XGCValues gcValues;
 	GC newGC;
@@ -1048,7 +1049,7 @@ SwapColours(Stripchart * StripchartPtr)
  *     Stripchart is displayed with the new colour scheme.
  */
 static void 
-ReplaceColours(Stripchart* StripchartPtr, int argc, char** argv) //SV-XXX: FreeBSD
+ReplaceColours(Stripchart* StripchartPtr, int argc, CONST84 char* argv[]) //SV-XXX: FreeBSD
 {
 	StripchartPtr->altborder =
 		Tk_Get3DBorder(StripchartPtr->interp, StripchartPtr->tkwin,
