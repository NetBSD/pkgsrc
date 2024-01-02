$NetBSD: patch-Dialog.c,v 1.1 2024/01/02 20:41:47 nros Exp $

Fix warning: cast to pointer from integer of different size.

--- Dialog.c.orig	2023-12-26 10:10:12.632499452 +0000
+++ Dialog.c
@@ -82,13 +82,15 @@
 extern void unsetKillfromWM();
 extern XtAppContext pixmap_context;
 
+static int okayyes = Okay | Yes;
 static int selected;
 
 static void SetSelected(w, client_data, call_data)
      Widget w;
      XtPointer client_data, call_data;
 {
-  selected = (int)client_data;
+  int *selectedP = (int*)client_data;
+  selected = *selectedP;
 }
 
 #ifdef USE_ATHENA
@@ -156,7 +158,7 @@ Dialog CreateDialog(top_widget, name, op
 		  XtAddCallback(XmSelectionBoxGetChild(popup->dialog_widget,
 						       XmDIALOG_OK_BUTTON),
 				XmNactivateCallback, SetSelected, 
-				(XtPointer)dialog_buttons[i].flag);
+				(XtPointer)&dialog_buttons[i].flag);
 		  XmStringFree(xmstr);
 		  break;
 		case No:
@@ -175,7 +177,7 @@ Dialog CreateDialog(top_widget, name, op
 		  XtAddCallback(XmSelectionBoxGetChild(popup->dialog_widget,
 						       XmDIALOG_APPLY_BUTTON),
 				XmNactivateCallback, SetSelected, 
-				(XtPointer)dialog_buttons[i].flag);
+				(XtPointer)&dialog_buttons[i].flag);
 		  XmStringFree(xmstr);
 		  break;
 		case Cancel:
@@ -195,7 +197,7 @@ Dialog CreateDialog(top_widget, name, op
 		  XtAddCallback(XmSelectionBoxGetChild(popup->dialog_widget,
 						       XmDIALOG_CANCEL_BUTTON),
 				XmNactivateCallback, SetSelected, 
-				(XtPointer)dialog_buttons[i].flag);
+				(XtPointer)&dialog_buttons[i].flag);
 		  XmStringFree(xmstr);
 		  break;
 		}
@@ -211,7 +213,7 @@ Dialog CreateDialog(top_widget, name, op
 	    if (options & dialog_buttons[i].flag)
 		XawDialogAddButton(popup->dialog_widget, 
 				   dialog_buttons[i].name, SetSelected, 
-                                   (XtPointer)dialog_buttons[i].flag);
+                                   (XtPointer)&dialog_buttons[i].flag);
 #endif /* USE_ATHENA */
 
 	popup->options = options;
@@ -263,7 +265,7 @@ int PopupDialog(popup, message, suggesti
                                                   XmDIALOG_TEXT),
                            XmNactivateCallback);
       XtAddCallback(XmSelectionBoxGetChild(popup->dialog_widget,XmDIALOG_TEXT),
-		    XmNactivateCallback, SetSelected, (XtPointer)(Okay | Yes));
+		    XmNactivateCallback, SetSelected, (XtPointer)&okayyes);
     }
   else XtUnmanageChild(XmSelectionBoxGetChild(popup->dialog_widget, 
 					      XmDIALOG_TEXT));
@@ -386,7 +388,7 @@ Dialog CreateFDialog(top_widget, name, o
 						       popup->dialog_widget,
 						       XmDIALOG_OK_BUTTON),
 				XmNactivateCallback, SetSelected, 
-				(XtPointer)dialog_buttons[i].flag);
+				(XtPointer)&dialog_buttons[i].flag);
 		  break;
 		case No:
 		  XtSetArg(wargs[0], XmNlabelString, 
@@ -407,7 +409,7 @@ Dialog CreateFDialog(top_widget, name, o
 						       popup->dialog_widget,
 						       XmDIALOG_HELP_BUTTON),
 				XmNactivateCallback, SetSelected, 
-				(XtPointer)dialog_buttons[i].flag);
+				(XtPointer)&dialog_buttons[i].flag);
 		  break;
 		case Cancel:
 		case Retry:
@@ -429,7 +431,7 @@ Dialog CreateFDialog(top_widget, name, o
 						      popup->dialog_widget,
 						      XmDIALOG_CANCEL_BUTTON),
 				XmNactivateCallback, SetSelected, 
-				(XtPointer)dialog_buttons[i].flag);
+				(XtPointer)&dialog_buttons[i].flag);
 		  break;
 		}
 #endif /* USE_ATHENA */
@@ -478,7 +480,7 @@ int PopupFDialog(popup, message, suggest
                            XmNactivateCallback);
       XtAddCallback(XmFileSelectionBoxGetChild(popup->dialog_widget,
 					       XmDIALOG_TEXT),
-		    XmNactivateCallback, SetSelected, (XtPointer)(Okay | Yes));
+		    XmNactivateCallback, SetSelected, (XtPointer)&okayyes);
     }
   else XtUnmanageChild(XmFileSelectionBoxGetChild(popup->dialog_widget, 
 					      XmDIALOG_TEXT));
