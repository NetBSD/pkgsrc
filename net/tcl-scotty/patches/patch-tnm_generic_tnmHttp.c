$NetBSD: patch-tnm_generic_tnmHttp.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/generic/tnmHttp.c.orig	1999-04-06 11:13:31.000000000 +0200
+++ tnm/generic/tnmHttp.c	2014-03-04 18:01:45.000000000 +0100
@@ -169,20 +169,21 @@
  */
 
 static char*
-Base64Encode		_ANSI_ARGS_((char *string));
+Base64Encode		_ANSI_ARGS_((const char *string));
 
 static char*
-Base64Decode		_ANSI_ARGS_((char *string));
+Base64Decode		_ANSI_ARGS_((const char *string));
 
 static int
-HttpGetPort		_ANSI_ARGS_((char *name));
+HttpGetPort		_ANSI_ARGS_((const char *name));
 
 static HttpUrl*
-HttpSplitUrl		_ANSI_ARGS_((char *str));
+HttpSplitUrl		_ANSI_ARGS_((const char *str));
 
 static void
 HttpRequestLine		_ANSI_ARGS_((Tcl_Channel channel,
-				     char *method, char *path));
+				     const char *method,
+				     const char *path));
 static void
 HttpStatusLine		_ANSI_ARGS_((Tcl_Channel channel, int code));
 
@@ -213,7 +214,7 @@
 HttpEvalCallback	_ANSI_ARGS_((Tcl_Interp *interp, char *callback,
 				     char *addr, char *url));
 static Tcl_Channel
-HttpOpen		_ANSI_ARGS_((char *fileName, char **contentType, 
+HttpOpen		_ANSI_ARGS_((const char *fileName, char **contentType, 
 				     char **contentEncoding, 
 				     int *contentLength));
 static void
@@ -228,31 +229,31 @@
 				     Tcl_Channel dst));
 static int
 HttpProxy		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 HttpHead		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 HttpGet			_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 HttpPost		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 HttpPut			_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 HttpDelete		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 HttpServer		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 HttpBind		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 static int
 HttpMime		_ANSI_ARGS_((Tcl_Interp *interp, 
-				     int argc, char **argv));
+				     int argc, const char **argv));
 /*
  * The following defines are used to implement base64 en/decoding.
  * See RFC 1521 for a description of base64 en/decoding.
@@ -294,7 +295,7 @@
 
 static char *
 Base64Encode(in)
-    char *in;
+    const char *in;
 {
     static char *ret = NULL;
     static int size = 0;
@@ -374,7 +375,7 @@
 
 static char *
 Base64Decode(in)  
-    char *in;
+    const char *in;
 {
     static char *ret = NULL;
     static int size = 0;
@@ -448,7 +449,7 @@
 
 static int
 HttpGetPort(name)
-    char *name;
+    const char *name;
 {
     struct sockaddr_in addr;
 
@@ -479,7 +480,7 @@
 
 static HttpUrl*
 HttpSplitUrl(str)
-    char *str;
+    const char *str;
 {
     static HttpUrl url = { 0, 0, 0, 0 };
     char *hbuf;
@@ -595,8 +596,8 @@
 static void
 HttpRequestLine(channel, method, path)
     Tcl_Channel channel;
-    char *method;
-    char *path;
+    const char *method;
+    const char *path;
 {
     Tcl_Write(channel, method, strlen(method));
     Tcl_Write(channel, " ", 1);
@@ -973,7 +974,7 @@
     Tcl_DStringFree(&tclCmd);
 
     if (code == TCL_ERROR) {
-	char *errorMsg = ckstrdup(interp->result);
+	char *errorMsg = ckstrdup(Tcl_GetStringResult(interp));
 	Tcl_AddErrorInfo(interp, "\n    (http callback)");
         Tcl_BackgroundError(interp);
 	Tcl_SetResult(interp, errorMsg, TCL_DYNAMIC);
@@ -1005,14 +1006,14 @@
 
 static Tcl_Channel
 HttpOpen(fileName, contentType, contentEncoding, contentLength)
-    char *fileName;
+    const char *fileName;
     char **contentType;
     char **contentEncoding;
     int *contentLength;
 {
     Tcl_Channel channel;
     struct stat st;
-    char *dot = NULL;
+    char *dot = NULL, *fn;
     int n;
 
     channel = Tcl_OpenFileChannel(NULL, fileName, "r", 0644);
@@ -1033,21 +1034,22 @@
      * x-compress and x-gzip encoding. This is a quick hack.
      */
     
-    for (n = strlen(fileName) - 1; n >= 0; n--) {
-	if (fileName[n] == '.' && *contentEncoding == NULL) {
-	    if (strcmp(fileName+n, ".gz") == 0) {
+    fn = ckstrdup(fileName);
+    for (n = strlen(fn) - 1; n >= 0; n--) {
+	if (fn[n] == '.' && *contentEncoding == NULL) {
+	    if (strcmp(fn+n, ".gz") == 0) {
 		*contentEncoding = "x-gzip";
-		dot = fileName + n;
+		dot = fn + n;
 		*dot = '\0';
-	    } else if (strcmp(fileName+n, ".Z") == 0) {
+	    } else if (strcmp(fn+n, ".Z") == 0) {
 		*contentEncoding = "x-compress";
-		dot = fileName + n;
+		dot = fn + n;
                 *dot = '\0';
 	    }
 	}
-	if (fileName[n] == '.') {
+	if (fn[n] == '.') {
 	    Tcl_HashEntry *entryPtr;
-	    entryPtr = Tcl_FindHashEntry(&mimeTypeTable, fileName+n+1);
+	    entryPtr = Tcl_FindHashEntry(&mimeTypeTable, fn+n+1);
 	    if (entryPtr) {
 		*contentType = (char *) Tcl_GetHashValue(entryPtr);
 	    }
@@ -1061,6 +1063,7 @@
     if (! *contentType) {
 	*contentType = "text/plain";
     }
+    ckfree(fn);
 
     return channel;
 }
@@ -1165,7 +1168,7 @@
     if (rc == TCL_OK) {
 	char *contentType, *contentEncoding;
 	int contentLength;
-	Tcl_Channel obj = HttpOpen(interp->result, &contentType, 
+	Tcl_Channel obj = HttpOpen(Tcl_GetStringResult(interp), &contentType,
 				   &contentEncoding, &contentLength);
 	if (obj) {
 	    HttpStatusLine(channel, HTTP_OK);
@@ -1179,7 +1182,7 @@
 	    HttpSendError(channel, HTTP_INTERNAL);
 	}
     } else {
-	int code = TnmGetTableKey(httpStatusTable, interp->result);
+	int code = TnmGetTableKey(httpStatusTable, Tcl_GetStringResult(interp));
 	HttpSendError(channel, (code < 0) ? HTTP_INTERNAL : code);
     }
     
@@ -1362,7 +1365,7 @@
 HttpProxy(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     if (argc < 2 && argc > 3) {
 	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
@@ -1419,7 +1422,7 @@
 HttpHead(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_Channel src;
     HttpUrl *url;
@@ -1469,7 +1472,7 @@
 HttpGet(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_Channel src, dst;
     HttpUrl *url;
@@ -1530,7 +1533,7 @@
 HttpPost(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_Channel src, dst, obj;
     HttpUrl *url;
@@ -1603,7 +1606,7 @@
 HttpPut(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_Channel src, obj;
     HttpUrl *url;
@@ -1665,7 +1668,7 @@
 HttpDelete(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_Channel src;
     HttpUrl *url;
@@ -1717,10 +1720,11 @@
 HttpServer(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     static int port = -1;
     static Tcl_Channel channel;
+    char res[20];
 
     if (argc < 2 && argc > 3) {
 	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0],
@@ -1730,7 +1734,8 @@
 
     if (argc == 2) {
 	if (port > 0) {
-	    sprintf(interp->result, "%d", port);
+	    sprintf(res, "%d", port);
+	    Tcl_SetResult(interp, res, TCL_VOLATILE);
 	}
 	return TCL_OK;
     }
@@ -1762,7 +1767,8 @@
 	return TCL_ERROR;
     }
 
-    sprintf(interp->result, "%d", port);
+    sprintf(res, "%d", port);
+    Tcl_SetResult(interp, res, TCL_VOLATILE);
     return TCL_OK;
 }
 
@@ -1788,7 +1794,7 @@
 HttpBind(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int eventType = 0;
     HttpBinding *bindPtr;
@@ -1878,7 +1884,7 @@
 HttpMime(interp, argc, argv)
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     Tcl_HashTable *tablePtr = &mimeTypeTable;
     Tcl_HashEntry *entryPtr;
@@ -1934,7 +1940,7 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     static int initialized = 0;
     char c;
