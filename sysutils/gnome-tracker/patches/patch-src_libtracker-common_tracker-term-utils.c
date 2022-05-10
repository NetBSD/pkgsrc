$NetBSD: patch-src_libtracker-common_tracker-term-utils.c,v 1.1 2022/05/10 09:37:38 jperkin Exp $

Include termios for TIOCGWINSZ.

--- src/libtracker-common/tracker-term-utils.c.orig	2020-10-02 09:59:29.818610200 +0000
+++ src/libtracker-common/tracker-term-utils.c
@@ -27,6 +27,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdio.h>
+#include <termios.h>
 
 static guint n_columns = 0;
 static guint n_rows = 0;
