$NetBSD: patch-libraries_unix_cbits_execvpe.c,v 1.1 2015/10/23 20:46:22 tnn Exp $

Don't conflict with builtin execvpe(3).

--- libraries/unix/cbits/execvpe.c.orig	2013-04-18 21:36:40.000000000 +0000
+++ libraries/unix/cbits/execvpe.c
@@ -57,8 +57,22 @@
  * SUCH DAMAGE.
  */
 
+#ifdef __NetBSD__
+#  include <sys/param.h>
+#  if __NetBSD_Version__ > 799000000
+#    define HAVE_EXECVPE 1
+#  endif
+#elif defined(__GLIBC__)
+#  define HAVE_EXECVPE 1
+#endif
+
+#ifdef HAVE_EXECVPE
+static int
+unused_execvpe(char *name, char *const argv[], char **envp)
+#else
 int
 execvpe(char *name, char *const argv[], char **envp)
+#endif /* HAVE_EXECVPE */
 {
     register int lp, ln;
     register char *p;
