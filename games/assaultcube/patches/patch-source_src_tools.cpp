$NetBSD: patch-source_src_tools.cpp,v 1.1 2024/05/06 14:04:26 nia Exp $

Support non-Linux

--- source/src/tools.cpp.orig	2024-05-06 13:28:19.436269508 +0000
+++ source/src/tools.cpp
@@ -889,7 +889,11 @@ void *sl_createthread(int (*fn)(void *),
     ti->fn = fn;
     ti->done = 0;
     pthread_create(&(ti->handle), NULL, sl_thread_indir, ti);
+#ifdef __NetBSD__
+    if(name) pthread_setname_np(ti->handle, "%s", (void *)name);
+#elif defined(__linux__)
     if(name) pthread_setname_np(ti->handle, name);
+#endif
     return (void *) ti;
 }
 
