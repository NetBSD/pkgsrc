$NetBSD: patch-graphics.c,v 1.4 2015/12/29 23:34:56 dholland Exp $

Fix a number of cases of plainly invalid C and portability issues.

--- graphics.c.orig	2008-09-03 17:58:13.000000000 +0000
+++ graphics.c
@@ -231,7 +231,7 @@ void draw_turtle_helper(void) {
     FLONUM delta_x, delta_y;
 #endif
    
-    prepare_to_draw;
+    prepare_to_draw(UNBOUND);
     prepare_to_draw_turtle;
     save_pen(&saved_pen);
     plain_xor_pen();
@@ -276,7 +276,7 @@ void save_string(char *, int);
 void save_arc(FLONUM, FLONUM, FLONUM, FLONUM, FLONUM, FLONUM, FLONUM, FLONUM);
 
 void right(FLONUM a) {
-    prepare_to_draw;
+    prepare_to_draw(UNBOUND);
     draw_turtle();
     turtle_heading += a;
     turtle_heading = pfmod(turtle_heading,360.0);
@@ -336,7 +336,7 @@ void forward(FLONUM d) {
    // #ifndef WIN32
     internal_hideturtle();
    // #endif
-    prepare_to_draw;
+    prepare_to_draw(UNBOUND);
     draw_turtle();
     forward_helper(d);
     draw_turtle();
@@ -570,7 +570,7 @@ NODE *lback(NODE *arg) {
 
 NODE *lshowturtle(NODE *args) {
     if(!graphics_setup) graphics_setup++;
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     if (!turtle_shown) {
 	turtle_shown = TRUE;
 	draw_turtle();
@@ -582,7 +582,7 @@ NODE *lshowturtle(NODE *args) {
 
 void internal_hideturtle() {
     if(!graphics_setup) graphics_setup++;
-    prepare_to_draw;
+    prepare_to_draw(UNBOUND);
     if (turtle_shown) {
 	draw_turtle();
 	turtle_shown = FALSE;
@@ -616,7 +616,7 @@ NODE *lsetheading(NODE *arg) {
     
     val = numeric_arg(arg);
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	draw_turtle();
 	if (nodetype(val) == INT)
 	    turtle_heading = (FLONUM)getint(val);
@@ -720,7 +720,7 @@ NODE *lscrunch(NODE *args) {
 }
 
 NODE *lhome(NODE *args) {
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     out_of_bounds = FALSE;
     setpos_bynumber((FLONUM)0.0, (FLONUM)0.0);
     draw_turtle();
@@ -734,7 +734,7 @@ void cs_helper(int centerp) {    
 #if defined(x_window) && !HAVE_WX
     clearing_screen++;
 #endif
-    prepare_to_draw;
+    prepare_to_draw(UNBOUND);
     clear_screen;
 #if defined(x_window) && !HAVE_WX
     clearing_screen==0;
@@ -814,7 +814,7 @@ void setpos_commonpart(FLONUM target_x, 
 
 void setpos_bynumber(FLONUM target_x, FLONUM target_y) {
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw(UNBOUND);
 	draw_turtle();
 	move_to(g_round(screen_x_coord), g_round(screen_y_coord));
 	setpos_commonpart(target_x, target_y);
@@ -827,7 +827,7 @@ void setpos_helper(NODE *xnode, NODE *yn
     
     if (NOT_THROWING) {
 	internal_hideturtle();
-	prepare_to_draw;
+	prepare_to_draw(UNBOUND);
 	draw_turtle();
 	move_to(g_round(screen_x_coord), g_round(screen_y_coord));
 	target_x = ((xnode == NIL) ?
@@ -884,7 +884,7 @@ NODE *lsety(NODE *args) {
 }
 
 NODE *lwrap(NODE *args) {
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     draw_turtle();
     current_mode = wrapmode;
     while (turtle_x > turtle_right_max) {
@@ -907,7 +907,7 @@ NODE *lwrap(NODE *args) {
 
 NODE *lfence(NODE *args) {
     (void)lwrap(args);	    /* get turtle inside the fence */
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     draw_turtle();
     current_mode = fencemode;
     draw_turtle();
@@ -916,7 +916,7 @@ NODE *lfence(NODE *args) {
 }
 
 NODE *lwindow(NODE *args) {
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     draw_turtle();
     current_mode = windowmode;
     draw_turtle();
@@ -935,7 +935,7 @@ NODE *lturtlemode(NODE *args) {
 }
 
 NODE *lfill(NODE *args) {    
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     draw_turtle();
     logofill();
     draw_turtle();
@@ -964,7 +964,7 @@ NODE *llabel(NODE *arg) {
     print_stringlen = old_stringlen;
 	
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	draw_turtle();
 	theLength = strlen(textbuf);
 #ifdef mac
@@ -1085,7 +1085,7 @@ NODE *lsetpencolor(NODE *arg) {
     NODE *val;
 
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	if (is_list(car(arg))) {
 	    val = make_intnode(PEN_COLOR_OFFSET);
 	    lsetpalette(cons(val,arg));
@@ -1107,7 +1107,7 @@ NODE *lsetbackground(NODE *arg) {
     }
 
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	if (is_list(car(arg))) {
 	    val = make_intnode(BACKGROUND_COLOR_OFFSET);
 	    lsetpalette(cons(val,arg));
@@ -1188,7 +1188,7 @@ void restore_palette(FILE *fp) {
 NODE *lsetpensize(NODE *args) {
     NODE *arg;
 
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     if (is_list(car(args))) {
 	arg = pos_int_vector_arg(args);
 	if (NOT_THROWING) {
@@ -1216,7 +1216,7 @@ NODE *lsetpenpattern(NODE *args) {    
 	arg = err_logo(BAD_DATA, arg);
 	
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	set_list_pen_pattern(arg);
 	save_pattern();
 	done_drawing;
@@ -1232,7 +1232,7 @@ NODE *lsetscrunch(NODE *args) {
     ynode = numeric_arg(cdr(args));
 
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	draw_turtle();
 	x_scale = (nodetype(xnode) == FLOATT) ? getfloat(xnode) :
 			       (FLONUM)getint(xnode);
@@ -1390,7 +1390,7 @@ NODE *larc(NODE *arg) {
 	    radius = getfloat(val2);
 
 	internal_hideturtle();
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	draw_turtle();
 
 	/* save and force turtle state */
@@ -1472,7 +1472,7 @@ NODE *lfilled(NODE *args) {
     FLONUM x1,y1,lastx,lasty;
     int old_refresh = refresh_p;
 
-    prepare_to_draw;
+    prepare_to_draw2(UNBOUND);
     if (is_list(car(args))) {
 	val = make_intnode(FILLED_COLOR_OFFSET);
 	lsetpalette(cons(val,args));
@@ -1834,7 +1834,7 @@ void redraw_graphics(void) {
 	return;
     }
 
-    prepare_to_draw;
+    prepare_to_draw(UNBOUND);
     if(!graphics_setup){
         done_drawing;
         return;
@@ -2074,7 +2074,7 @@ NODE *lloadpict(NODE *args) {
     lopenread(args);
 #endif
     if (NOT_THROWING) {
-	prepare_to_draw;
+	prepare_to_draw2(UNBOUND);
 	fp = (FILE *)file_list->n_obj;
 	restore_palette(fp);
 	fread(&rec_idx, sizeof(FIXNUM), 1, fp);
