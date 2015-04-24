$NetBSD: patch-Include_pyerrors.h,v 1.2 2015/04/24 03:01:36 rodent Exp $

* from cygport 2.6.5-export-PySignal_SetWakeupFd.patch

--- Include/pyerrors.h.orig	2014-12-10 15:59:32.000000000 +0000
+++ Include/pyerrors.h
@@ -231,7 +231,7 @@ PyAPI_FUNC(int) PyErr_CheckSignals(void)
 PyAPI_FUNC(void) PyErr_SetInterrupt(void);
 
 /* In signalmodule.c */
-int PySignal_SetWakeupFd(int fd);
+PyAPI_FUNC(int) PySignal_SetWakeupFd(int fd);
 
 /* Support for adding program text to SyntaxErrors */
 PyAPI_FUNC(void) PyErr_SyntaxLocation(const char *, int);
