$NetBSD: patch-util.c,v 1.1 2014/08/11 21:29:00 markd Exp $

Readline-6.3 Official Patch 3

There are debugging functions in the readline release that are theoretically
exploitable as security problems.  They are not public functions, but have
global linkage.

--- util.c.orig	2013-09-02 17:36:12.000000000 +0000
+++ util.c
@@ -476,6 +476,7 @@ _rl_savestring (s)
   return (strcpy ((char *)xmalloc (1 + (int)strlen (s)), (s)));
 }
 
+#if defined (DEBUG)
 #if defined (USE_VARARGS)
 static FILE *_rl_tracefp;
 
@@ -538,6 +539,7 @@ _rl_settracefp (fp)
   _rl_tracefp = fp;
 }
 #endif
+#endif /* DEBUG */
 
 
 #if HAVE_DECL_AUDIT_USER_TTY && defined (ENABLE_TTY_AUDIT_SUPPORT)
