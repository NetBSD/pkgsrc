$NetBSD: patch-tnm_generic_tnmInt.h,v 1.1 2014/03/05 13:52:29 he Exp $

Make own TnmCreateDirectory.
Constify.

--- tnm/generic/tnmInt.h.orig	1999-03-23 18:08:59.000000000 +0100
+++ tnm/generic/tnmInt.h	2014-03-05 09:22:28.000000000 +0100
@@ -36,7 +36,6 @@
 #define TnmGetTime TclpGetTime
 #endif
 
-#define TnmCreateDirectory	TclpCreateDirectory
 #if TCL_MAJOR_VERSION == 8 && TCL_MINOR_VERSION == 8 && TCL_RELEASE_SERIAL > 2 
 #define TnmStat			TclStat
 #else
@@ -54,7 +53,7 @@
 TclpGetTime		_ANSI_ARGS_((Tcl_Time *timePtr));
 
 EXTERN int
-TnmCreateDirectory	_ANSI_ARGS_((char *path));
+TnmCreateDirectory	_ANSI_ARGS_((const char *path));
 
 EXTERN int
 TnmStat			_ANSI_ARGS_((CONST char *path, struct stat *buf));
@@ -93,7 +92,7 @@
 TnmGetTableValue	_ANSI_ARGS_((TnmTable *table, unsigned key));
 
 EXTERN int
-TnmGetTableKey		_ANSI_ARGS_((TnmTable *table, char *value));
+TnmGetTableKey		_ANSI_ARGS_((TnmTable *table, const char *value));
 
 EXTERN char *
 TnmGetTableValues	_ANSI_ARGS_((TnmTable *table));
@@ -106,10 +105,10 @@
  *----------------------------------------------------------------
  */
 
-typedef char * (TnmGetConfigProc) _ANSI_ARGS_((Tcl_Interp *interp,
+typedef const char * (TnmGetConfigProc) _ANSI_ARGS_((Tcl_Interp *interp,
         ClientData clientData, int option));
 typedef int (TnmSetConfigProc) _ANSI_ARGS_((Tcl_Interp *interp,
-        ClientData clientData, int option, char *value));
+        ClientData clientData, int option, const char *value));
 
 typedef struct TnmConfig {
     TnmTable *optionTable;
@@ -119,10 +118,12 @@
 
 EXTERN int
 TnmSetConfig		_ANSI_ARGS_((Tcl_Interp *interp, TnmConfig *config,
-				     ClientData obj, int argc, char **argv));
+				     ClientData obj, int argc,
+				     const char **argv));
 EXTERN int
 TnmGetConfig		_ANSI_ARGS_((Tcl_Interp *interp, TnmConfig *config,
-				     ClientData obj, int argc, char **argv));
+				     ClientData obj, int argc,
+				     const char **argv));
 
 /*
  *----------------------------------------------------------------
@@ -132,28 +133,29 @@
  */
 
 EXTERN int 
-TnmGetUnsigned		_ANSI_ARGS_((Tcl_Interp *interp, char *string,
+TnmGetUnsigned		_ANSI_ARGS_((Tcl_Interp *interp, const char *string,
 				     int *intPtr));
 EXTERN int 
-TnmGetPositive		_ANSI_ARGS_((Tcl_Interp *interp, char *string,
+TnmGetPositive		_ANSI_ARGS_((Tcl_Interp *interp, const char *string,
 				     int *intPtr));
 EXTERN int
-TnmSetIPAddress		_ANSI_ARGS_((Tcl_Interp *interp, char *name,
+TnmSetIPAddress		_ANSI_ARGS_((Tcl_Interp *interp, const char *name,
 				     struct sockaddr_in *addr));
 EXTERN char *
 TnmGetIPName		_ANSI_ARGS_((Tcl_Interp *interp,
 				     struct sockaddr_in *addr));
 EXTERN int
-TnmSetIPPort		_ANSI_ARGS_((Tcl_Interp *interp, char *protocol,
-				     char *port, struct sockaddr_in *addr));
+TnmSetIPPort		_ANSI_ARGS_((Tcl_Interp *interp, const char *protocol,
+				     const char *port,
+				     struct sockaddr_in *addr));
 EXTERN char *
-TnmGetIPPort		_ANSI_ARGS_((Tcl_Interp *interp, char *protocol,
+TnmGetIPPort		_ANSI_ARGS_((Tcl_Interp *interp, const char *protocol,
 				     struct sockaddr_in *addr));
 EXTERN int
-TnmValidateIpHostName	_ANSI_ARGS_((Tcl_Interp *interp, char *name));
+TnmValidateIpHostName	_ANSI_ARGS_((Tcl_Interp *interp, const char *name));
 
 EXTERN int
-TnmValidateIpAddress	_ANSI_ARGS_((Tcl_Interp *interp, char *address));
+TnmValidateIpAddress	_ANSI_ARGS_((Tcl_Interp *interp, const char *address));
 
 /*
  *----------------------------------------------------------------
@@ -175,10 +177,10 @@
 
 EXTERN int 
 TnmWriteLogMessage	_ANSI_ARGS_((Tcl_Interp *interp, int level,
-				     char *message));
+				     const char *message));
 
 EXTERN void
-TnmWriteMessage		_ANSI_ARGS_((Tcl_Interp *interp, char *msg));
+TnmWriteMessage		_ANSI_ARGS_((Tcl_Interp *interp, const char *msg));
 
 /*
  *----------------------------------------------------------------
@@ -215,7 +217,7 @@
     int delay;			/* The delay value (ms) for this request. */
     int size;			/* The size of the ICMP packet. */
     int argc;			/* The number of targets for this request. */
-    char **argv;		/* The names of the targets. */
+    const char **argv;		/* The names of the targets. */
     TnmIcmpTarget *targets;	/* The vector of targets. */
     struct TnmIcmpRequest *nextPtr;	/* Next queued request. */
 } TnmIcmpRequest;
@@ -242,7 +244,7 @@
 TnmSocketBind		_ANSI_ARGS_((int s, struct sockaddr *name,
 				     int namelen));
 EXTERN int
-TnmSocketSendTo		_ANSI_ARGS_((int s, char *buf, int len, int flags,
+TnmSocketSendTo		_ANSI_ARGS_((int s, const char *buf, int len, int flags,
 				     struct sockaddr *to, int tolen));
 EXTERN int
 TnmSocketRecvFrom	_ANSI_ARGS_((int s, char *buf, int len, int flags,
