$NetBSD: patch-agent_filter_lock.c,v 1.1 2013/06/15 06:09:37 obache Exp $

--- agent/filter/lock.c.orig	2001-03-17 18:31:21.000000000 +0000
+++ agent/filter/lock.c
@@ -48,6 +48,7 @@
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <stdio.h>
 
 #ifdef I_FCNTL
 #include <fcntl.h>
