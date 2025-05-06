$NetBSD: patch-whiptcl.c,v 1.1 2025/05/06 20:35:02 vins Exp $

Use Tcl_* functions to fix compiler warnings. 

--- whiptcl.c.orig	2025-03-10 13:29:06.000000000 +0000
+++ whiptcl.c
@@ -138,45 +138,44 @@ static int wtCmd(ClientData clientData, 
     
     if (arg < -1) {
 	/* this could buffer oveflow, bug we're not setuid so I don't care */
-	interp->result = malloc(200);
-	interp->freeProc = TCL_DYNAMIC;
-	sprintf(interp->result, "%s: %s\n", 
+        char *result = Tcl_Alloc(200);
+	sprintf(result, "%s: %s\n", 
 		poptBadOption(optCon, POPT_BADOPTION_NOALIAS), 
 		poptStrerror(arg));
-
+        Tcl_SetResult(interp, result, TCL_DYNAMIC);
 	return TCL_ERROR;
     }
 
     if (mode == MODE_NONE) {
-	interp->result = "no dialog mode was specified";
+        Tcl_SetResult(interp, "no dialog mode was specified", TCL_STATIC);
 	return TCL_ERROR;
     } else if (rc) {
-	interp->result = "multiple modes were specified";
+	Tcl_SetResult(interp, "multiple modes were specified", TCL_STATIC);
 	return TCL_ERROR;
     }
 
     if (!(text = poptGetArg(optCon))) {
-	interp->result = "missing text parameter";
+	Tcl_SetResult(interp, "missing text parameter", TCL_STATIC);
 	return TCL_ERROR;
     }
 
     if (!(nextArg = poptGetArg(optCon))) {
-	interp->result = "height missing";
+	Tcl_SetResult(interp,"height missing", TCL_STATIC);
 	return TCL_ERROR;
     }
     height = strtoul(nextArg, &end, 10);
     if (*end) {
-	interp->result = "height is not a number";
+	Tcl_SetResult(interp,"height is not a number", TCL_STATIC);
 	return TCL_ERROR;
     }
 
     if (!(nextArg = poptGetArg(optCon))) {
-	interp->result = "width missing";
+	Tcl_SetResult(interp, "width missing", TCL_STATIC);
 	return TCL_ERROR;
     }
     width = strtoul(nextArg, &end, 10);
     if (*end) {
-	interp->result = "width is not a number";
+	Tcl_SetResult(interp, "width is not a number", TCL_STATIC);
 	return TCL_ERROR;
     }
 
@@ -185,12 +184,12 @@ static int wtCmd(ClientData clientData, 
       case MODE_RADIOLIST:
       case MODE_CHECKLIST:
 	if (!(nextArg = poptGetArg(optCon))) {
-	    interp->result = "list-height missing";
+            Tcl_SetResult(interp, "list-height missing",TCL_STATIC);
 	    return TCL_ERROR;
 	}
 	listHeight = strtoul(nextArg, &end, 10);
 	if (*end) {
-	    interp->result = "list-height is not a number";
+            Tcl_SetResult(interp, "list-height is not a number",TCL_STATIC);
 	    return TCL_ERROR;
 	}
 	break;
@@ -212,18 +211,14 @@ static int wtCmd(ClientData clientData, 
 
       case MODE_YESNO:
 	rc = messageBox(text, height, width, MSGBOX_YESNO, flags);
-	if (rc == DLG_OKAY)
-	    interp->result = "yes";
-	else 
-	    interp->result = "no";
+        Tcl_SetResult( interp, rc == DLG_OKAY ? "yes " : "no" , TCL_STATIC);
 	if (rc == DLG_ERROR) rc = 0;
 	break;
 
       case MODE_INPUTBOX:
 	rc = inputBox(text, height, width, optCon, flags, &result);
 	if (rc ==DLG_OKAY) {
-	    interp->result = result;
-	    interp->freeProc = TCL_DYNAMIC;
+            Tcl_SetResult(interp, result, TCL_DYNAMIC);
 	}
 	break;
 
@@ -231,8 +226,7 @@ static int wtCmd(ClientData clientData, 
 	rc = listBox(text, height, width, listHeight, optCon, flags, default_item,
 		     &result);
 	if (rc==DLG_OKAY) {
-	    interp->result = result;
-	    interp->freeProc = TCL_DYNAMIC;
+            Tcl_SetResult(interp, result, TCL_DYNAMIC);
 	}
 	break;
 
@@ -240,9 +234,7 @@ static int wtCmd(ClientData clientData, 
 	rc = checkList(text, height, width, listHeight, optCon, 1, flags,
 		       &selections);
 	if (rc==DLG_OKAY) {
-	    interp->result = selections[0];
-	    interp->freeProc = TCL_DYNAMIC;
-
+	    Tcl_SetResult( interp, selections[0], TCL_DYNAMIC);
 	    free(selections);
 	}
 	break;
@@ -267,7 +259,7 @@ static int wtCmd(ClientData clientData, 
     newtPopWindow();
 
     if (rc == DLG_ERROR) {
-	interp->result = "bad paramter for whiptcl dialog box";
+        Tcl_SetResult(interp, "bad paramter for whiptcl dialog box", TCL_STATIC);
 	return TCL_ERROR;
     } 
 
