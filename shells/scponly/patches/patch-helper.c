$NetBSD: patch-helper.c,v 1.1 2011/12/05 22:56:22 joerg Exp $

--- helper.c.orig	2011-12-05 21:14:21.000000000 +0000
+++ helper.c
@@ -230,7 +230,7 @@ int check_dangerous_args(char **av)
 						return 1;
 					}
 				}
-#elif
+#else
 				/*
 				 * make sure that processing doesn't continue if we can't validate a rsync check
 				 * and if the getopt flag is set.
