$NetBSD: patch-examples_loadables_fdflags.c,v 1.2 2021/01/04 10:39:23 wiz Exp $

Handle O_CLOEXEC not being defined (Solaris 10)

--- examples/loadables/fdflags.c.orig	2019-03-01 19:25:23.000000000 +0000
+++ examples/loadables/fdflags.c
@@ -149,8 +149,11 @@ getflags(int fd, int p)
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
@@ -234,6 +237,7 @@ setone(int fd, char *v, int verbose)
 
   parseflags(v, &pos, &neg);
 
+#ifdef O_CLOEXEC
   cloexec = -1;
 
   if ((pos & O_CLOEXEC) && (f & O_CLOEXEC) == 0)
@@ -247,6 +251,7 @@ setone(int fd, char *v, int verbose)
   pos &= ~O_CLOEXEC;
   neg &= ~O_CLOEXEC;
   f &= ~O_CLOEXEC;
+#endif
 
   n = f;
   n |= pos;
