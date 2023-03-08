$NetBSD: patch-files.c,v 1.2 2023/03/08 21:46:44 vins Exp $

Pull patches from Debian.

--- files.c.orig	1994-05-19 02:01:06.000000000 +0000
+++ files.c
@@ -1,9 +1,10 @@
-#ifndef lint
-static char rcsid[] = "files.c,v 2.0 1994/05/19 02:01:06 dan Exp";
+#if 0
+static char rcsid[] __attribute__((unused)) = "files.c,v 2.0 1994/05/19 02:01:06 dan Exp";
 #endif
 
 /*
  * Copyright (c) 1994    Daniel Williams
+ * Copyright (c) 2003    Erik de Castro Lopo
  * 
  * The X Consortium, and any party obtaining a copy of these files from
  * the X Consortium, directly or indirectly, is granted, free of charge,
@@ -36,6 +37,7 @@ static char rcsid[] = "files.c,v 2.0 199
 #include <unistd.h>
 #include <errno.h>
 #include <sys/stat.h>
+#include <sys/types.h>
 #include <ctype.h>
 #include <assert.h>
 
@@ -83,16 +85,18 @@ static void popup_cb (Widget w, XtPointe
  */
 static int is_ascii_text (char *filename)
 {
-    int fd, bytes, i;
+    int fd, bytes, i, ch;
     char buffer[1024];
 
     fd = open (filename, O_RDONLY);
     bytes = read (fd, (void *) buffer, 1024);
     (void) close (fd);
 
-    for (i = 0; i < bytes; i++)
-	if (!isascii (buffer[i]))
+    for (i = 0; i < bytes; i++) {
+	ch = buffer [i];
+	if (!isallowed(ch))
 	    return (0);
+    }
     return (1);
 }
 
@@ -143,12 +147,13 @@ void werror (Widget parent, char *title,
     XmString xms;
     Arg args[2];
 
-    (void) sprintf (buffer, "%s: %s", msg1, msg2);
+    (void) snprintf (buffer, sizeof (buffer), "%s: %s", msg1, msg2);
     xms = XmStringCreateLtoR (buffer, XmSTRING_DEFAULT_CHARSET);
     XtSetArg (args[0], XmNmessageString, xms);
     XtSetArg (args[1], XmNdialogStyle, XmDIALOG_PRIMARY_APPLICATION_MODAL);
     dialog = XmCreateErrorDialog (parent, "werror", args, 2);
-    XmStringFree (xms);
+    if (xms)
+	XmStringFree (xms);
     XtVaSetValues (XtParent (dialog), XtNtitle, title, NULL);
 
     XtUnmanageChild (XmMessageBoxGetChild (dialog, XmDIALOG_CANCEL_BUTTON));
@@ -174,8 +179,10 @@ void werror_long (Widget parent, char *t
 	    xms1 = xms4;
 	else {
 	    xms2 = XmStringConcat (xms1, xms4);
-	    XmStringFree (xms4);
-	    XmStringFree (xms1);
+	    if (xms4)
+		XmStringFree (xms4);
+	    if (xms1)
+		XmStringFree (xms1);
 	    xms1 = xms2;
 	}
 
@@ -183,16 +190,19 @@ void werror_long (Widget parent, char *t
 	    XmString xms3;
 
 	    xms3 = XmStringConcat (xms1, sep);
-	    XmStringFree (xms1);
+	    if (xms1)
+		XmStringFree (xms1);
 	    xms1 = xms3;
 	}
     }
-    XmStringFree (sep);
+    if (sep)
+	XmStringFree (sep);
     
     XtSetArg (args[0], XmNmessageString, xms1);
     XtSetArg (args[1], XmNdialogStyle, XmDIALOG_PRIMARY_APPLICATION_MODAL);
     dialog = XmCreateErrorDialog (parent, "werror", args, 2);
-    XmStringFree (xms1);
+    if (xms1)
+	XmStringFree (xms1);
     XtVaSetValues (XtParent (dialog), XtNtitle, title, NULL);
     XtUnmanageChild (XmMessageBoxGetChild (dialog, XmDIALOG_CANCEL_BUTTON));
     XtUnmanageChild (XmMessageBoxGetChild (dialog, XmDIALOG_HELP_BUTTON));
@@ -318,7 +328,7 @@ void open_both_files (Widget parent, cha
     Arg args[2];
     int i;
     char *dir;
-    XmString xms;
+    XmString xms = (XmString)0;
 
     shell = XtVaCreatePopupShell ("openfiles", xmDialogShellWidgetClass, parent,
 				  XmNallowShellResize, True,
@@ -349,7 +359,8 @@ void open_both_files (Widget parent, cha
     fsb1 = XmCreateFileSelectionBox (frame1a, "files1", args, i);
     if (dir) {
 	XtFree (dir);
-	XmStringFree (xms);
+	if (xms)
+	    XmStringFree (xms);
     }
 
     i = 0;
@@ -360,7 +371,8 @@ void open_both_files (Widget parent, cha
     fsb2 = XmCreateFileSelectionBox (frame2a, "files2", args, i);
     if (dir) {
 	XtFree (dir);
-	XmStringFree (xms);
+	if (xms)
+	    XmStringFree (xms);
     }
 
     XtAddCallback (fsb1, XmNokCallback, filel_both_cb, shell);
@@ -424,7 +436,7 @@ void open_left_file (Widget parent, char
     Arg args[2];
     int i;
     char *dir;
-    XmString xms;
+    XmString xms = (XmString)0;
 
     i = 0;
     XtSetArg (args[i], XmNdeleteResponse, XmDO_NOTHING); i++;
@@ -435,7 +447,8 @@ void open_left_file (Widget parent, char
     dialog = XmCreateFileSelectionDialog (parent, "openfile", args, i);
     if (dir) {
 	XtFree (dir);
-	XmStringFree (xms);
+	if (xms)
+	    XmStringFree (xms);
     }
     XtAddCallback (XtParent (dialog), XmNpopupCallback, popup_cb, parent);
     XtAddCallback (dialog, XmNokCallback, file_left_cb, dialog);
@@ -477,7 +490,7 @@ void open_right_file (Widget parent, cha
     Arg args[2];
     int i;
     char *dir;
-    XmString xms;
+    XmString xms = (XmString)0;
 
     i = 0;
     XtSetArg (args[i], XmNdeleteResponse, XmDO_NOTHING); i++;
@@ -488,7 +501,8 @@ void open_right_file (Widget parent, cha
     dialog = XmCreateFileSelectionDialog (parent, "openfile", args, XtNumber (args));
     if (dir) {
 	XtFree (dir);
-	XmStringFree (xms);
+	if (xms)
+	    XmStringFree (xms);
     }
 
     XtAddCallback (XtParent (dialog), XmNpopupCallback, popup_cb, parent);
@@ -533,7 +547,7 @@ static void file_save_cb (Widget w, XtPo
     if (access (filename, W_OK) == 0) {	/* file exists and can be written */
 	char buffer[1024];
 
-	(void) sprintf (buffer, "Overwrite \"%s\"?", filename);
+	(void) snprintf (buffer, sizeof (buffer), "Overwrite \"%s\"?", filename);
 	if (modal_question (w, "Mgdiff Save Question", buffer)) {
 	    set_cursor (shell);
 	    if ((status = really_save_file (filename, (Block *) closure)) != 0) {
@@ -569,7 +583,7 @@ void save_file (Widget parent, Block *b,
     Arg args[3];
     int i;
     char *dir;
-    XmString xms;
+    XmString xms = (XmString)0;
 
     i = 0;
     XtSetArg (args[i], XmNdialogStyle, XmDIALOG_PRIMARY_APPLICATION_MODAL); i++;
@@ -582,7 +596,8 @@ void save_file (Widget parent, Block *b,
     dialog = XmCreateFileSelectionDialog (parent, "savefile", args, i);
     if (dir) {
 	XtFree (dir);
-	XmStringFree (xms);
+	if (xms)
+	    XmStringFree (xms);
     }
 
     XtAddCallback (XtParent (dialog), XmNpopupCallback, popup_cb, parent);
@@ -618,18 +633,32 @@ static int really_save_file (char *filen
 		return (status);
 	}
 	else if ((b->arr[LEFT].type == DIFF) && (b->arr[RIGHT].type == DIFF)) {
-	    assert (b->selected != NEITHER);
+	    switch (b->selected) {
+		case BOTH:
+		    fprintf (file, "<<<<<<< diff from left file\n");
+		    if ((status = write_chunk (file, &b->arr[LEFT])) != 0)
+			return (status);
+		    fprintf (file, "========\n");
+		    if ((status = write_chunk (file, &b->arr[RIGHT])) != 0)
+			return (status);
+		    fprintf (file, ">>>>>>> diff from right file\n");
+		    break;
+		case LEFT:
+		case RIGHT:
 	    if ((status = write_chunk (file, &b->arr[b->selected])) != 0)
 		return (status);
+		    break;
+		case NEITHER:
+		    break;
+		default : assert (False);
+	    }
 	}
 	else if ((b->arr[LEFT].type == INSERT) && (b->arr[RIGHT].type == BLANK)) {
-	    assert (b->selected != NEITHER);
 	    if (b->selected == LEFT)
 		if ((status = write_chunk (file, &b->arr[LEFT])) != 0)
 		    return (status);
 	}
 	else if ((b->arr[LEFT].type == BLANK) && (b->arr[RIGHT].type == INSERT)) {
-	    assert (b->selected != NEITHER);
 	    if (b->selected == RIGHT)
 		if ((status = write_chunk (file, &b->arr[RIGHT])) != 0)
 		    return (status);
@@ -669,3 +698,45 @@ static int write_chunk (FILE *file, Chun
 
     return (0);
 }
+
+void save_as_filename (Widget parent, Block *closure, char *filename)
+{	
+    char *title = "Mgdiff Save Error";
+    int status;
+    Widget shell = get_top_shell (parent);
+
+    if (access (filename, W_OK) == 0) {
+	/* file exists and can be written */
+	char buffer[1024];
+
+	(void) snprintf (buffer, sizeof (buffer), "Overwrite \"%s\"?", filename);
+	if (modal_question (parent, "Mgdiff Save Question", buffer)) {
+	    set_cursor (shell);
+	    if ((status = really_save_file (filename, (Block *) closure)) != 0) {
+		reset_cursor (shell);
+		werror (parent, title, filename, strerror (status));
+		return;
+	    }
+	    reset_cursor (shell) ;
+	}
+    }
+    else {
+	/* file can't be written to */
+	if (errno == ENOENT) {
+	    /* because it doesn't exist */
+	    set_cursor (shell);
+	    if ((status = really_save_file (filename, (Block *) closure)) != 0) {
+		reset_cursor (shell);
+		werror (parent, title, filename, strerror (status));
+		return;
+	    }
+	    reset_cursor (shell);
+	}
+	else {
+	    /* for some other reason */
+	    werror (parent, title, filename, strerror (errno));
+	    return;
+	}
+    }
+
+} /* save_as_filename */
