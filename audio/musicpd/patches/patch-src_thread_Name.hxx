$NetBSD: patch-src_thread_Name.hxx,v 1.1 2015/01/05 22:19:02 wiz Exp $

http://bugs.musicpd.org/view.php?id=4266

Still gives:
In file included from src/IOThread.cxx:25:0:
src/thread/Name.hxx: In function 'void SetThreadName(const char*)':
src/thread/Name.hxx:37:51: warning: cast from type 'const char*' to type 'void*' casts away qualifiers [-Wcast-qual]
  pthread_setname_np(pthread_self(), "%s", (void *)name);
                                                   ^
--- src/thread/Name.hxx.orig	2014-10-24 22:28:53.000000000 +0000
+++ src/thread/Name.hxx
@@ -33,6 +33,8 @@ SetThreadName(const char *name)
 #ifdef HAVE_PTHREAD_SETNAME_NP
 #ifdef __APPLE__
 	pthread_setname_np(name);
+#elif defined(__NetBSD__)
+	pthread_setname_np(pthread_self(), "%s", (void *)name);
 #else
 	pthread_setname_np(pthread_self(), name);
 #endif
