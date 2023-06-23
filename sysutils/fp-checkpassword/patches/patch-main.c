$NetBSD: patch-main.c,v 1.2 2023/06/23 20:30:22 schmonz Exp $

Avoid clearenv(), not available on all platforms.
Provide no-op definition of LOG_PERROR for Solarish.

--- main.c.orig	2017-11-08 07:08:02.000000000 +0000
+++ main.c
@@ -41,6 +41,8 @@
 #define PORT 15408
 #define LOCALHOST "127.0.0.1"
 
+extern char **environ;
+
 int create_socket() {
     int sock;
     struct sockaddr_in dest;
@@ -99,6 +101,9 @@ void timeout(int signum) {
 int main(int argc, char** argv) {
     char *user, *passwd, *remoteIP;
 
+#ifndef LOG_PERROR
+#define LOG_PERROR 0x0
+#endif
     openlog(NULL, LOG_NDELAY | LOG_PERROR, 0);
     
     // Give ourselves 8 seconds
@@ -146,7 +151,7 @@ int main(int argc, char** argv) {
     trimNewline(result);
 
     if (strcmp("success", result) == 0) {
-        clearenv();
+        environ = calloc(1, sizeof(*environ));
         readEnvironment(socket);
 
         closelog();
