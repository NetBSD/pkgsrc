$NetBSD: patch-src_linc.c,v 1.1 2013/05/25 23:45:34 joerg Exp $

--- src/linc.c.orig	2013-05-25 17:31:27.000000000 +0000
+++ src/linc.c
@@ -182,15 +182,9 @@ linc_io_thread_fn (gpointer data)
 void
 linc_init (gboolean init_threads)
 {
-	if ((init_threads || linc_threaded) &&
-	    !g_thread_supported ())
-		g_thread_init (NULL);
-
 	if (!linc_threaded && init_threads)
 		linc_threaded = TRUE;
 
-	g_type_init ();
-
 	/*
 	 * Linc's raison d'etre is for ORBit2 and Bonobo
 	 *
@@ -246,8 +240,6 @@ linc_init (gboolean init_threads)
 	linc_lifecycle_mutex = linc_mutex_new ();
 
 	if (init_threads) {
-		GError *error = NULL;
-
 		if (pipe (linc_wakeup_fds) < 0) /* cf. g_main_context_init_pipe */
 			g_error ("Can't create CORBA main-thread wakeup pipe");
 
@@ -256,11 +248,9 @@ linc_init (gboolean init_threads)
 			 NULL, (G_IO_IN | G_IO_PRI),
 			 linc_mainloop_handle_input, NULL);
 
-		linc_io_thread = g_thread_create_full
-			(linc_io_thread_fn, NULL, 0, TRUE, FALSE,
-			 G_THREAD_PRIORITY_NORMAL, &error);
+		linc_io_thread = g_thread_new("io", linc_io_thread_fn, NULL);
 
-		if (!linc_io_thread || error)
+		if (!linc_io_thread)
 			g_error ("Failed to create linc worker thread");
 	}
 }
@@ -317,7 +307,7 @@ linc_mutex_new (void)
 	linc_mutex_new_called = TRUE;
 
 #ifdef G_THREADS_ENABLED
-	if (linc_threaded && g_thread_supported ())
+	if (linc_threaded)
 		return g_mutex_new ();
 #endif
 
