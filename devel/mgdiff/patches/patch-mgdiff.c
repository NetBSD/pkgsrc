$NetBSD: patch-mgdiff.c,v 1.1 2023/01/02 22:43:53 vins Exp $

Prevent unsafe use of tmpnam(). 

--- mgdiff.c.orig	1994-09-29 01:56:53.000000000 +0000
+++ mgdiff.c
@@ -520,7 +520,7 @@ static void drawit (Widget w, XtPointer 
 /* ARGSUSED */
 static void file_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((uintptr_t) closure) {
     case 0:			/* open */
 	toggle_open_sensitive (False);
 	set_cursor (toplevel);
@@ -560,7 +560,7 @@ static void file_cb (Widget w, XtPointer
 /* ARGSUSED */
 static void view_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((uintptr_t) closure) {
     case 0:			/* previous */
 	prev_diff (NULL, NULL, NULL);
 	break;
@@ -582,7 +582,7 @@ static void view_cb (Widget w, XtPointer
 /* ARGSUSED */
 static void select_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((uintptr_t) closure) {
     case 0:			/* left */
 	select_all (LEFT);
 	break;
@@ -604,7 +604,7 @@ static void select_cb (Widget w, XtPoint
 /* ARGSUSED */
 static void options_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((uintptr_t) closure) {
     case 0:			/* toggle overview area */
 	overview_flag = !overview_flag;
 	if (overview_flag) {
@@ -660,7 +660,7 @@ static void options_cb (Widget w, XtPoin
 /* ARGSUSED */
 static void helpmenu_cb (Widget w, XtPointer closure, XtPointer call_data)
 {
-    switch ((int) closure) {
+    switch ((uintptr_t) closure) {
     case 0:			/* version */
 	show_version (toplevel);
 	break;
@@ -1110,7 +1110,9 @@ int main (int argc, char *argv[])
 	 */
     case 3:
 	if (strcmp (argv[1], "-") == 0) {
-	    tempfname = tempnam (NULL, "mgdif");
+	    char xxx[20];
+	    sprintf(tempfname, "mgdif.XXXXXXXX");
+	    close(mkstemp (tempfname));
 	    str_fnamel = strdup (tempfname);
 	    str_snamel = strdup (user_filename);
 	    if (!copy_to_file (stdin, tempfname)) {
@@ -1131,7 +1133,9 @@ int main (int argc, char *argv[])
 	}
 
 	if (strcmp (argv[2], "-") == 0) {
-	    tempfname = tempnam (NULL, "mgdif");
+	   char xxx[20];
+            sprintf(tempfname, "mgdif.XXXXXXXX");
+            close(mkstemp (tempfname));
 	    str_fnamer = strdup (tempfname);
 	    str_snamer = strdup (user_filename);
 	    if (!copy_to_file (stdin, tempfname)) {
