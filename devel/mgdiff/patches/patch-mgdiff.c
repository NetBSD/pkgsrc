$NetBSD: patch-mgdiff.c,v 1.3 2023/03/01 23:48:00 vins Exp $

Prevent unsafe use of tmpnam(). 
Pull patches from Debian.

--- mgdiff.c.orig	1994-09-29 01:56:53.000000000 +0000
+++ mgdiff.c
@@ -1,13 +1,14 @@
-#ifndef lint
-static char rcsid[] = "mgdiff.c,v 2.1 1994/09/29 01:56:53 dan Exp";
+#if 0
+static char rcsid[] __attribute__((unused)) = "mgdiff.c,v 2.1 1994/09/29 01:56:53 dan Exp";
 #endif
 
-#ifndef lint
-static char copyright[] = "Copyright (c) 1994, Daniel Williams";
+#if 0
+static char copyright[] __attribute__((unused)) = "Copyright (c) 1994, Daniel Williams";
 #endif
 
 /*
  * Copyright (c) 1994    Daniel Williams
+ * Copyright (c) 2003    Erik de Castro Lopo
  * 
  * The X Consortium, and any party obtaining a copy of these files from
  * the X Consortium, directly or indirectly, is granted, free of charge,
@@ -33,13 +34,17 @@ static char copyright[] = "Copyright (c)
  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 
+#define _GNU_SOURCE
+
 #include <X11/Xos.h>
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
 #include <errno.h>
+#include <stdint.h>
 #include <sys/stat.h>
+#include <locale.h>
 
 #include <X11/Intrinsic.h>
 #include <X11/StringDefs.h>
@@ -79,7 +84,7 @@ static void update_pixmaps (void);
 static void do_nothing (Widget widget, XEvent *event, String *params, Cardinal *num_params);
 static void add_actions (XtAppContext app);
 static int  x_error_handler (Display *dpy, XErrorEvent *event);
-static void xt_error_handler (String message);
+static void xt_error_handler (String message) __attribute__ ((noreturn));
 static void xt_warning_handler (String message);
 static void redraw_partial_vert (Widget w);
 static void redraw_partial_horz (Widget w);
@@ -99,7 +104,7 @@ static void drag_diff (Widget w, XtPoint
 static void show_version (Widget parent);
 static void update_overall (void);
 static void refresh (void);
-static void toggle_saveas_sensitive (Boolean sensitive);
+static void toggle_saveas_sensitive (Boolean saveas, Boolean save_left, Boolean save_right);
 static void exit_cb (Widget w, XtPointer closure, XtPointer call_data);
 static void Select (Widget widget, XEvent *event, String *params, Cardinal *num_params);
 static void Scroll (Widget widget, XEvent *event, String *params, Cardinal *num_params);
@@ -109,9 +114,16 @@ static void select_all (Side side);
 static void unselect_all (void);
 static Boolean all_selected (void);
 static Dimension get_preferred_width (Widget w);
-static char *basename (char *name);
+#if !(defined __GLIBC__ && __GLIBC__ >= 2)
+static char *mgdiff_basename (char *name);
+#endif
+
+enum {
+    WIDGET_LEFT	 = 0x10000000,
+    WIDGET_RIGHT = 0x20000000
+} ;
 
-#define APP_DEFAULTS_VERSION 1
+#define APP_DEFAULTS_VERSION 2
 
 /* 
  * treat failure to find the resources from the application defaults
@@ -120,10 +132,16 @@ static char *basename (char *name);
  */
 static String fallbacks[] = {
     "*menubar.button_0.XmString: File",
-    "*file_menu*button_4.XmString: Exit",
+    "*file_menu*button_6.XmString: Exit",
     NULL
 };
 
+static char unselected_text_msg [] =
+    "Unselected blocks remain.\n\n"
+    "Press Cancel to go back to correct this.\n"
+    "Pressing OK will save the merged data with all unselected\n"
+    "blocks absent from the output file." ;
+
 static XrmOptionDescRec option_table[] = {
     {"-quit", "quitIfSame", XrmoptionNoArg, "true"},
     {"-args", "diffArgs", XrmoptionSepArg, NULL},
@@ -137,6 +155,7 @@ static Pixmap bitmap;
 
 static struct screenstate {
     Block *b;
+    Block *lastSelected;
     int topline;
     int leftcol;
     int sindex, findex[2];
@@ -170,7 +189,7 @@ static Widget form22, frame41, linenumr;
 
 static char *str_fnamel, *str_fnamer;
 static char *str_snamel, *str_snamer;
-static char *tempfname;
+static char tempfname [512] = "" ;
 static char *user_filename;
 char *progname;
 
@@ -195,8 +214,11 @@ static Boolean debug_flag;
  * anyway) and less complex than turning on and correctly processing
  * GraphicsExpose events.
  */
-static int statel = VisibilityFullyObscured;
-static int stater = VisibilityFullyObscured;
+
+/* Make the initial state unobscured. */
+static int statel = VisibilityUnobscured;
+static int stater = VisibilityUnobscured;
+
 
 /* ARGSUSED1 */
 static void Visible (Widget widget, XtPointer closure, XEvent *event, Boolean *continue_to_dispatch)
@@ -398,23 +420,37 @@ static void drawit (Widget w, XtPointer
     Region region;
     Block *b;
     GC fore, back;
-    int columns;
-
+    int columns, widget_side;
+	
+    Side x_selection = NEITHER;
+    Block *curr_x_block = newss.lastSelected;
+	
+    if (curr_x_block) {
+	x_selection = curr_x_block->selected;
+    }
+	
     XtVaGetValues (w, XmNwidth, &width, XmNheight, &height, NULL);
     XtAddExposureToRegion (cbs->event, region = XCreateRegion ());
 
     columns = (int) width / font_width + 1;
 
+    if (w == textl)
+	widget_side = WIDGET_LEFT;
+    else if (w == textr)
+	widget_side = WIDGET_RIGHT;
+    else
+	assert (False);
+
     itemp = newss.sindex;
     ypos = 0;
     for (b = newss.b; b != NULL; b = b->next) {
 	int j;
 	Chunk *ths, *oth;
 
-	if (w == textl) {
+	if (widget_side == WIDGET_LEFT) {
 	    ths = &b->arr[LEFT];
 	    oth = &b->arr[RIGHT];
-	    if (b->selected == LEFT) {
+	    if (b->selected == LEFT || b->selected == BOTH) {
 		fore = gcfore[4];
 		back = gcback[4];
 	    }
@@ -423,10 +459,10 @@ static void drawit (Widget w, XtPointer
 		back = gcback[ths->type];
 	    }
 	}
-	else if (w == textr) {
+	else if (widget_side == WIDGET_RIGHT) {
 	    ths = &b->arr[RIGHT];
 	    oth = &b->arr[LEFT];
-	    if (b->selected == RIGHT) {
+	    if (b->selected == RIGHT || b->selected == BOTH) {
 		fore = gcfore[4];
 		back = gcback[4];
 	    }
@@ -520,7 +556,7 @@ static void drawit (Widget w, XtPointer
 /* ARGSUSED */
 static void file_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((intptr_t) closure) {
     case 0:			/* open */
 	toggle_open_sensitive (False);
 	set_cursor (toplevel);
@@ -537,15 +573,32 @@ static void file_cb (Widget w, XtPointer
 	open_right_file (toplevel, str_fnamer);
 	break;
     case 3:			/* save as */
-	if (all_selected ()) {
-	    set_cursor (toplevel);
-	    save_file (toplevel, di->first, str_fnamel);
+	if (all_selected () == False) {
+	    if (modal_question (toplevel, "Mgdiff Save", unselected_text_msg) == False)
+		break;
 	}
-	else {
-	    werror (toplevel, "Save Error", "Save", "there are unselected text blocks");
+	save_file (toplevel, di->first, str_fnamel);
+	break;
+	case 4:			/* save as left */
+	if (all_selected () == False) {
+	    if (modal_question (toplevel, "Mgdiff Save", unselected_text_msg) == False)
+		break;
+	}
+	    set_cursor (toplevel);
+	    save_as_filename (toplevel, di->first, str_fnamel);
+	    reset_cursor (toplevel);
+	break;
+	case 5:			/* save as right */
+	if (all_selected () == False) {
+	    if (modal_question (toplevel, "Mgdiff Save", unselected_text_msg) == False)
+		break;
 	}
+	    set_cursor (toplevel);
+	    save_as_filename (toplevel, di->first, str_fnamer);
+	    reset_cursor (toplevel);
+
 	break;
-    case 4:			/* exit */
+    case 6:			/* exit */
 	exit_cb (w, NULL, NULL);
 	break;
     default:
@@ -560,7 +613,7 @@ static void file_cb (Widget w, XtPointer
 /* ARGSUSED */
 static void view_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((intptr_t) closure) {
     case 0:			/* previous */
 	prev_diff (NULL, NULL, NULL);
 	break;
@@ -582,7 +635,7 @@ static void view_cb (Widget w, XtPointer
 /* ARGSUSED */
 static void select_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((intptr_t) closure) {
     case 0:			/* left */
 	select_all (LEFT);
 	break;
@@ -604,7 +657,7 @@ static void select_cb (Widget w, XtPoint
 /* ARGSUSED */
 static void options_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((intptr_t) closure) {
     case 0:			/* toggle overview area */
 	overview_flag = !overview_flag;
 	if (overview_flag) {
@@ -660,7 +713,7 @@ static void options_cb (Widget w, XtPoin
 /* ARGSUSED */
 static void helpmenu_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((intptr_t) closure) {
     case 0:			/* version */
 	show_version (toplevel);
 	break;
@@ -724,7 +777,6 @@ static void set_pixmaps (WidgetList chil
 	dagcb = XtGetGC (children[1], GCForeground|GCBackground, &gc_values);
 	been_here = 1;
     }
-
     for (i = 0; i < 3; i++) {
 	XtVaGetValues (children[i],
 		       XmNwidth, &width[i],
@@ -755,7 +807,7 @@ static void set_pixmaps (WidgetList chil
 	yfpos[LEFT] += b->arr[LEFT].fsize;
 	h = ((int) height[0] * yfpos[LEFT] / max (di->flines[LEFT], 1)) - y;
 	y3 = ((h == 0) ? y1 : (y1 + h - 1));
-	back = (b->selected == LEFT) ? 4 : b->arr[LEFT].type;
+	back = (b->selected == LEFT || b->selected == BOTH) ? 4 : b->arr[LEFT].type;
 	XFillRectangle (XtDisplay (children[0]), p[0], gcback[back],
 			0, y, width[0], h);
 
@@ -763,7 +815,7 @@ static void set_pixmaps (WidgetList chil
 	yfpos[RIGHT] += b->arr[RIGHT].fsize;
 	h = ((int) height[2] * yfpos[RIGHT] / max (di->flines[RIGHT], 1)) - y;
 	y4 = ((h == 0) ? y2 : (y2 + h - 1));
-	back = (b->selected == RIGHT) ? 4 : b->arr[RIGHT].type;
+	back = (b->selected == RIGHT || b->selected == BOTH) ? 4 : b->arr[RIGHT].type;
 	XFillRectangle (XtDisplay (children[2]), p[2], gcback[back],
 			0, y, width[2], h);
 
@@ -906,6 +958,7 @@ static void add_actions (XtAppContext ap
      */
     static char *foo3 = "\
 	<Btn1Down>: Select() \n\
+	<Btn2Down>: Select() \n\
 	~Ctrl <Key>osfPageDown: Scroll(PageDown) \n\
 	~Ctrl <Key>osfPageUp: Scroll(PageUp) \n\
 	<Key>osfLeft: Scroll(Left) \n\
@@ -951,8 +1004,9 @@ static void add_actions (XtAppContext ap
  */
 static void cleanup_at_exit (void)
 {
-    if (tempfname != NULL)
+    if (strlen (tempfname) > 0)
 	(void) unlink (tempfname);
+    tempfname [0] = 0 ; 
 }
 
 /* 
@@ -1017,8 +1071,11 @@ int main (int argc, char *argv[])
     {"quitIfSame", "QuitIfSame", XtRBoolean, sizeof (Boolean), 0, XtRString, "false"},
     {"debug", "Debug", XtRBoolean, sizeof (Boolean), 0, XtRString, "false"},
     {"filename", "Filename", XtRString, sizeof (String), 0, XtRString, ""}};
-    
+#if !(defined __GLIBC__ && __GLIBC__ >= 2)
+    progname = mgdiff_basename (argv[0]);
+#else
     progname = basename (argv[0]);
+#endif
 
     toplevel = XtVaAppInitialize (&app, "Mgdiff", option_table, XtNumber (option_table),
 #if X11R5
@@ -1027,6 +1084,10 @@ int main (int argc, char *argv[])
 				  (unsigned int *) &argc,
 #endif
 				  argv, fallbacks, NULL);
+    setlocale (LC_ALL, "");
+    setlocale (LC_CTYPE, "POSIX");
+    XtSetLanguageProc (app, NULL, NULL);
+
 
     XtVaGetValues (toplevel, XmNdepth, &depth, NULL);
     if (depth == 1)
@@ -1079,7 +1140,6 @@ int main (int argc, char *argv[])
 	};
 	werror_long (toplevel, "Wrong Application Defaults", array, sizeof (array) / sizeof (array[0]));
     }
-
     if (debug_flag) {
 	XSetErrorHandler (x_error_handler);
 	XtAppSetErrorHandler (app, xt_error_handler);
@@ -1087,7 +1147,10 @@ int main (int argc, char *argv[])
     else
 	XtAppSetWarningHandler (app, xt_warning_handler);
 
-#if sun
+#if 0
+    /* May possibly be required on some old versions of SunOS.
+    ** Definitely not required on Solaris.
+    */
     (void) on_exit (cleanup_at_exit, NULL);
 #else
     (void) atexit (cleanup_at_exit);
@@ -1109,14 +1172,17 @@ int main (int argc, char *argv[])
 	 * two filenames on command line; process them
 	 */
     case 3:
+	if (strcmp (argv[1], "-") == 0 && strcmp (argv[2], "-") == 0) {
+		(void) fprintf (stderr, "Cannot use stdin for both file input\n");
+		exit (2);
+	}
 	if (strcmp (argv[1], "-") == 0) {
-	    tempfname = tempnam (NULL, "mgdif");
-	    str_fnamel = strdup (tempfname);
-	    str_snamel = strdup (user_filename);
-	    if (!copy_to_file (stdin, tempfname)) {
+	    if (!copy_to_tempfile (stdin, tempfname, sizeof (tempfname))) {
 		(void) fprintf (stderr, "Error copying stdin to temp file \"%s\"\n", tempfname);
 		exit (2);
 	    }
+	    str_fnamel = strdup (tempfname);
+	    str_snamel = strdup (user_filename);
 	}
 	else if (!file_tests (toplevel, argv[1])) {
 	    no_files_flag = True;
@@ -1131,13 +1197,12 @@ int main (int argc, char *argv[])
 	}
 
 	if (strcmp (argv[2], "-") == 0) {
-	    tempfname = tempnam (NULL, "mgdif");
-	    str_fnamer = strdup (tempfname);
-	    str_snamer = strdup (user_filename);
-	    if (!copy_to_file (stdin, tempfname)) {
+	    if (!copy_to_tempfile (stdin, tempfname, sizeof (tempfname))) {
 		(void) fprintf (stderr, "Error copying stdin to temp file \"%s\"\n", tempfname);
 		exit (2);
 	    }
+	    str_fnamer = strdup (tempfname);
+	    str_snamer = strdup (user_filename);
 	}
 	else if (!file_tests (toplevel, argv[2])) {
 	    no_files_flag = True;
@@ -1174,6 +1239,7 @@ int main (int argc, char *argv[])
     }
 
     newss.b = di->first;
+    newss.lastSelected= NULL;
     newss.topline = newss.sindex = newss.findex[LEFT] = newss.findex[RIGHT] = 0;
 
     mainw = XtVaCreateManagedWidget ("mainw", xmMainWindowWidgetClass,
@@ -1205,10 +1271,13 @@ int main (int argc, char *argv[])
 				  XmVaPUSHBUTTON, NULL, NULL, NULL, NULL,
 				  XmVaSEPARATOR,
 				  XmVaPUSHBUTTON, NULL, NULL, NULL, NULL,
+				  XmVaPUSHBUTTON, NULL, NULL, NULL, NULL,
+				  XmVaSEPARATOR,
+				  XmVaPUSHBUTTON, NULL, NULL, NULL, NULL,
 				  NULL);
     if (no_files_flag || (di->status == 2)) {
 	toggle_openlr_sensitive (False);
-	toggle_saveas_sensitive (False);
+	toggle_saveas_sensitive (False, False, False);
     }
     XmVaCreateSimplePulldownMenu (menubar, "view_menu", 1, view_cb,
 				  XmVaPUSHBUTTON, NULL, NULL, NULL, NULL,
@@ -1491,6 +1560,7 @@ int main (int argc, char *argv[])
 
     XtAppMainLoop (app);
     /* NOTREACHED */
+    return 0;
 }
 
 static void redraw_partial_vert (Widget w)
@@ -1622,9 +1692,9 @@ static void update_line_numbers (int l,
 {
     char buffer[16];
 
-    (void) sprintf (buffer, "%*d", linenum_columns, l);
+    (void) snprintf (buffer, sizeof (buffer), "%*d", linenum_columns, l);
     XmTextFieldSetString (linenuml, buffer);
-    (void) sprintf (buffer, "%*d", linenum_columns, r);
+    (void) snprintf (buffer, sizeof (buffer), "%*d", linenum_columns, r);
     XmTextFieldSetString (linenumr, buffer);
 }
 
@@ -1860,19 +1930,20 @@ static void next_diff (Widget w, XtPoint
 
 	    value = (b->sline >= lines_of_context) ? (b->sline - lines_of_context) : b->sline;
 	    XtVaGetValues (sb, XmNmaximum, &maximum, XmNsliderSize, &slidersize, NULL);
-	    if (value > (maximum - slidersize))
-		value = maximum - slidersize;
 
 	    if ((w == sbl) || (w == sbr)) {
 		int side = (w == sbl) ? LEFT : RIGHT;
 
-		if (newcbs.value > (maximum - slidersize)) {
-		    newcbs.value = maximum - slidersize;
-		    XtVaSetValues (w, XmNvalue, newcbs.value - b->sline + b->arr[side].fline, NULL);
+		if (value > (maximum - slidersize)) {
+		    value = maximum - slidersize;
+		    XtVaSetValues (w, XmNvalue, value - b->sline + b->arr[side].fline, NULL);
 		    return;
 		}
 	    }
 
+	    if (value > (maximum - slidersize))
+		value = maximum - slidersize;
+
 	    newcbs.reason = XmCR_VALUE_CHANGED;
 	    newcbs.event = NULL;
 	    newcbs.value = value;
@@ -1986,7 +2057,7 @@ static void show_version (Widget parent)
 					      mgdiff_width, mgdiff_height,
 					      fg, bg,
 					      DefaultDepth (dpy, DefaultScreen (dpy)));
-	(void) sprintf (buffer, "mgdiff\n\nA graphical difference browser\n\nAuthor: Dan Williams (dan@sass.com)\nVersion: %s PL%s", VERSION, PATCHLEVEL);
+	(void) snprintf (buffer, sizeof (buffer), "mgdiff\n\nA graphical difference browser\n\nAuthors: Dan Williams (dan@sass.com)\nErik de Castro Lopo (erikd@mega-nerd.com)\n\nVersion: %s PL%s", VERSION, PATCHLEVEL);
 
 	XtVaSetValues (dialog,
 		       XmNautoUnmanage, True,
@@ -2041,12 +2112,12 @@ void process_both_files (char *file1, ch
     if (di->status != 2) {
 	no_files_flag = False;
 	toggle_openlr_sensitive (True);
-	toggle_saveas_sensitive (True);
+	toggle_saveas_sensitive (True, True, True);
     }
     else {
 	no_files_flag = True;
 	toggle_openlr_sensitive (False);
-	toggle_saveas_sensitive (False);
+	toggle_saveas_sensitive (False, False, False);
 	free (str_fnamel);
 	free (str_snamel);
 	free (str_fnamer);
@@ -2082,7 +2153,7 @@ void process_left_file (char *file1, cha
     if (di->status == 2) {
 	no_files_flag = True;
 	toggle_openlr_sensitive (False);
-	toggle_saveas_sensitive (False);
+	toggle_saveas_sensitive (False, False, False);
 	free (str_fnamel);
 	free (str_snamel);
 	free (str_fnamer);
@@ -2117,7 +2188,7 @@ void process_right_file (char *file2, ch
     if (di->status == 2) {
 	no_files_flag = True;
 	toggle_openlr_sensitive (False);
-	toggle_saveas_sensitive (False);
+	toggle_saveas_sensitive (False, False, False);
 	free (str_fnamel);
 	free (str_snamel);
 	free (str_fnamer);
@@ -2133,6 +2204,7 @@ void process_right_file (char *file2, ch
     handle_diff_errors (di);
 }
 
+
 static void refresh (void)
 {
     newss.b = di->first;
@@ -2182,9 +2254,11 @@ void toggle_open_sensitive (Boolean sens
     toggle_openlr_sensitive (sensitive);
 }
 
-static void toggle_saveas_sensitive (Boolean sensitive)
+static void toggle_saveas_sensitive (Boolean saveas, Boolean save_left, Boolean save_right)
 {
-    XtSetSensitive (XtNameToWidget (file_menu, "button_3"), sensitive);
+    XtSetSensitive (XtNameToWidget (file_menu, "button_3"), saveas);
+    XtSetSensitive (XtNameToWidget (file_menu, "button_4"), save_left);
+    XtSetSensitive (XtNameToWidget (file_menu, "button_5"), save_right);
 }
 
 /* 
@@ -2196,78 +2270,263 @@ static void exit_cb (Widget w, XtPointer
     exit ((di != NULL) ? di->status : 2);
 }
 
+static void lost_selection ( Widget  widget, Atom* selection) { 
+	
+	if (debug_flag) {
+		fprintf(stderr,"selection lost on widget %p\n",widget);
+	}
+//	newss.lastSelected=NULL;
+}
+
+static Boolean do_selection(Widget widget, Atom*  selection, Atom*  target ,
+                            Atom*  type, XtPointer*  value, 
+			    unsigned long* length,int* format) {
+
+    Atom targets = XInternAtom(XtDisplay(widget), "TARGETS", False);
+    Atom *array;
+    char* result;
+    char* line;
+    int i,j;
+    Block *b= newss.lastSelected;
+    Chunk *chunk =NULL;
+    
+    if (debug_flag) {
+		fprintf(stderr,"selection request on widget %p\n",widget);
+    }
+
+   if (!b) return False;
+   
+   chunk = &(b->arr[b->selected]);
+   
+    if (*target == targets)
+    {
+	if (debug_flag) {
+		fprintf(stderr,"clipboards targets requested on widget %p\n",widget);
+        }	
+	/*
+	 * Handle request for data types
+	 */
+
+	if ((array = (Atom *)XtMalloc((unsigned)(sizeof(Atom) * 1))) == NULL)
+	    return False;
+	*value = (XtPointer)array;
+	array[0] = XA_STRING;
+	*type = XA_ATOM;
+	*format = sizeof(Atom) * 8;
+	*length = 5;
+	return True;
+    }
+    
+    if (*target == XA_STRING) {
+    	/*
+	 * request for string data !.
+	 */
+	if (debug_flag) {
+		fprintf(stderr,"string target requested on widget %p\n",widget);
+	}
+    	
+	/*
+	 * Iterate through the lines in the text block
+	 * summing the lengths
+	 */
+	*length=0;
+	for (i = 0; i < chunk->fsize; i++) {
+	   if ((chunk->wtext != NULL) && (chunk->wtext[i] != NULL)) {
+	       *length += (strlen(chunk->wtext[i])+1);
+	   } else {
+	       *length += (strlen(chunk->text[i])+1);
+	   }
+         }
+        *format = 8;	    /* 8 bits per char */
+	*type  = XA_STRING;
+	if (debug_flag) {
+		fprintf(stderr,"string length= %li\n",*length);
+	}
+
+    	*value = XtMalloc(*length);
+        result = (char*)(*value);
+ 	/*
+	 * Iterate through the lines in the text block
+	 * moving the data into the clipboard memblock
+	 */
+	for (i = 0; i < chunk->fsize; i++) {
+	   if ((chunk->wtext != NULL) && (chunk->wtext[i] != NULL)) {
+	      line = chunk->wtext[i] ;
+	   } else {
+	       line = chunk->text[i];
+	   }
+	   j =strlen(line);
+	   memcpy(result,line,j);
+	   result+=j;
+	   *(result++)= '\n';
+         }
+ 	
+	
+	if (debug_flag) {
+		fprintf(stderr,"all done string at= %p\n",*value);
+	}
+	if (!(*value)) {
+		return False;
+    	}
+	return True;
+    }
+    /* 
+     * Haven't found data type we know about!
+     */
+    return False;	
+}
+
+
+
+
 /* ARGSUSED2 */
 static void Select (Widget widget, XEvent *event, String *params, Cardinal *num_params)
 {
-    if (event->xany.type == ButtonPress) {
+    /*
+    ** The original version of this function was rather confusing. It was
+    ** rewritten to make it easier to follow so that more selection features
+    ** could then be added (ie select both left and right).
+    ** The function itself and the main for loop are written so that evaluation
+    ** of current state occurs at the top and processing at the bottom. For
+    ** instance, the first test to see if the XEvent is a ButtonPress returns
+    ** from the function rather than making the whole function one huge if
+    ** statement. Similarly, continue statements are used in the for loop to
+    ** bypass the lower part of the loop.
+    */
 	Block *b;
 	Dimension ypos, height;
-	int itemp, rect_height;
+    int itemp, rect_height, widget_side;
+ 	Side x_selection = NEITHER;
+        Block *curr_x_block = newss.lastSelected;
+
+    if (event->xany.type != ButtonPress)
+	return;
+
+    if (widget == textl)
+	widget_side = WIDGET_LEFT;
+    else if (widget == textr)
+	widget_side = WIDGET_RIGHT;
+    else
+	assert (False);
+
+ 	
+ 	if (curr_x_block) {
+		x_selection = curr_x_block->selected;
+ 	}
 
 	XtVaGetValues (widget, XmNheight, &height, NULL);
 
 	itemp = newss.sindex;
 	ypos = 0;
+ 	//Find selected chunk!.
 	for (b = newss.b; b != NULL; b = b->next) {
+	/* If the current ypos is > height of window, we're done, so just return. */
+	    if (ypos > height)
+	    	return;
+
 	    if ((rect_height = font_height * (b->ssize - itemp)) > (int) height)
 		rect_height = height;
+	itemp = 0;
 
-	    if ((event->xbutton.y >= (unsigned int) ypos) &&
-		(event->xbutton.y < (unsigned int) (ypos + rect_height)) &&
-		(b->arr[LEFT].type != SAME)) {
-		switch (b->selected) {
-		case LEFT:
-		    if (widget == textl) {
-			b->selected = NEITHER;
-			redraw_partial (textl, ypos, rect_height);
-			redraw_partial (textr, ypos, rect_height);
-			update_pixmaps ();
+	if (event->xbutton.y < (unsigned int) ypos) {
+	    ypos += rect_height;
+	    continue;
 		    }
-		    else if (widget == textr) {
-			b->selected = RIGHT;
-			redraw_partial (textl, ypos, rect_height);
-			redraw_partial (textr, ypos, rect_height);
-			update_pixmaps ();
+
+	if (event->xbutton.y >= (unsigned int) (ypos + rect_height)) {
+	    ypos += rect_height;
+	    continue;
 		    }
-		    else
-			assert (False);
-		    break;
-		case RIGHT:
-		    if (widget == textl) {
+
+	/*
+	** Have now found the selected block.
+	** If the LH and RH sides of the selected block are the same, then
+	** there is nothing to do, so just return.
+	*/
+	if (b->arr[LEFT].type == SAME)
+	    return;
+
+	/*
+	** This state machine has been rewritten as a true state machine. The
+	** original had three cases (LEFT< RIGHT, NEITHER) and an if statement
+	** in each case. Since the original simplification, more states have
+	** been added (ie select BOTH state).
+	*/
+	switch (widget_side | (event->xbutton.button << 4) | b->selected) {
+	    case WIDGET_LEFT  | (1<<4) | NEITHER:
+	    case WIDGET_LEFT  | (1<<4) | RIGHT:
+	    case WIDGET_LEFT  | (1<<4) | BOTH:
 			b->selected = LEFT;
-			redraw_partial (textl, ypos, rect_height);
-			redraw_partial (textr, ypos, rect_height);
-			update_pixmaps ();
-		    }
-		    else if (widget == textr) {
+		break;
+	    case WIDGET_LEFT  | (1<<4) | LEFT:
+	    case WIDGET_RIGHT | (2<<4) | BOTH:
 			b->selected = NEITHER;
-			redraw_partial (textl, ypos, rect_height);
-			redraw_partial (textr, ypos, rect_height);
-			update_pixmaps ();
-		    }
-		    else
-			assert (False);
 		    break;
-		case NEITHER:
-		    b->selected = (widget == textl) ? LEFT : RIGHT;
-		    redraw_partial (textl, ypos, rect_height);
-		    redraw_partial (textr, ypos, rect_height);
-		    update_pixmaps ();
+
+	    case WIDGET_RIGHT | (1<<4) | NEITHER:
+	    case WIDGET_RIGHT | (1<<4) | LEFT:
+	    case WIDGET_RIGHT | (1<<4) | BOTH:
+		b->selected = RIGHT;
+		break;
+	    case WIDGET_RIGHT | (1<<4) | RIGHT:
+	    case WIDGET_LEFT  | (2<<4) | BOTH:
+		b->selected = NEITHER;
 		    break;
-		default:
-		    assert (False);
+
+	    case WIDGET_LEFT  | (2<<4) | NEITHER:
+	    case WIDGET_LEFT  | (2<<4) | LEFT:
+	    case WIDGET_LEFT  | (2<<4) | RIGHT:
+	    	if (b->arr[LEFT].type == DIFF) {
+		    b->selected = BOTH;
 		    break;
 		}
-		return;
-	    }
+		if (b->arr[LEFT].wtext != NULL)
+		    b->selected = (b->selected == LEFT) ? NEITHER : LEFT;
+	    	break ;
+
+	    case WIDGET_RIGHT | (2<<4) | NEITHER:
+	    case WIDGET_RIGHT | (2<<4) | LEFT:
+	    case WIDGET_RIGHT | (2<<4) | RIGHT:
+	    	if (b->arr[LEFT].type == DIFF) {
+		    b->selected = BOTH;
+		    break;
+		}
+	    	if (b->arr[RIGHT].wtext != NULL)
+		    b->selected = (b->selected == RIGHT) ? NEITHER : RIGHT;
+	    	break ;
 
-	    ypos += rect_height;
 
-	    itemp = 0;
-	    if (ypos > height)
-		return;
+		default:
+		printf ("Button:%d    widget:%s    sel:%d\n", event->xbutton.button, 
+			widget_side == WIDGET_LEFT ? "LEFT" : "RIGHT", b->selected) ;
+		    assert (False);
+		    break;
+		}
+	redraw_partial (textl, ypos, rect_height);
+	redraw_partial (textr, ypos, rect_height);
+	update_pixmaps ();
+      
+	if (  b->selected == NEITHER ) {
+		if (b == newss.lastSelected)
+ 			newss.lastSelected=NULL;
+	} else {
+		newss.lastSelected=b;
 	}
-    }
+	
+	if ( !newss.lastSelected 
+	      || (x_selection != newss.lastSelected->selected)
+  //	     || (newss.lastSelected != curr_x_block ) 
+ 	    )
+	{
+ 		XtDisownSelection(widget,XA_PRIMARY, CurrentTime);
+	}
+	
+ 	if (newss.lastSelected) {
+ 	   XtOwnSelection(widget,XA_PRIMARY, CurrentTime,&do_selection,&lost_selection,NULL);
+  	}
+
+	return;
+	    }
 }
 
 /* 
@@ -2307,14 +2566,14 @@ static void Scroll (Widget widget, XEven
 	else {
 	    char buffer[1024];
 	    
-	    (void) sprintf (buffer, "Illegal argument to action proc Scroll (\"%s\")", params[0]);
+	    (void) snprintf (buffer, sizeof (buffer), "Illegal argument to action proc Scroll (\"%s\")", params[0]);
 	    XtAppWarning (XtWidgetToApplicationContext (widget), buffer);
 	}
     }
     else {
 	char buffer[1024];
 	    
-	(void) sprintf (buffer, "Illegal number of arguments to action proc Scroll (\"%d\")", *num_params);
+	(void) snprintf (buffer, sizeof (buffer), "Illegal number of arguments to action proc Scroll (\"%d\")", *num_params);
 	XtAppWarning (XtWidgetToApplicationContext (widget), buffer);
     }
 }
@@ -2391,7 +2650,8 @@ static Dimension get_preferred_width (Wi
 /* 
  * delete any prefix ending in '/' and return a copy
  */
-static char *basename (char *path)
+#if !(defined __GLIBC__ && __GLIBC__ >= 2)
+static char *mgdiff_basename (char *path)
 {
     if (path) {
 	char *p;
@@ -2416,3 +2676,4 @@ static char *basename (char *path)
     else
 	return (NULL);
 }
+#endif
