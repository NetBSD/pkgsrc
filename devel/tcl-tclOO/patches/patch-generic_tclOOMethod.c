$NetBSD: patch-generic_tclOOMethod.c,v 1.1 2014/06/28 22:02:50 dholland Exp $

Fix build with tcl 8.6.

--- generic/tclOOMethod.c~	2013-08-03 11:31:43.000000000 +0000
+++ generic/tclOOMethod.c
@@ -34,7 +34,7 @@ struct PNI {
 typedef struct {
     CallFrame *framePtr;	/* Reference to the call frame itself (it's
 				 * actually allocated on the Tcl stack). */
-    ProcErrorProc errProc;	/* The error handler for the body. */
+    ProcErrorProc *errProc;	/* The error handler for the body. */
     Tcl_Obj *nameObj;		/* The "name" of the command. */
     Command cmd;		/* The command structure. Mostly bogus. */
     ExtraFrameInfo efi;		/* Extra information used for [info frame]. */
@@ -508,8 +508,8 @@ TclOOMakeProcInstanceMethod(
 		cfPtr->data.eval.path = context.data.eval.path;
 		Tcl_IncrRefCount(cfPtr->data.eval.path);
 
-		cfPtr->cmd.str.cmd = NULL;
-		cfPtr->cmd.str.len = 0;
+		cfPtr->cmd = NULL;
+		cfPtr->len = 0;
 
 		hPtr = Tcl_CreateHashEntry(iPtr->linePBodyPtr,
 			(char *) procPtr, &isNew);
@@ -621,8 +621,8 @@ TclOOMakeProcMethod(
 		cfPtr->data.eval.path = context.data.eval.path;
 		Tcl_IncrRefCount(cfPtr->data.eval.path);
 
-		cfPtr->cmd.str.cmd = NULL;
-		cfPtr->cmd.str.len = 0;
+		cfPtr->cmd = NULL;
+		cfPtr->len = 0;
 
 		hPtr = Tcl_CreateHashEntry(iPtr->linePBodyPtr,
 			(char *) procPtr, &isNew);
@@ -756,7 +756,7 @@ PushMethodCallFrame(
     register int result;
     const char *namePtr;
     CallFrame **framePtrPtr = &fdPtr->framePtr;
-    static Tcl_ObjType *byteCodeTypePtr = NULL;	/* HACK! */
+    static const Tcl_ObjType *byteCodeTypePtr = NULL;	/* HACK! */
 
     /*
      * Compute basic information on the basis of the type of method it is.
@@ -1168,7 +1168,7 @@ MethodErrorHandler(
     Tcl_AppendObjToErrorInfo(interp, Tcl_ObjPrintf(
 	    "\n    (%s \"%.*s%s\" method \"%.*s%s\" line %d)",
 	    kindName, ELLIPSIFY(objectName, objectNameLen),
-	    ELLIPSIFY(methodName, nameLen), interp->errorLine));
+	    ELLIPSIFY(methodName, nameLen), Tcl_GetErrorLine(interp)));
 }
 
 static void
@@ -1197,7 +1197,7 @@ ConstructorErrorHandler(
 	    &objectNameLen);
     Tcl_AppendObjToErrorInfo(interp, Tcl_ObjPrintf(
 	    "\n    (%s \"%.*s%s\" constructor line %d)", kindName,
-	    ELLIPSIFY(objectName, objectNameLen), interp->errorLine));
+	    ELLIPSIFY(objectName, objectNameLen), Tcl_GetErrorLine(interp)));
 }
 
 static void
@@ -1226,7 +1226,7 @@ DestructorErrorHandler(
 	    &objectNameLen);
     Tcl_AppendObjToErrorInfo(interp, Tcl_ObjPrintf(
 	    "\n    (%s \"%.*s%s\" destructor line %d)", kindName,
-	    ELLIPSIFY(objectName, objectNameLen), interp->errorLine));
+	    ELLIPSIFY(objectName, objectNameLen), Tcl_GetErrorLine(interp)));
 }
 
 /*
