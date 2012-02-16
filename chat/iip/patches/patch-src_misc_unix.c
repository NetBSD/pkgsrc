$NetBSD: patch-src_misc_unix.c,v 1.1 2012/02/16 15:00:58 hans Exp $

--- src/misc/unix.c.orig	2002-06-21 05:27:01.000000000 +0200
+++ src/misc/unix.c	2012-01-20 18:18:01.041438535 +0100
@@ -11,11 +11,7 @@
 #include <dirent.h>
 #include <signal.h>
 #include <unistd.h>
-/*
-#if !defined(LOCK_EX) && !defined(LOCK_NB)
 #include <fcntl.h>
-#endif
-*/
 #include <string.h>
 #include <stdio.h>
 
