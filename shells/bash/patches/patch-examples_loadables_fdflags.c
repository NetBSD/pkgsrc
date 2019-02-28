$NetBSD: patch-examples_loadables_fdflags.c,v 1.1 2019/02/28 07:20:57 maya Exp $

Handle O_CLOEXEC not being defined (Solaris 10)

--- examples/loadables/fdflags.c.orig	2017-02-02 16:40:42.000000000 +0000
+++ examples/loadables/fdflags.c
@@ -113,8 +113,11 @@ getflags(int fd, int p)
       return -1;
     }
 
-  if (c)
+  if (c) {
+#ifdef O_CLOEXEC
     f |= O_CLOEXEC;
+#endif
+  }
 
   return f & getallflags();
 }
@@ -198,6 +201,7 @@ setone(int fd, char *v, int verbose)
 
   parseflags(v, &pos, &neg);
 
+#ifdef O_CLOEXEC
   cloexec = -1;
   if ((pos & O_CLOEXEC) && (f & O_CLOEXEC) == 0)
     cloexec = FD_CLOEXEC;
@@ -209,6 +213,7 @@ setone(int fd, char *v, int verbose)
   pos &= ~O_CLOEXEC;
   neg &= ~O_CLOEXEC;
   f &= ~O_CLOEXEC;
+#endif
 
   n = f;
   n |= pos;
