$NetBSD: patch-src_frontend_input.cc,v 1.1 2026/10/16 17:53:01 ktnb Exp $

On a EOF from stdin, just update the the user input rather than
flagging as quit. This prevents issues with fgets(3) throwing an
interrupted system call.

--- src/frontend/input.cc.orig	2025-07-12 10:00:07.000000000 +0000
+++ src/frontend/input.cc
@@ -152,7 +152,7 @@ void *input_func(void *arg __attribute__((unused)) )
 	      (RealGameCnt+1)/2 + 1 );
     }
     if (!get_line(prompt)) {
-      SET(flags, QUIT);
+      strcpy(userinputstr , "quit\n");
     }
     SendToFrontend( userinputstr );
 #ifdef HAVE_LIBREADLINE
