$NetBSD: patch-src_FmFwCb.c,v 1.1 2025/04/11 01:49:11 nia Exp $

64-bit support.

--- src/FmFwCb.c.orig	2025-04-11 00:12:39.255422476 +0000
+++ src/FmFwCb.c
@@ -31,7 +31,7 @@ typedef struct
 void fileEditCb(Widget w, XtPointer client_data, XtPointer call_data)
 {
  FileWindowRec *fw = (FileWindowRec *) client_data;
- int item;
+ long item;
 
  XtVaGetValues(fw->form, XmNuserData, (XtPointer) &item, NULL);
  doEdit(fw->directory, fw->files[item]->name);
@@ -44,7 +44,7 @@ void fileExecCb(Widget w, XtPointer clie
  FileWindowRec *fw = (FileWindowRec *) client_data;
  ExecFileRec *data = (ExecFileRec *) XtMalloc(sizeof(ExecFileRec));
  TextFieldRec argLine[2];
- int item;
+ long item;
 
  XtVaGetValues(fw->form, XmNuserData, (XtPointer) &item, NULL);
  data->directory = XtNewString(fw->directory);
@@ -86,7 +86,7 @@ void commandCb(Widget w, XtPointer clien
  FileWindowRec *fw = (FileWindowRec *) client_data;
  ExecFileRec *data = (ExecFileRec *) XtMalloc(sizeof(ExecFileRec));
  TextFieldRec actionLine[2];
- int item;
+ long item;
 
  XtVaGetValues(fw->form, XmNuserData, (XtPointer) &item, NULL);
  data->directory = XtNewString(fw->directory);
@@ -104,7 +104,7 @@ void commandCb(Widget w, XtPointer clien
 void fileViewCb(Widget w, XtPointer client_data, XtPointer call_data)
 {
  FileWindowRec *fw = (FileWindowRec *) client_data;
- int item;
+ long item;
 
  XtVaGetValues(fw->form, XmNuserData, (XtPointer) &item, NULL);
  doView(fw->directory, fw->files[item]->name);
@@ -159,7 +159,7 @@ void dirOpenCb(Widget w, XtPointer clien
 {
  FileWindowRec *fw = (FileWindowRec *) client_data;
  char path[MAXPATHLEN];
- int item;
+ long item;
 
  zzz();
  XtVaGetValues(fw->form, XmNuserData, (XtPointer) &item, NULL);
