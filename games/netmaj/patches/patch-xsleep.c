$NetBSD: patch-xsleep.c,v 1.1 2013/02/26 10:29:34 joerg Exp $

--- xsleep.c.orig	2013-02-25 20:45:25.000000000 +0000
+++ xsleep.c
@@ -25,12 +25,14 @@
 #include "pai.h"
 #include "global.h"
 
-xsleep(time_out) {
-	return ysleep(time_out * 10);
+static void ysleep(int);
+
+void xsleep(time_out) {
+	ysleep(time_out * 10);
 }
 
 #ifndef HAVE_GETTIMEOFDAY
-ysleep(time_out) {
+static void ysleep(int time_out) {
 	fd_set fds;
 	struct timeval to,*top;
 	int ret = 0;
@@ -51,7 +53,7 @@ static double dtime() {
 	return (now.tv_sec + now.tv_usec * 0.0000001);
 }
 
-ysleep(time_out) {
+static void ysleep(int time_out) {
 	fd_set fds;
 	struct timeval to,*top;
 	double t,now;
