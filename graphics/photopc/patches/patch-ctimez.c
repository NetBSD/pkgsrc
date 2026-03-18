$NetBSD: patch-ctimez.c,v 1.1 2026/03/18 14:39:30 nia Exp $

Fix implicit declaration of string functions.

--- ctimez.c.orig	2026-03-18 14:09:29.669459027 +0000
+++ ctimez.c
@@ -48,6 +48,7 @@ static char *rcsid="$Id: ctimez.c,v 1.7 
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <stdio.h>
+#include <string.h>
 #if TIME_WITH_SYS_TIME
 # include <sys/time.h>
 # include <time.h>
