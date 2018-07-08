$NetBSD: patch-mpg321.c,v 1.3 2018/07/08 13:42:13 leot Exp $

- Ensure structs are zero'd before use.
- Do not unlock uninitialized main_lock

--- mpg321.c.orig	2012-03-25 12:27:49.000000000 +0000
+++ mpg321.c
@@ -525,6 +525,7 @@ int main(int argc, char *argv[])
     
     old_dir[0] = '\0';
 
+    memset(&playbuf, 0, sizeof(playbuf));
     playbuf.pl = pl = new_playlist();
 
     if (!pl)
@@ -728,12 +729,13 @@ int main(int argc, char *argv[])
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
