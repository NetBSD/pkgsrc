$NetBSD: patch-libdesk_o__FileListbox.c,v 1.1 2022/06/06 05:11:58 dholland Exp $

Update interpreter result handling for Tcl 8.6 (?)

Also, memory allocated from inside tcl needs to be freed with Tcl_Free.

--- libdesk/o_FileListbox.c.orig	2004-02-29 21:52:24.000000000 +0000
+++ libdesk/o_FileListbox.c
@@ -69,7 +69,7 @@ int dsk_init_ftags_Cmd (clientData, inte
 
     /* get and split the taglist */
     if (targv != NULL)
-	free ((char *)targv);
+	Tcl_Free ((char *)targv);
     if (argc > 1) {
 	if (Tcl_SplitList (interp, argv[1], &targc, &targv) == TCL_ERROR)
 	    return TCL_ERROR;
@@ -81,7 +81,7 @@ int dsk_init_ftags_Cmd (clientData, inte
 
     /* get and split tag masks */
     if (pargv != NULL)
-	free ((char *)pargv);
+	Tcl_Free ((char *)pargv);
     if (argc > 2) {
 	if (Tcl_SplitList (interp, argv[2], &pargc, &pargv) == TCL_ERROR)
 	    return TCL_ERROR;
@@ -93,7 +93,7 @@ int dsk_init_ftags_Cmd (clientData, inte
     
     /* get and split ignore masks */
     if (iargv != NULL)
-	free ((char *)iargv);
+	Tcl_Free ((char *)iargv);
     if (argc > 3) {
 	if (Tcl_SplitList (interp, argv[3], &iargc, &iargv) == TCL_ERROR)
 	    return TCL_ERROR;
@@ -139,7 +139,7 @@ int dsk_ls_and_tag_Cmd (clientData, inte
 #endif
 
     if (argc != 2) {
-	strcpy (interp->result, "usage: dskC_ls_and_tag path");
+	Tcl_SetResult(interp, "usage: dskC_ls_and_tag path", TCL_STATIC);
 	return TCL_ERROR;
     }
 
@@ -170,7 +170,7 @@ int dsk_ls_and_tag_Cmd (clientData, inte
     if (Tcl_SplitList (interp, lscmd, &lsargc, &lsargv) == TCL_ERROR)
 	return TCL_ERROR;
     dsk_ls_init_and_parse_options (lsargc, lsargv, argv[1]);
-    free (lsargv);
+    Tcl_Free (lsargv);
     
     /* now read and sort the file list */
     fargc = dsk_ls_read_and_sort (iargc, (showall ? NULL : iargv),
@@ -301,14 +301,14 @@ int dsk_ls_and_tag_Cmd (clientData, inte
     /* free memory allocated by dsk_ls */
     dsk_ls_cleanup();
     if (!mask_matches_all)
-	free (maskv);
+	Tcl_Free (maskv);
 
     /*
      * And now the tagging:
      */
     if (mtags) {
 	ot_invoke ("array names mt");
-	strcpy (buf, interp->result);
+	strcpy (buf, Tcl_GetStringResult(interp));
 	if (Tcl_SplitList (interp, buf, &mtargc, &mtargv) == TCL_ERROR)
 	  return TCL_ERROR;
 
@@ -343,7 +343,7 @@ int dsk_ls_and_tag_Cmd (clientData, inte
 	}
 	Tcl_DStringFree (&dbigcmd);
 
-	free (mtargv);
+	Tcl_Free (mtargv);
     }
     
     if (add_images && notmatch_set) {
