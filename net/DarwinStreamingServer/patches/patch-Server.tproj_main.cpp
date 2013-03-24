$NetBSD: patch-Server.tproj_main.cpp,v 1.1 2013/03/24 16:51:08 joerg Exp $

--- Server.tproj/main.cpp.orig	2005-04-27 12:21:14.000000000 +0000
+++ Server.tproj/main.cpp
@@ -212,7 +212,7 @@ int main(int argc, char * argv[]) 
     //(void) ::signal(SIGPIPE, SIG_IGN);
     struct sigaction act;
     
-#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__)
+#if defined(sun) || defined(i386) || defined (__MacOSX__) || defined(__powerpc__) || defined (__osf__) || defined (__sgi_cc__) || defined (__hpux__) || defined(__NetBSD__)
     sigemptyset(&act.sa_mask);
     act.sa_flags = 0;
     act.sa_handler = (void(*)(int))&sigcatcher;
