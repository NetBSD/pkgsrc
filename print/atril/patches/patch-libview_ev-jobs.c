$NetBSD: patch-libview_ev-jobs.c,v 1.1 2018/05/16 14:18:11 jperkin Exp $

Pull in upstream fix for non-epub build.

--- libview/ev-jobs.c.orig	2018-03-22 15:13:28.000000000 +0000
+++ libview/ev-jobs.c
@@ -876,8 +876,6 @@ snapshot_callback(WebKitWebView *webview
 	gtk_widget_destroy (gtk_widget_get_toplevel (GTK_WIDGET (webview)));
 }
 
-#endif  /* ENABLE_EPUB */
-
 static void
 web_thumbnail_get_screenshot_cb (WebKitWebView  *webview,
                                  WebKitLoadEvent event,
@@ -910,6 +908,8 @@ webview_load_failed_cb (WebKitWebView  *
 	return TRUE;
 }
 
+#endif  /* ENABLE_EPUB */
+
 static gboolean
 ev_job_thumbnail_run (EvJob *job)
 {
