$NetBSD: patch-daemon.c,v 1.1 2013/09/10 14:26:49 joerg Exp $

--- daemon.c.orig	1995-06-30 23:41:05.000000000 +0000
+++ daemon.c
@@ -126,7 +126,7 @@ void  dip_setup ( void )
   /*
    *  Fire up the protocol here. 
    */
-  (int) protosw [ mydip.protonr - 1 ].func ( );
+  (void) protosw [ mydip.protonr - 1 ].func ( );
 
 
   /*
@@ -168,6 +168,8 @@ int  dip_daemon ( void )
     openlog ( "DIP", LOG_PID, LOG_DAEMON );
   }
 
+  /* note the race condition here; ick! */
+  tty_relock();
 
   (void) signal ( SIGALRM, sig_catcher );
   (void) alarm ( mydip.timeout );
