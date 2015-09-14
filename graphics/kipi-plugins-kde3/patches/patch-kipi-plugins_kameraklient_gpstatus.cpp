$NetBSD: patch-kipi-plugins_kameraklient_gpstatus.cpp,v 1.1 2015/09/14 13:31:54 joerg Exp $

--- kipi-plugins/kameraklient/gpstatus.cpp.orig	2015-09-13 16:09:58.000000000 +0000
+++ kipi-plugins/kameraklient/gpstatus.cpp
@@ -52,39 +52,21 @@ GPContextFeedback GPStatus::cancel_func(
     return (cancel ? GP_CONTEXT_FEEDBACK_CANCEL : GP_CONTEXT_FEEDBACK_OK);
 }
 
-void GPStatus::error_func(GPContext *, const char *format, va_list args, void *) {
-    char buf[4096] = "";
-    int nSize = vsnprintf( buf, 4096, format, args );
-    if(nSize > 4094) {
-	nSize = 4094;
-    }
-    buf[nSize] = '\0';
+void GPStatus::error_func(GPContext *, const char *text, void *) {
     QString error;
-    error = error.fromLocal8Bit(buf);
+    error = error.fromLocal8Bit(text);
     GPMessages::gpMessagesWrapper()->emit errorMessage(error);
 }
 
-void GPStatus::status_func (GPContext *, const char *format, va_list args, void *) {
-    char buf[4096] = "";
-    int nSize = vsnprintf( buf, 4096, format, args );
-    if(nSize > 4094) {
-	nSize = 4094;
-    }
-    buf[nSize] = '\0';
+void GPStatus::status_func (GPContext *, const char *text, void *) {
     QString status;
-    status = status.fromLocal8Bit(buf);
+    status = status.fromLocal8Bit(text);
     GPMessages::gpMessagesWrapper()->emit statusChanged(status);
 }
 
-unsigned int GPStatus::progress_start_func(GPContext *, float _target, const char *format, va_list args, void *) {
-    char buf[4096] = "";
-    int nSize = vsnprintf( buf, 4096, format, args );
-    if(nSize > 4094) {
-	nSize = 4094;
-    }
-    buf[nSize] = '\0';
+unsigned int GPStatus::progress_start_func(GPContext *, float _target, const char *text, void *) {
     QString prog;
-    prog = prog.fromLocal8Bit(buf);
+    prog = prog.fromLocal8Bit(text);
     target = _target;
     return GP_OK;
 }
