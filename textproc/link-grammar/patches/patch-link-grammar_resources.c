$NetBSD: patch-link-grammar_resources.c,v 1.1 2023/10/15 06:39:25 ryoon Exp $

--- link-grammar/resources.c.orig	2023-03-05 03:54:59.000000000 +0000
+++ link-grammar/resources.c
@@ -38,6 +38,10 @@ int getrusage(int who, struct rusage *ru
 /* Declaration missing from sys/resource.h in sun operating systems (?) */
 #endif /* __sun__ */
 
+#if !defined(RUSAGE_THREAD) /* At least NetBSD */
+#define RUSAGE_THREAD RUSAGE_SELF
+#endif
+
 #include "api-structures.h"
 #include "resources.h"
 #include "utilities.h"
