$NetBSD: patch-libdesk_misc.c,v 1.1 2022/06/06 05:11:58 dholland Exp $

Update interpreter result handling for Tcl 8.6 (?)
Don't cast result of malloc.

--- libdesk/misc.c.orig	2004-02-29 21:52:24.000000000 +0000
+++ libdesk/misc.c
@@ -79,7 +79,7 @@ int dsk_striptc_Cmd (clientData, interp,
     char instr[TCL_RESULT_SIZE], outstr[TCL_RESULT_SIZE];
     
     if (argc < 2 || argc > 3) {
-	sprintf (interp->result, "usage: dsk_striptc ?-keep? string");
+	Tcl_SetResult(interp, "usage: dsk_striptc ?-keep? string", TCL_STATIC);
 	return (TCL_ERROR);
     }
     if (argc == 3) {
@@ -87,7 +87,8 @@ int dsk_striptc_Cmd (clientData, interp,
             keep = 1;
             strcpy(instr, argv[2]);
         } else {
-            sprintf (interp->result, "usage: dsk_striptc ?-keep? string");
+            Tcl_SetResult(interp, "usage: dsk_striptc ?-keep? string",
+			  TCL_STATIC);
             return (TCL_ERROR);
         }
     } else {
@@ -95,7 +96,7 @@ int dsk_striptc_Cmd (clientData, interp,
     }
 
     if (instr[0] == 0) {
-	*interp->result = 0;
+	Tcl_SetResult(interp, "", TCL_STATIC);
 	return (TCL_OK);
     }
 
@@ -125,7 +126,7 @@ int dsk_striptc_Cmd (clientData, interp,
 	}
     }
 
-    strcpy (interp->result, outstr);
+    Tcl_SetResult(interp, outstr, TCL_VOLATILE);
     return (TCL_OK);
 } /* dsk_striptc_Cmd */
 
@@ -144,12 +145,12 @@ int dsk_esc_Cmd (clientData, interp, arg
     char *buf;
 
     if (argc != 3) {
-	sprintf (interp->result, "usage: dsk_esc string chars");
+	Tcl_SetResult(interp, "usage: dsk_esc string chars", TCL_STATIC);
 	return (TCL_ERROR);
     }
 
     /* assume every char needs to be backslashed, for safety reasons */
-    buf = (char *) malloc (strlen (argv[1]) * 2);
+    buf = malloc (strlen (argv[1]) * 2);
     if (buf == NULL) {
 	fprintf (stderr, "out of memory in dsk_esc_Cmd\n");
 	exit (1);
@@ -176,12 +177,12 @@ int dsk_unesc_Cmd (clientData, interp, a
     char *buf;
 
     if (argc != 2) {
-	strcpy (interp->result, "usage: dsk_unesc string");
+	Tcl_SetResult(interp, "usage: dsk_unesc string", TCL_STATIC);
 	return (TCL_ERROR);
     }
 
     /* assume every char needs to be backslashed, for safety reasons */
-    buf = (char *) malloc (strlen (argv[1]) * 2);
+    buf = malloc (strlen (argv[1]) * 2);
     if (buf == NULL) {
 	fprintf (stderr, "out of memory in dsk_esc_Cmd\n");
 	exit (1);
@@ -259,7 +260,7 @@ int dsk_statfs_Cmd (clientData, interp, 
     char buf[64];
     
     if (argc != 2) {
-	strcpy (interp->result, "usage: dskC_statfs path?/file?");
+	Tcl_SetResult(interp, "usage: dskC_statfs path?/file?", TCL_STATIC);
 	return TCL_ERROR;
     }
 
@@ -295,13 +296,14 @@ int dsk_statfs_Cmd (clientData, interp, 
 	return TCL_OK;
 	
     } else {
-	sprintf (interp->result, "Error %d", errno);
+	snprintf(buf, sizeof(buf), "Error %d", errno);
+	Tcl_SetResult(interp, buf, TCL_VOLATILE);
 	return TCL_ERROR;
     }
     
 #else
     
-    strcpy (interp->result, "");
+    Tcl_SetResult(interp, "", TCL_STATIC);
     return TCL_OK;
     
 #endif    
