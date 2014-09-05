$NetBSD: patch-glib_gmessages.c,v 1.1 2014/09/05 20:49:55 prlw1 Exp $

PR pkg/48318
https://bugzilla.gnome.org/show_bug.cgi?id=720708

--- glib/gmessages.c.orig	2014-02-15 15:31:32.000000000 +0000
+++ glib/gmessages.c
@@ -1112,15 +1112,21 @@ g_assert_warning (const char *log_domain
 		  const char *pretty_function,
 		  const char *expression)
 {
-  g_log (log_domain,
-	 G_LOG_LEVEL_ERROR,
-	 expression 
-	 ? "file %s: line %d (%s): assertion failed: (%s)"
-	 : "file %s: line %d (%s): should not be reached",
-	 file, 
-	 line, 
-	 pretty_function,
-	 expression);
+  if (expression)
+    g_log (log_domain,
+	   G_LOG_LEVEL_ERROR,
+	   "file %s: line %d (%s): assertion failed: (%s)",
+	   file,
+	   line,
+	   pretty_function,
+	   expression);
+  else
+    g_log (log_domain,
+	   G_LOG_LEVEL_ERROR,
+	   "file %s: line %d (%s): should not be reached",
+	   file,
+	   line,
+	   pretty_function);
   _g_log_abort (FALSE);
   abort ();
 }
