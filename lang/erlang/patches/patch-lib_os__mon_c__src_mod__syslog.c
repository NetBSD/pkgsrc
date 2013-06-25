$NetBSD: patch-lib_os__mon_c__src_mod__syslog.c,v 1.1 2013/06/25 10:06:34 jperkin Exp $

Avoid -Werror=return-type errors.

--- lib/os_mon/c_src/mod_syslog.c.orig	2013-02-25 19:21:31.000000000 +0000
+++ lib/os_mon/c_src/mod_syslog.c
@@ -47,7 +47,7 @@
 #define		TRUE		1
 #define		WAIT		1
 
-main(int argc, char *argv[])
+int main(int argc, char *argv[])
 /*	usage: mod_syslog mode ownpath syslogconf */
 {
     int	syslogd_pid, n_lines_copied=0;
@@ -128,6 +128,9 @@ main(int argc, char *argv[])
        make_exit(PIPE_NOT_FOUND);
        else */
     make_exit(OK);
+
+    /* NOTREACHED */
+    return 0;
 }
 
 void	make_exit(int exit_code)
