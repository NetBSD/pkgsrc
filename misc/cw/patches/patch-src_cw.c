$NetBSD: patch-src_cw.c,v 1.1 2015/06/04 20:27:53 youri Exp $

fprintf requires the format.

--- src/cw.c.orig	2010-06-20 04:39:51.000000000 +0000
+++ src/cw.c
@@ -643,7 +643,7 @@ void sighandler(signed int sig){
  else if(sig==SIGUSR1)ext=1;
  else if(sig==SIGALRM)ext=2;
  else if(sig==SIGPIPE||sig==SIGINT){
-  fprintf(stderr,pal2[16]);
+  fprintf(stderr,"%s\n",pal2[16]);
   fflush(stderr);
   cwexit(0,0);
  }
