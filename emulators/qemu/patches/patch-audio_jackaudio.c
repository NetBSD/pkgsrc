$NetBSD: patch-audio_jackaudio.c,v 1.2 2022/06/11 10:13:06 bsiegert Exp $

Teach it about NetBSD's and macOS' pthread_setname_np.

--- audio/jackaudio.c.orig	2021-12-14 20:42:02.000000000 +0000
+++ audio/jackaudio.c
@@ -631,7 +631,13 @@ static int qjack_thread_creator(jack_nat
     }
 
     /* set the name of the thread */
+#ifdef __NetBSD__
+    pthread_setname_np(*thread, "%s", (void *)"jack-client");
+#elif __APPLE__
+    pthread_setname_np("jack-client");
+#else
     pthread_setname_np(*thread, "jack-client");
+#endif
 
     return ret;
 }
