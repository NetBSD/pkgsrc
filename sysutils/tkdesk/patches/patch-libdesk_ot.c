$NetBSD: patch-libdesk_ot.c,v 1.1 2022/06/06 05:11:58 dholland Exp $

Update interpreter result handling for Tcl 8.6 (?)

Also, memory allocated from inside tcl needs to be freed with Tcl_Free.

--- libdesk/ot.c.orig	2004-04-14 02:34:37.000000000 +0000
+++ libdesk/ot.c
@@ -150,7 +150,8 @@ char *argv[];
     char **largv;
 
     if (argc < 3) {
-	interp->result = "usage: ot_maplist list var ?var ...?";
+	Tcl_SetResult(interp, "usage: ot_maplist list var ?var ...?",
+		      TCL_STATIC);
 	return TCL_ERROR;
     }
 
@@ -160,7 +161,7 @@ char *argv[];
 
     for (i = 0; i < largc; i++) {
 	if (!Tcl_SetVar (interp, argv[i + 2], largv[i], TCL_LEAVE_ERR_MSG)) {
-	    free (largv);
+	    Tcl_Free (largv);
 	    return TCL_ERROR;
 	}
 
@@ -169,7 +170,7 @@ char *argv[];
 	    for (j = i + 1; j < largc; j++) {
 		if (!Tcl_SetVar (interp, argv[i + 2], largv[j],
 		       TCL_LEAVE_ERR_MSG|TCL_LIST_ELEMENT|TCL_APPEND_VALUE)) {
-		    free (largv);
+		    Tcl_Free (largv);
 		    return TCL_ERROR;
 		}
 	    }
@@ -177,7 +178,7 @@ char *argv[];
 	}
     }
 
-    free (largv);
+    Tcl_Free (largv);
     return TCL_OK;
 } /* ot_maplist_Cmd */
 
@@ -204,7 +205,9 @@ char *argv[];
     int x, y;
     
     if (argc != 2 && argc != 3) {
-	interp->result = "usage: ot_warp_pointer window / ot_warp_pointer x y";
+	Tcl_SetResult(interp,
+		      "usage: ot_warp_pointer window / ot_warp_pointer x y",
+		      TCL_STATIC);
 	return TCL_ERROR;
     }
 
@@ -262,14 +265,16 @@ char *cmd;
     }
 
     if (Tcl_GetCommandInfo (interp, argv[0], &cmdInfo) == 0) {
-        sprintf (interp->result, "invalid command name \"%s\"", argv[0]);
-	free (argv);
+	char buf[1024];
+	snprintf(buf, sizeof(buf), "invalid command name \"%s\"", argv[0]);
+	Tcl_SetResult(interp, buf, TCL_VOLATILE);
+	Tcl_Free (argv);
         return TCL_ERROR;
     }
 
     Tcl_ResetResult (interp);
     retval = (*cmdInfo.proc) (cmdInfo.clientData, interp, argc, argv);
-    free (argv);
+    Tcl_Free (argv);
     return retval;
 } /* Ot_TclInvoke */
 
