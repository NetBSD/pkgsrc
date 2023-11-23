$NetBSD: patch-bat_bat.c,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- bat/bat.c.orig	2023-09-01 15:36:26.000000000 +0000
+++ bat/bat.c
@@ -158,7 +158,8 @@ static void get_format(struct bat *bat, 
 	}
 }
 
-static inline int thread_wait_completion(struct bat *, pthread_t id, int **val)
+static inline int thread_wait_completion(struct bat *bat ATTRIBUTE_UNUSED,
+					 pthread_t id, int **val)
 {
 	int err;
 
