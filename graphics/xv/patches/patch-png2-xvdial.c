$NetBSD: patch-png2-xvdial.c,v 1.1 1999/11/14 13:26:01 rh Exp $

--- xvdial.c.orig	Tue Jan  3 22:20:31 1995
+++ xvdial.c	Sun Nov 14 14:05:49 1999
@@ -45,16 +45,17 @@
 static void drawArrow       PARM((DIAL *));
 static void drawValStr      PARM((DIAL *));
 static void drawButt        PARM((DIAL *, int, int));
-static int  computeDialVal  PARM((DIAL *, int, int));
+static double computeDialVal  PARM((DIAL *, int, int));
 static void dimDial         PARM((DIAL *));
 
 
 /***************************************************/
-void DCreate(dp, parent, x, y, w, h, minv, maxv, curv, page, 
+void DCreate(dp, parent, x, y, w, h, minv, maxv, curv, inc, page, 
 	          fg, bg, hi, lo, title, units)
 DIAL         *dp;
 Window        parent;
-int           x,y,w,h,minv,maxv,curv,page;
+int           x,y,w,h;
+double        minv,maxv,curv,inc,page;
 unsigned long fg,bg,hi,lo;
 char         *title, *units;
 {
@@ -98,18 +99,18 @@
 				1,fg,bg);
   if (!dp->win) FatalError("can't create dial window");
 
-  DSetRange(dp, minv, maxv, curv, page);
+  DSetRange(dp, minv, maxv, curv, inc, page);
   XSelectInput(theDisp, dp->win, ExposureMask | ButtonPressMask);
 }
 
 
 /***************************************************/
-void DSetRange(dp, minv, maxv, curv, page)
+void DSetRange(dp, minv, maxv, curv, inc, page)
 DIAL *dp;
-int   minv, maxv, curv, page;
+double  minv, maxv, curv, inc, page;
 {
   if (maxv<minv) maxv=minv;
-  dp->min = minv;    dp->max = maxv;    dp->page = page;
+  dp->min = minv; dp->max = maxv; dp->inc = inc; dp->page = page;
   dp->active =  (minv < maxv);
 
   DSetVal(dp, curv);
@@ -119,7 +120,7 @@
 /***************************************************/
 void DSetVal(dp, curv)
 DIAL *dp;
-int   curv;
+double curv;
 {
   RANGE(curv, dp->min, dp->max);   /* make sure curv is in-range */
 
@@ -129,7 +130,7 @@
   XSetForeground(theDisp, theGC, dp->bg); 
   drawArrow(dp);
 
-  dp->val = curv;
+  dp->val = (double)((int)(curv / dp->inc + (curv > 0 ? 0.5 : -0.5))) * dp->inc;
 
   /* draw new arrow and string */
   XSetForeground(theDisp, theGC, dp->fg);
@@ -202,7 +203,8 @@
 int mx,my;
 {
   Window       rW,cW;
-  int          rx,ry, x,y, ipos, pos, lit, i, origval;
+  int          rx, ry, x, y, ipos, pos, lit;
+  double       origval;
   unsigned int mask;
 
   lit = 0;
@@ -224,9 +226,9 @@
   if (ipos != INDIAL) {
     drawButt(dp, ipos, 1);
     switch (ipos) {
-    case INCW1:  if (dp->val < dp->max) DSetVal(dp, dp->val+1); break;
+    case INCW1:  if (dp->val < dp->max) DSetVal(dp, dp->val+dp->inc);  break;
     case INCW2:  if (dp->val < dp->max) DSetVal(dp, dp->val+dp->page); break;
-    case INCCW1: if (dp->val > dp->min) DSetVal(dp, dp->val-1); break;
+    case INCCW1: if (dp->val > dp->min) DSetVal(dp, dp->val-dp->inc);  break;
     case INCCW2: if (dp->val > dp->min) DSetVal(dp, dp->val-dp->page); break;
     }
     if (dp->drawobj != NULL) (dp->drawobj)();  
@@ -235,8 +237,9 @@
   }
 
   else { 
-    i = computeDialVal(dp, mx, my);
-    DSetVal(dp, i);
+    double v;
+    v = computeDialVal(dp, mx, my);
+    DSetVal(dp, v);
     if (dp->drawobj != NULL) (dp->drawobj)();  
   }
 
@@ -246,11 +249,11 @@
     if (!(mask & Button1Mask)) break;    /* button released */
 
     if (ipos == INDIAL) {
-      int j;
-      i = computeDialVal(dp, x, y);
-      j = dp->val;
-      DSetVal(dp, i);
-      if (j != dp->val) {
+      double v, w;
+      v = computeDialVal(dp, x, y);
+      w = dp->val;
+      DSetVal(dp, v);
+      if (w != dp->val) {
 	/* track whatever dial controls */
 	if (dp->drawobj != NULL) (dp->drawobj)();  
       }
@@ -266,11 +269,11 @@
 
       if (lit) {
 	switch (ipos) {
-	case INCW1:  if (dp->val < dp->max) DSetVal(dp, dp->val+1); 
+	case INCW1:  if (dp->val < dp->max) DSetVal(dp, dp->val+dp->inc); 
 	             break;
 	case INCW2:  if (dp->val < dp->max) DSetVal(dp, dp->val+dp->page);
                      break;
-	case INCCW1: if (dp->val > dp->min) DSetVal(dp, dp->val-1);
+	case INCCW1: if (dp->val > dp->min) DSetVal(dp, dp->val-dp->inc);
                      break;
 	case INCCW2: if (dp->val > dp->min) DSetVal(dp, dp->val-dp->page);
                      break;
@@ -320,19 +323,20 @@
 static void drawArrow(dp)
 DIAL *dp;
 {
-  int i, rad, cx, cy;
+  int rad, cx, cy;
+  double v;
   XPoint arrow[4];
 
   rad = dp->rad;  cx = dp->cx;  cy = dp->cy;
 
   /* map pos (range minv..maxv) into degrees (range 240..-60) */
-  i = 240 + (-300 * (dp->val - dp->min)) / (dp->max - dp->min);
-  arrow[0].x = cx + (int) ((double) rad * .80 * cos(i * DEG2RAD));
-  arrow[0].y = cy - (int) ((double) rad * .80 * sin(i * DEG2RAD));
-  arrow[1].x = cx + (int) ((double) rad * .33 * cos((i+160) * DEG2RAD));
-  arrow[1].y = cy - (int) ((double) rad * .33 * sin((i+160) * DEG2RAD));
-  arrow[2].x = cx + (int) ((double) rad * .33 * cos((i-160) * DEG2RAD));
-  arrow[2].y = cy - (int) ((double) rad * .33 * sin((i-160) * DEG2RAD));
+  v = 240 + (-300 * (dp->val - dp->min)) / (dp->max - dp->min);
+  arrow[0].x = cx + (int) ((double) rad * .80 * cos(v * DEG2RAD));
+  arrow[0].y = cy - (int) ((double) rad * .80 * sin(v * DEG2RAD));
+  arrow[1].x = cx + (int) ((double) rad * .33 * cos((v+160) * DEG2RAD));
+  arrow[1].y = cy - (int) ((double) rad * .33 * sin((v+160) * DEG2RAD));
+  arrow[2].x = cx + (int) ((double) rad * .33 * cos((v-160) * DEG2RAD));
+  arrow[2].y = cy - (int) ((double) rad * .33 * sin((v-160) * DEG2RAD));
   arrow[3].x = arrow[0].x;
   arrow[3].y = arrow[0].y;
   XDrawLines(theDisp, dp->win, theGC, arrow, 4, CoordModeOrigin);
@@ -343,23 +347,37 @@
 static void drawValStr(dp)
 DIAL *dp;
 {
-  int  i, x1, x2;
+  int  tot, i, x1, x2;
   char foo[60], foo1[60];
 
   /* compute longest string necessary so we can right-align this thing */
-  sprintf(foo,"%d",dp->min);    x1 = strlen(foo);
-  sprintf(foo,"%d",dp->max);    x2 = strlen(foo);
+  sprintf(foo,"%d",(int)dp->min);    x1 = strlen(foo);
+  sprintf(foo,"%d",(int)dp->max);    x2 = strlen(foo);
   if (dp->min < 0 && dp->max > 0) x2++;   /* put '+' at beginning */
   i = x1;  if (x2>x1) i = x2;
   if (dp->units) i += strlen(dp->units);
 
-  if (dp->min < 0 && dp->max > 0) sprintf(foo,"%+d", dp->val);
-  else sprintf(foo,"%d", dp->val);
+  sprintf(foo,"%g",dp->inc);   /* space for decimal values */
+  tot = i + strlen(foo) - 1;   /* Take away the 0 from the beginning */
+
+  if (dp->min < 0.0 && dp->max > 0.0) sprintf(foo,"%+g", dp->val);
+  else sprintf(foo,"%g", dp->val);
+
+  if (dp->inc < 1.0)
+  {
+    int j;
+
+    if (dp->val == (double)((int)dp->val))
+      strcat(foo,".");
+
+    for (j = strlen(foo); j < tot; j++)
+      strcat(foo,"0");
+  }
 
   if (dp->units) strcat(foo,dp->units);
   foo1[0] = '\0';
   if (strlen(foo) < (size_t) i) {
-    for (i = i - strlen(foo); i>0; i--) strcat(foo1," ");
+    for (i-=strlen(foo);i>0;i--) strcat(foo1," ");
   }
   strcat(foo1, foo);
 
@@ -411,12 +429,13 @@
 
 
 /***************************************************/
-static int computeDialVal(dp, x, y)
+static double computeDialVal(dp, x, y)
 DIAL *dp;
 int x, y;
 {
-  int dx, dy, val;
-  double angle;
+  int dx, dy;
+ 
+  double angle, val;
 
   /* compute dx, dy (distance from cx, cy).  Note: +dy is *up* */
   dx = x - dp->cx;  dy = dp->cy - y;
@@ -436,8 +455,10 @@
   if (angle > 270.0) angle -= 360.0;
   if (angle < -90.0) angle += 360.0;
 
-  val = (int) ((dp->max - dp->min) * (240.0 - angle) / 300.0) + dp->min;
+  val = ((dp->max - dp->min) * (240.0 - angle) / 300.0) + dp->min;
 
+  /* round value to be an even multiple of dp->inc */
+  val = (double)((int)(val / dp->inc + 0.5)) * dp->inc;
   return val;
 }
 
