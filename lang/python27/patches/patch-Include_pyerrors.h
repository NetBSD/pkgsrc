$NetBSD: patch-Include_pyerrors.h,v 1.1 2013/04/17 13:21:05 obache Exp $

* from cygport 2.6.5-export-PySignal_SetWakeupFd.patch

--- Include/pyerrors.h.orig	2013-04-06 14:02:25.000000000 +0000
+++ Include/pyerrors.h
@@ -231,7 +231,7 @@ PyAPI_FUNC(int) PyErr_CheckSignals(void)
 PyAPI_FUNC(void) PyErr_SetInterrupt(void);
 
 /* In signalmodule.c */
-int PySignal_SetWakeupFd(int fd);
+PyAPI_FUNC(int) PySignal_SetWakeupFd(int fd);
 
 /* Support for adding program text to SyntaxErrors */
 PyAPI_FUNC(void) PyErr_SyntaxLocation(const char *, int);
