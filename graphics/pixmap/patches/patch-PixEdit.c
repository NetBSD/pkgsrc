$NetBSD: patch-PixEdit.c,v 1.1 2024/01/02 20:41:47 nros Exp $

Fix implicit function declaration of:
atoi
getenv
exit
XmCreateTextField
XmCreatePanedWindow
XmCreatePushButton
XmCreateScrollBar
XmCreateScrolledText
XmCreateScrolledWindow
XmCreateScrolledWindowSetAreas
XmTextFieldGetString
XmTextGetString
XmTextSetString

--- PixEdit.c.orig	2024-01-02 10:28:23.893459197 +0000
+++ PixEdit.c
@@ -59,6 +59,7 @@ static char rcsid[] = "$Id: PixEdit.c,v 
 
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <X11/Intrinsic.h>
 #include <X11/Xos.h>
 #include <X11/Xfuncs.h>
@@ -68,6 +69,8 @@ static char rcsid[] = "$Id: PixEdit.c,v 
 #ifndef USE_ATHENA
 #include <Xm/Xm.h>
 #include <Xm/RowColumn.h>
+#include <Xm/PanedW.h>
+#include <Xm/PushB.h>
 #include <Xm/PushBG.h>
 #include <Xm/SeparatoG.h>
 #include <Xm/ToggleBG.h>
@@ -75,6 +78,10 @@ static char rcsid[] = "$Id: PixEdit.c,v 
 #include <Xm/Form.h>
 #include <Xm/Label.h>
 #include <Xm/LabelG.h>
+#include <Xm/ScrollBar.h>
+#include <Xm/ScrolledW.h>
+#include <Xm/Text.h>
+#include <Xm/TextF.h>
 #ifndef NO_EDITRES
 #include <X11/Xmu/Editres.h>
 #endif /* NO_EDITRES */
