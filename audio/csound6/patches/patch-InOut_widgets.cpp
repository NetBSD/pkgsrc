$NetBSD: patch-InOut_widgets.cpp,v 1.3 2019/11/02 22:25:46 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- InOut/widgets.cpp.orig	2019-07-12 14:54:19.000000000 -0700
+++ InOut/widgets.cpp	2019-10-29 13:41:51.455962617 -0700
@@ -2101,7 +2101,7 @@
         (WIDGET_GLOBALS *)csound->QueryGlobalVariable(csound, "WIDGET_GLOBALS");
       p = (widgetsGlobals_t*) csound->QueryGlobalVariable(csound,
                                                           "_widgets_globals");
-#ifdef LINUX
+#if defined(LINUX) || defined(__NetBSD__) || defined(__DragonFly__)
       {
         struct sched_param  sp;
         // IV - Aug 27 2002: widget thread is always run with normal priority
@@ -2121,7 +2121,7 @@
 // #ifdef WIN32
 //         HWND xid = fl_xid(widgetGlobals->fl_windows[panelNum].panel);
 //         widgetGlobals->VSTplugEditors[k]->SetEditWindow(xid);
-// #elif defined (LINUX) || defined(MACOSX)
+// #elif defined (LINUX) || defined(MACOSX) || defined(__NetBSD__) || defined(__DragonFly__)
 //         // put some appropriate alternative code here
 //         Fl_Window * xid =
 //           fl_find(fl_xid(widgetGlobals->fl_windows[panelNum].panel));
@@ -2258,8 +2258,7 @@
     CSOUND *csound = p->csound;
     char *command = (char *)csound->Malloc(csound, strlen(p->commandString) + 1);
 
-#if defined(LINUX) || defined (MACOSX)
-
+#if defined(LINUX) || defined (MACOSX) || defined(__NetBSD__) || defined(__DragonFly__)
 
     pid_t pId = vfork();
     if (pId == 0) {
