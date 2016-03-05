$NetBSD: patch-src_keyboard.c,v 1.1 2016/03/05 15:31:45 gson Exp $

Don't call printf from a signal handler.  Fixes emacs bug#22790.
Changes back-ported from emacs-25.0.92.

--- src/keyboard.c.orig	2015-04-02 07:23:06.000000000 +0000
+++ src/keyboard.c
@@ -10295,6 +10295,21 @@ deliver_interrupt_signal (int sig)
   deliver_process_signal (sig, handle_interrupt_signal);
 }
 
+/* Output MSG directly to standard output, without buffering.  Ignore
+   failures.  This is safe in a signal handler.  */
+static void
+write_stdout (char const *msg)
+{
+  (void) (write (STDOUT_FILENO, msg, strlen (msg)));
+}
+
+/* Read a byte from stdin, without buffering.  Safe in signal handlers.  */
+static int
+read_stdin (void)
+{
+  char c;
+  return read (STDIN_FILENO, &c, 1) == 1 ? c : EOF;
+}
 
 /* If Emacs is stuck because `inhibit-quit' is true, then keep track
    of the number of times C-g has been requested.  If C-g is pressed
@@ -10331,9 +10346,9 @@ handle_interrupt (bool in_signal_handler
 	  sigemptyset (&blocked);
 	  sigaddset (&blocked, SIGINT);
 	  pthread_sigmask (SIG_BLOCK, &blocked, 0);
+          fflush (stdout);
 	}
 
-      fflush (stdout);
       reset_all_sys_modes ();
 
 #ifdef SIGTSTP
@@ -10349,8 +10364,9 @@ handle_interrupt (bool in_signal_handler
       /* Perhaps should really fork an inferior shell?
 	 But that would not provide any way to get back
 	 to the original shell, ever.  */
-      printf ("No support for stopping a process on this operating system;\n");
-      printf ("you can continue or abort.\n");
+      write_stdout ("No support for stopping a process"
+		    " on this operating system;\n"
+		    "you can continue or abort.\n");
 #endif /* not SIGTSTP */
 #ifdef MSDOS
       /* We must remain inside the screen area when the internal terminal
@@ -10361,46 +10377,49 @@ handle_interrupt (bool in_signal_handler
 	 the code used for auto-saving doesn't cope with the mark bit.  */
       if (!gc_in_progress)
 	{
-	  printf ("Auto-save? (y or n) ");
-	  fflush (stdout);
-	  if (((c = getchar ()) & ~040) == 'Y')
+	  write_stdout ("Auto-save? (y or n) ");
+	  c = read_stdin ();
+	  if (c == 'y' || c == 'Y')
 	    {
 	      Fdo_auto_save (Qt, Qnil);
 #ifdef MSDOS
-	      printf ("\r\nAuto-save done");
-#else /* not MSDOS */
-	      printf ("Auto-save done\n");
-#endif /* not MSDOS */
+	      write_stdout ("\r\nAuto-save done");
+#else
+	      write_stdout ("Auto-save done\n");
+#endif
 	    }
-	  while (c != '\n') c = getchar ();
+	  while (c != '\n')
+	    c = read_stdin ();
 	}
       else
 	{
 	  /* During GC, it must be safe to reenable quitting again.  */
 	  Vinhibit_quit = Qnil;
+	  write_stdout
+	    (
 #ifdef MSDOS
-	  printf ("\r\n");
-#endif /* not MSDOS */
-	  printf ("Garbage collection in progress; cannot auto-save now\r\n");
-	  printf ("but will instead do a real quit after garbage collection ends\r\n");
-	  fflush (stdout);
+	     "\r\n"
+#endif
+	     "Garbage collection in progress; cannot auto-save now\r\n"
+	     "but will instead do a real quit"
+	     " after garbage collection ends\r\n");
 	}
 
 #ifdef MSDOS
-      printf ("\r\nAbort?  (y or n) ");
-#else /* not MSDOS */
-      printf ("Abort (and dump core)? (y or n) ");
-#endif /* not MSDOS */
-      fflush (stdout);
-      if (((c = getchar ()) & ~040) == 'Y')
+      write_stdout ("\r\nAbort?  (y or n) ");
+#else
+      write_stdout ("Abort (and dump core)? (y or n) ");
+#endif
+      c = read_stdin ();
+      if (c == 'y' || c == 'Y')
 	emacs_abort ();
-      while (c != '\n') c = getchar ();
+      while (c != '\n')
+	c = read_stdin ();
 #ifdef MSDOS
-      printf ("\r\nContinuing...\r\n");
+      write_stdout ("\r\nContinuing...\r\n");
 #else /* not MSDOS */
-      printf ("Continuing...\n");
+      write_stdout ("Continuing...\n");
 #endif /* not MSDOS */
-      fflush (stdout);
       init_all_sys_modes ();
     }
   else
