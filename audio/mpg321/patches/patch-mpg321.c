$NetBSD: patch-mpg321.c,v 1.2 2018/06/16 14:43:21 leot Exp $

- Ensure structs are zero'd before use.
- Do not unlock uninitialized main_lock

--- mpg321.c.orig	2012-03-25 12:27:49.000000000 +0000
+++ mpg321.c
@@ -525,6 +525,7 @@ int main(int argc, char *argv[])
     
     old_dir[0] = '\0';
 
+    memset(&playbuf, 0, sizeof(playbuf));
     playbuf.pl = pl = new_playlist();
 
     if (!pl)
@@ -750,8 +751,6 @@ int main(int argc, char *argv[])
 	    	    if (tcgetattr(0, &terminal_settings) < 0)
 	    		    perror("tcgetattr()");
 	    	    memcpy(&old_terminal_settings, &terminal_settings, sizeof(struct termios));
-		    /* Early thread start */
-		    sem_post(&main_lock);
 	    }
     }
     /* Play the mpeg files or zip it! */
