$NetBSD: patch-mpg321.c,v 1.4 2025/10/07 03:56:02 mrg Exp $

- Ensure structs are zero'd before use.
- Do not unlock uninitialized main_lock
- Add missing type for http_file_length

--- mpg321.c.orig	2012-03-25 05:27:49.000000000 -0700
+++ mpg321.c	2025-09-29 14:02:15.346443620 -0700
@@ -99,7 +99,7 @@
 /* PID of frame buffer process */
 pid_t output_pid;
 /* Not used for the moment. It only works for CBR http/ftp retrieved files */
-extern http_file_length;
+extern int http_file_length;
 #ifdef HAVE_ALSA
 /* ALSA Volume Range */
 extern long volume_min,volume_max;
@@ -525,6 +525,7 @@
     
     old_dir[0] = '\0';
 
+    memset(&playbuf, 0, sizeof(playbuf));
     playbuf.pl = pl = new_playlist();
 
     if (!pl)
@@ -728,12 +729,13 @@
 //	    options.volume = mad_f_tofixed((long)100.0/100.0);
     }
 
+    sem_init(&main_lock,0,0);
+
     if (!(options.opt & MPG321_REMOTE_PLAY))
     {
 	     if(options.opt & MPG321_ENABLE_BASIC)
 	     {
 	 	     /* Now create and detach the basic controls thread */
-		     sem_init(&main_lock,0,0);
 	 	     pthread_create(&keyb_thread,NULL,read_keyb,NULL);
 		     pthread_detach(keyb_thread);
 	     }
