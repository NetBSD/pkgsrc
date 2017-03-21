$NetBSD: patch-libxl_xl_cmdimpl.c,v 1.1 2017/03/21 22:52:52 bouyer Exp $
avoid shadowing a global on netbsd-6.

--- libxl/xl_cmdimpl.c.orig	2017-03-21 23:27:46.000000000 +0100
+++ libxl/xl_cmdimpl.c	2017-03-21 23:28:17.000000000 +0100
@@ -473,7 +473,7 @@
     flush_stream(fh);
 }
 
-static int do_daemonize(char *name, const char *pidfile)
+static int do_daemonize(char *name, const char *l_pidfile)
 {
     char *fullname;
     pid_t child1;
@@ -505,8 +505,8 @@
 
     CHK_SYSCALL(daemon(0, 1));
 
-    if (pidfile) {
-        int fd = open(pidfile, O_RDWR | O_CREAT, S_IRUSR|S_IWUSR);
+    if (l_pidfile) {
+        int fd = open(l_pidfile, O_RDWR | O_CREAT, S_IRUSR|S_IWUSR);
         char *pid = NULL;
 
         if (fd == -1) {
@@ -8076,7 +8076,7 @@
 int main_devd(int argc, char **argv)
 {
     int ret = 0, opt = 0, daemonize = 1;
-    const char *pidfile = NULL;
+    const char *l_pidfile = NULL;
     static const struct option opts[] = {
         {"pidfile", 1, 0, 'p'},
         COMMON_LONG_OPTS,
@@ -8088,12 +8088,12 @@
         daemonize = 0;
         break;
     case 'p':
-        pidfile = optarg;
+        l_pidfile = optarg;
         break;
     }
 
     if (daemonize) {
-        ret = do_daemonize("xldevd", pidfile);
+        ret = do_daemonize("xldevd", l_pidfile);
         if (ret) {
             ret = (ret == 1) ? 0 : ret;
             goto out;
