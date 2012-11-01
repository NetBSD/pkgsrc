$NetBSD: patch-graphics.c,v 1.1 2012/11/01 19:55:37 joerg Exp $

--- graphics.c.orig	2012-10-30 22:02:54.000000000 +0000
+++ graphics.c
@@ -535,7 +535,7 @@ NODE *lback(NODE *arg) {
 }
 
 NODE *lshowturtle(NODE *args) {
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     if (!turtle_shown) {
 	turtle_shown = TRUE;
 	draw_turtle();
@@ -545,7 +545,7 @@ NODE *lshowturtle(NODE *args) {
 }
 
 NODE *lhideturtle(NODE *args) {
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     if (turtle_shown) {
 	draw_turtle();
 	turtle_shown = FALSE;
@@ -874,7 +874,7 @@ NODE *llabel(NODE *arg) {
     *print_stringptr = '\0';
 	
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	draw_turtle();
 	theLength = strlen(textbuf);
 #ifdef mac
@@ -983,7 +983,7 @@ NODE *lsetpencolor(NODE *arg) {
     NODE *val = pos_int_arg(arg);
 
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	set_pen_color(getint(val));
 	save_color();
 	done_drawing;
@@ -995,7 +995,7 @@ NODE *lsetbackground(NODE *arg) {
     NODE *val = pos_int_arg(arg);
 
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	set_back_ground(getint(val));
 	done_drawing;
     }
@@ -1008,7 +1008,7 @@ NODE *lsetpalette(NODE *args) {
 	int slotnum = (int)getint(slot);
 
 	if (NOT_THROWING && (slotnum > 7)) {
-		prepare_to_draw;
+		prepare_to_draw2(UNBOUND);
 		set_palette(slotnum,
 			    (unsigned int)getint(car(arg)),
 			    (unsigned int)getint(cadr(arg)),
@@ -1057,7 +1057,7 @@ NODE *lsetpensize(NODE *args) {
     NODE *arg = pos_int_vector_arg(args);
 
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	set_pen_width((int)getint(car(arg)));
 	set_pen_height((int)getint(cadr(arg)));
 	save_size();
@@ -1074,7 +1074,7 @@ NODE *lsetpenpattern(NODE *args) {    
 	arg = err_logo(BAD_DATA, arg);
 	
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	set_list_pen_pattern(arg);
 	save_pattern();
 	done_drawing;
@@ -1090,7 +1090,7 @@ NODE *lsetscrunch(NODE *args) {
     ynode = numeric_arg(cdr(args));
 
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	draw_turtle();
 	x_scale = (nodetype(xnode) == FLOATT) ? getfloat(xnode) :
 			       (FLONUM)getint(xnode);
@@ -1227,7 +1227,7 @@ NODE *larc(NODE *arg) {
 	else
 	    radius = getfloat(val2);
 
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	draw_turtle();
 
 	/* save and force turtle state */
@@ -1582,7 +1582,7 @@ NODE *lloadpict(NODE *args) {
     lopenread(args);
 #endif
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	fp = (FILE *)file_list->n_obj;
 	restore_palette(fp);
 	fread(&record_index, sizeof(FIXNUM), 1, fp);
