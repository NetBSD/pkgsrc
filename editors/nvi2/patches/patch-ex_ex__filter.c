$NetBSD: patch-ex_ex__filter.c,v 1.1 2020/06/14 11:44:02 nia Exp $

Missing timespec definition.

--- ex/ex_filter.c.orig	2015-04-08 21:20:21.000000000 +0000
+++ ex/ex_filter.c
@@ -14,4 +14,5 @@ static const char sccsid[] = "$Id: ex_fi
 #endif /* not lint */
 
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/queue.h>
