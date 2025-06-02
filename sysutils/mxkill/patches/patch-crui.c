$NetBSD: patch-crui.c,v 1.1 2025/06/02 11:16:24 vins Exp $

* Silence size mismatch warnings.
* The first argument of XtRealloc() is of type char *.

--- crui.c.orig	1997-08-30 18:08:54.000000000 +0000
+++ crui.c
@@ -35,6 +35,8 @@
  *      muquit@semcor.com   04-Sep-95   first cut
  */
 
+#include <stdint.h>
+
 #include "xhead.h"
 #include "mxkill.h"
 #include "menu.h"
@@ -468,7 +470,7 @@ XtPointer
     call_data;
 {
     int
-        sig_no=(int) client_data;
+        sig_no=(intptr_t) client_data;
     register int
         i;
 
@@ -814,7 +816,7 @@ XtPointer
         matched=re_exec(text) > 0;
         if(matched)
         {
-            selectlist=(XmString *) XtRealloc((XmString *) selectlist,
+            selectlist=(XmString *) XtRealloc((char *) selectlist,
                 (j+1)*(sizeof(XmString *)));
 
             selectlist[j++]=XmStringCopy(strlist[cnt]);
@@ -856,7 +858,7 @@ XtPointer
     client_data,
     call_data;
 {
-    switch((int) client_data)
+    switch((intptr_t) client_data)
     {
         case 0:
         {
