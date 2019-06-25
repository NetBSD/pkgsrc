$NetBSD: patch-xio-termios.h,v 1.1 2019/06/25 16:43:47 schmonz Exp $

Use speed_t to match definition, fixing at least OS X build.

--- xio-termios.h.orig	2019-04-04 08:59:55.000000000 +0000
+++ xio-termios.h
@@ -148,7 +148,7 @@ extern int xiotermiosflag_applyopt(int f
 extern int xiotermios_value(int fd, int word, tcflag_t mask, tcflag_t value);
 extern int xiotermios_char(int fd, int n, unsigned char c);
 #ifdef HAVE_TERMIOS_ISPEED
-extern int xiotermios_speed(int fd, int n, unsigned int speed);
+extern int xiotermios_speed(int fd, int n, speed_t speed);
 #endif
 extern int xiotermios_spec(int fd, int optcode);
 extern int xiotermios_flush(int fd);
