$NetBSD: patch-dvistuff.c,v 1.1 2011/09/29 18:20:13 wiz Exp $

Fix conflict with POSIX getline().

--- dvistuff.c.orig	2011-09-29 18:17:16.000000000 +0000
+++ dvistuff.c
@@ -162,7 +162,7 @@ void            rule            (bool, l
 void            ruleaux         (long, long, char);
 long            horizontalmove  (long);
 int             skipnops        (void);
-linetype    *   getline         (void);
+linetype    *   get_line         (void);
 linetype    *   findline        (void);
 unsigned long   num             (int);
 long            snum            (int);
@@ -188,7 +188,7 @@ void            rule            ();
 void            ruleaux         ();
 long            horizontalmove  ();
 int             skipnops        ();
-linetype    *   getline         ();
+linetype    *   get_line         ();
 linetype    *   findline        ();
 unsigned long   num             ();
 long            snum            ();
@@ -347,7 +347,7 @@ void initpage()
     h = 0L;  v = 0L;                        /* initialize coordinates   */
     x = 0L;  w = 0L;  y = 0L;  z = 0L;      /* initialize amounts       */
     sptr = 0;                               /* initialize stack         */
-    currentline = getline();                /* initialize list of lines */
+    currentline = get_line();                /* initialize list of lines */
     currentline->vv = 0L;
     firstline   = currentline;
     lastline    = currentline;
@@ -810,7 +810,7 @@ int skipnops()
  * GETLINE -- Returns an initialized line-object 
  */
 
-linetype *getline()
+linetype *get_line()
 {
     register int  i;
     register linetype *temp;
@@ -826,7 +826,7 @@ linetype *getline()
 
     return temp;
 
-} /* getline */
+} /* get_line */
 
 
 
@@ -842,7 +842,7 @@ linetype *findline()
 
     if (v <= firstline->vv) {                      /* above first line */
         if (firstline->vv - v > lineheight) {
-            temp = getline();
+            temp = get_line();
             temp->next = firstline;
             firstline->prev = temp;
             temp->vv = v;
@@ -853,7 +853,7 @@ linetype *findline()
 
     if (v >= lastline->vv) {                       /* below last line */
         if (v - lastline->vv > lineheight) {
-            temp = getline();
+            temp = get_line();
             temp->prev = lastline;
             lastline->next = temp;
             temp->vv = v;
@@ -876,7 +876,7 @@ linetype *findline()
             return temp->next;
 
     /* no line fits suitable, generate a new one */
-    currentline = getline();
+    currentline = get_line();
     currentline->next = temp->next;
     currentline->prev = temp;
     temp->next->prev = currentline;
