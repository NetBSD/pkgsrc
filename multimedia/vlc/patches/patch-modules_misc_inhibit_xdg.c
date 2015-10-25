$NetBSD: patch-modules_misc_inhibit_xdg.c,v 1.1 2015/10/25 11:00:18 wiz Exp $

--- modules/misc/inhibit/xdg.c.orig	2014-08-14 07:20:04.000000000 +0000
+++ modules/misc/inhibit/xdg.c
@@ -27,7 +27,9 @@
 #include <vlc_inhibit.h>
 #include <assert.h>
 #include <signal.h>
+#if defined(_POSIX_SPAWN) && (_POSIX_SPAWN >= 0)
 #include <spawn.h>
+#endif
 #include <sys/wait.h>
 
 static int Open (vlc_object_t *);
@@ -45,7 +47,9 @@ vlc_module_end ()
 struct vlc_inhibit_sys
 {
     vlc_timer_t timer;
+#if defined(_POSIX_SPAWN) && (_POSIX_SPAWN >= 0)
     posix_spawnattr_t attr;
+#endif
 };
 
 extern char **environ;
@@ -59,8 +63,12 @@ static void Timer (void *data)
     };
     pid_t pid;
 
+#if defined(_POSIX_SPAWN) && (_POSIX_SPAWN >= 0)
     int err = posix_spawnp (&pid, "xdg-screensaver", NULL, &sys->attr,
                             argv, environ);
+#else
+    int err = EINVAL;
+#endif
     if (err == 0)
     {
         int status;
@@ -88,23 +96,31 @@ static int Open (vlc_object_t *obj)
     if (p_sys == NULL)
         return VLC_ENOMEM;
 
+#if defined(_POSIX_SPAWN) && (_POSIX_SPAWN >= 0)
     posix_spawnattr_init (&p_sys->attr);
+#endif
     /* Reset signal handlers to default and clear mask in the child process */
     {
         sigset_t set;
 
         sigemptyset (&set);
+#if defined(_POSIX_SPAWN) && (_POSIX_SPAWN >= 0)
         posix_spawnattr_setsigmask (&p_sys->attr, &set);
+#endif
         sigaddset (&set, SIGPIPE);
+#if defined(_POSIX_SPAWN) && (_POSIX_SPAWN >= 0)
         posix_spawnattr_setsigdefault (&p_sys->attr, &set);
         posix_spawnattr_setflags (&p_sys->attr, POSIX_SPAWN_SETSIGDEF
                                               | POSIX_SPAWN_SETSIGMASK);
+#endif
     }
 
     ih->p_sys = p_sys;
     if (vlc_timer_create (&p_sys->timer, Timer, ih))
     {
+#if defined(_POSIX_SPAWN) && (_POSIX_SPAWN >= 0)
         posix_spawnattr_destroy (&p_sys->attr);
+#endif
         free (p_sys);
         return VLC_ENOMEM;
     }
@@ -119,6 +135,8 @@ static void Close (vlc_object_t *obj)
     vlc_inhibit_sys_t *p_sys = ih->p_sys;
 
     vlc_timer_destroy (p_sys->timer);
+#if defined(_POSIX_SPAWN) && (_POSIX_SPAWN >= 0)
     posix_spawnattr_destroy (&p_sys->attr);
+#endif
     free (p_sys);
 }
