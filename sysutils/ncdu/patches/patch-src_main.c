$NetBSD: patch-src_main.c,v 1.1 2023/01/03 13:29:49 wiz Exp $

Fix build on non-Linux.

--- src/main.c.orig	2022-11-30 10:30:55.000000000 +0000
+++ src/main.c
@@ -257,8 +257,10 @@ static int arg_option(void) {
     if(exclude_addfile(arg)) die("Can't open %s: %s\n", arg, strerror(errno));
   } else if(OPT("--exclude-caches")) cachedir_tags = 1;
   else if(OPT("--include-caches")) cachedir_tags = 0;
+#if HAVE_LINUX_MAGIC_H && HAVE_SYS_STATFS_H && HAVE_STATFS
   else if(OPT("--exclude-kernfs")) exclude_kernfs = 1;
   else if(OPT("--include-kernfs")) exclude_kernfs = 0;
+#endif
   else if(OPT("--follow-firmlinks")) follow_firmlinks = 1;
   else if(OPT("--exclude-firmlinks")) follow_firmlinks = 0;
   else if(OPT("--confirm-quit")) confirm_quit = 1;
@@ -395,7 +397,7 @@ static void argv_parse(int argc, char **
     else if(!arg_option()) die("Unknown option '%s'.\n", argparser_state.last);
   }
 
-#if !(HAVE_LINUX_MAGIC_H && HAVE_SYS_STATFS_H && HAVE_STATFS)
+#if HAVE_LINUX_MAGIC_H && HAVE_SYS_STATFS_H && HAVE_STATFS
   if(exclude_kernfs) die("The --exclude-kernfs flag is currently only supported on Linux.\n");
 #endif
 
