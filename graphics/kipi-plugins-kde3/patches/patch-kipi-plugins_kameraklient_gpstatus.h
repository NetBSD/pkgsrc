$NetBSD: patch-kipi-plugins_kameraklient_gpstatus.h,v 1.1 2015/09/14 13:31:54 joerg Exp $

--- kipi-plugins/kameraklient/gpstatus.h.orig	2015-09-13 16:11:11.000000000 +0000
+++ kipi-plugins/kameraklient/gpstatus.h
@@ -48,9 +48,9 @@ class GPStatus : public QObject {
 
     private:
 	static GPContextFeedback cancel_func(GPContext *context, void *data);
-	static void error_func(GPContext *context, const char *format,  va_list args, void *data);
-	static void status_func(GPContext *context, const char *format, va_list args, void *data);
-	static unsigned int progress_start_func (GPContext *context, float target, const char *format, va_list args, void *data);
+	static void error_func(GPContext *context, const char *text, void *data);
+	static void status_func(GPContext *context, const char *text, void *data);
+	static unsigned int progress_start_func (GPContext *context, float target, const char *text, void *data);
 	static void progress_update_func (GPContext *context, unsigned int id, float current, void *data);
 	static void progress_stop_func(GPContext *context, unsigned int id, void *data);
 	static float target;
