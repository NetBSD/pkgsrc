$NetBSD: patch-fnames.c,v 1.1 2026/03/18 14:39:30 nia Exp $

Fix implicit declaration of string functions.

--- fnames.c.orig	2026-03-18 14:09:20.844534537 +0000
+++ fnames.c
@@ -53,6 +53,7 @@ static char *rcsid="$Id: fnames.c,v 1.7 
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <stdio.h>
+#include <string.h>
 #if TIME_WITH_SYS_TIME
 # include <sys/time.h>
 # include <time.h>
