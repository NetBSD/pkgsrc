$NetBSD: patch-src_osd.c,v 1.1 2012/06/02 05:43:07 obache Exp $

Allow compile on apple platforms. osd.c
Use pid_t instead of __pid_t as per open group.
http://splint.cvs.sourceforge.net/viewvc/splint/splint/src/osd.c?r1=1.43&r2=1.44

--- src/osd.c.orig	2007-07-13 22:18:20.000000000 +0000
+++ src/osd.c
@@ -516,7 +516,7 @@ osd_getPid ()
 # if defined (WIN32) || defined (OS2) && defined (__IBMC__)
   int pid = _getpid ();
 # else
-  __pid_t pid = getpid ();
+  pid_t pid = getpid ();
 # endif
 
   return (int) pid;
