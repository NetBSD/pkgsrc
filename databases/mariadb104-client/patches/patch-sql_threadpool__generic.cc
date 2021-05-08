$NetBSD: patch-sql_threadpool__generic.cc,v 1.1 2021/05/08 19:47:16 jdolecek Exp $

Deal with NetBSD kqueue changes.

--- sql/threadpool_generic.cc.orig	2020-01-26 20:43:53.000000000 +0000
+++ sql/threadpool_generic.cc
@@ -52,6 +52,9 @@ typedef int TP_file_handle;
 #include <sys/epoll.h>
 typedef struct epoll_event native_event;
 #elif defined(HAVE_KQUEUE)
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
 #include <sys/event.h>
 typedef struct kevent native_event;
 #elif defined (__sun)
@@ -343,12 +346,12 @@ static void *native_event_get_userdata(n
 #elif defined(HAVE_KQUEUE)
 
 /* 
-  NetBSD is incompatible with other BSDs , last parameter in EV_SET macro
+  NetBSD<=9 is incompatible with other BSDs , last parameter in EV_SET macro
   (udata, user data) needs to be intptr_t, whereas it needs to be void* 
   everywhere else.
 */
 
-#ifdef __NetBSD__
+#if defined(__NetBSD__) && __NetBSD_Version__ < 999001500
 #define MY_EV_SET(a, b, c, d, e, f, g) EV_SET(a, b, c, d, e, f, (intptr_t)g)
 #else
 #define MY_EV_SET(a, b, c, d, e, f, g) EV_SET(a, b, c, d, e, f, g)
