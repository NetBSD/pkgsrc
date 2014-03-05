$NetBSD: patch-tnm_generic_tnmUtil.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.
Implement TnmCreateDirectory.

--- tnm/generic/tnmUtil.c.orig	1999-03-08 08:42:26.000000000 +0000
+++ tnm/generic/tnmUtil.c
@@ -70,7 +70,7 @@ TnmGetTableValue(table, key)
 int
 TnmGetTableKey(table, value)
     TnmTable *table;
-    char *value;
+    const char *value;
 {
     TnmTable *elemPtr;
 
@@ -188,7 +188,7 @@ TnmSetConfig(interp, config, object, arg
     TnmConfig *config;
     ClientData object;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int i, option, code;
     TnmTable *elemPtr;
@@ -274,7 +274,7 @@ TnmGetConfig(interp, config, object, arg
     TnmConfig *config;
     ClientData object;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int option;
     char *value;
@@ -326,7 +326,7 @@ TnmGetConfig(interp, config, object, arg
 int
 TnmGetUnsigned(interp, string, intPtr)
     Tcl_Interp *interp;
-    char *string;
+    const char *string;
     int *intPtr;
 {
     if (Tcl_GetInt(interp, string, intPtr) != TCL_OK) {
@@ -361,7 +361,7 @@ TnmGetUnsigned(interp, string, intPtr)
 int
 TnmGetPositive(interp, string, intPtr)
     Tcl_Interp *interp;
-    char *string;
+    const char *string;
     int *intPtr;
 {
     if (Tcl_GetInt(interp, string, intPtr) != TCL_OK) {
@@ -400,7 +400,7 @@ TnmGetPositive(interp, string, intPtr)
 int
 TnmSetIPAddress(interp, host, addr)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
     struct sockaddr_in *addr;
 {
     static Tcl_HashTable *hostTable = NULL;
@@ -585,8 +585,8 @@ TnmGetIPName(interp, addr)
 int
 TnmSetIPPort(interp, protocol, port, addr)
     Tcl_Interp *interp;
-    char *protocol;
-    char *port;
+    const char *protocol;
+    const char *port;
     struct sockaddr_in* addr;
 {
     if (strcmp(protocol, "udp") != 0 && strcmp(protocol, "tcp") != 0) {
@@ -642,7 +642,7 @@ TnmSetIPPort(interp, protocol, port, add
 char *
 TnmGetIPPort(interp, protocol, addr)
     Tcl_Interp *interp;
-    char *protocol;
+    const char *protocol;
     struct sockaddr_in *addr;
 {
     struct servent *serv;
@@ -697,9 +697,10 @@ TnmGetIPPort(interp, protocol, addr)
 int
 TnmValidateIpHostName(interp, name)
     Tcl_Interp *interp;
-    char *name;
+    const char *name;
 {
-    char *p = name, last = ' ';
+    const char *p = name;
+    char last = ' ';
     int dots = 0, alpha = 0;
 
     /*
@@ -757,9 +758,9 @@ TnmValidateIpHostName(interp, name)
 int
 TnmValidateIpAddress(interp, address)
     Tcl_Interp *interp;
-    char *address;
+    const char *address;
 {
-    char *p = address;
+    const char *p = address;
     unsigned dots = 0, a;
 
     dots = 0;
@@ -811,7 +812,7 @@ TnmValidateIpAddress(interp, address)
 void
 TnmWriteMessage(interp, msg)
     Tcl_Interp *interp;
-    char *msg;
+    const char *msg;
 {
     Tcl_DString buffer;
     Tcl_Channel channel;
@@ -833,6 +834,34 @@ TnmWriteMessage(interp, msg)
 /*
  *----------------------------------------------------------------------
  *
+ * TnmCreateDirectory --
+ *
+ *	This procedure creates a directory.  The parent must already
+ *	exist.
+ *
+ * Results:
+ *	A standard Tcl result.
+ *
+ * Side effects:
+ *	Creates a directory in the file system.
+ *
+ *----------------------------------------------------------------------
+ */
+int
+TnmCreateDirectory(path)
+    const char *path;
+{
+    Tcl_Obj *po = Tcl_NewStringObj(path, -1);
+    Tcl_IncrRefCount(po);
+    int s = Tcl_FSCreateDirectory(po);
+    Tcl_DecrRefCount(po);
+    return s;
+}
+
+
+/*
+ *----------------------------------------------------------------------
+ *
  * TnmMkDir --
  *
  *	This procedure creates a path of directories. This is largely
@@ -854,7 +883,8 @@ TnmMkDir(interp, pathname)
 {
     Tcl_DString nameBuffer, targetBuffer;
     int result, j, pargc;
-    char *name, **pargv;
+    char *name;
+    const char **pargv;
     struct stat statBuf;
     
     pargv = NULL;
