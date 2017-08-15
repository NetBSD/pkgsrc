$NetBSD: patch-common.c,v 1.1 2017/08/15 13:13:36 jperkin Exp $

Avoid queue variable conflict.

--- common.c.orig	2016-03-29 19:19:05.000000000 +0000
+++ common.c
@@ -237,7 +237,7 @@ int connect_addr(struct connection *cnx,
 }
 
 /* Store some data to write to the queue later */
-int defer_write(struct queue *q, void* data, int data_size)
+int defer_write(struct sslhqueue *q, void* data, int data_size)
 {
     char *p;
     if (verbose)
@@ -261,7 +261,7 @@ int defer_write(struct queue *q, void* d
  * Upon success, the number of bytes written is returned.
  * Upon failure, -1 returned (e.g. connexion closed)
  * */
-int flush_deferred(struct queue *q)
+int flush_deferred(struct sslhqueue *q)
 {
     int n;
 
@@ -313,7 +313,7 @@ void dump_connection(struct connection *
  * returns FD_STALLED if data was read, could not be written, and has been
  * stored in temporary buffer.
  */
-int fd2fd(struct queue *target_q, struct queue *from_q)
+int fd2fd(struct sslhqueue *target_q, struct sslhqueue *from_q)
 {
    char buffer[BUFSIZ];
    int target, from, size_r, size_w;
@@ -594,7 +594,7 @@ void setup_syslog(const char* bin_name)
     int res;
 
     name1 = strdup(bin_name);
-    res = asprintf(&name2, "%s[%d]", basename(name1), getpid());
+    res = asprintf(&name2, "%s[%d]", basename(name1), (int)getpid());
     CHECK_RES_DIE(res, "asprintf");
     openlog(name2, LOG_CONS, LOG_AUTH);
     free(name1);
@@ -694,7 +694,7 @@ void write_pid_file(const char* pidfile)
         exit(3);
     }
 
-    fprintf(f, "%d\n", getpid());
+    fprintf(f, "%d\n", (int)getpid());
     fclose(f);
 }
 
