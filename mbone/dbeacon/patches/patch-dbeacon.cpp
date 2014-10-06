$NetBSD: patch-dbeacon.cpp,v 1.1 2014/10/06 10:04:17 he Exp $

Fix pidfile option handling (in configuration file case).

--- dbeacon.cpp.orig	2007-07-13 13:52:14.000000000 +0000
+++ dbeacon.cpp
@@ -176,7 +176,7 @@ bool daemonize = false;
 bool use_syslog = false;
 bool past_init = false;
 
-const char *pidfile = NULL;
+static string pidfile;
 
 static void next_event(timeval *);
 static void insert_event(uint32_t, uint32_t);
@@ -464,8 +464,8 @@ int main(int argc, char **argv) {
 			perror("Failed to daemon()ize.");
 			return -1;
 		}
-		if (pidfile) {
-			FILE *f = fopen(pidfile, "w");
+		if (!pidfile.empty()) {
+			FILE *f = fopen(pidfile.c_str(), "w");
 			if (f) {
 				fprintf(f, "%u\n", getpid());
 				fclose(f);
@@ -1657,8 +1657,8 @@ void dumpBigBwStats(int) {
 
 void sendLeaveReport(int) {
 	send_report(LEAVE_REPORT);
-	if (daemonize && pidfile)
-		unlink(pidfile);
+	if (daemonize && !pidfile.empty())
+		unlink(pidfile.c_str());
 	exit(0);
 }
 
