$NetBSD: patch-common.c,v 1.3 2021/06/13 12:04:21 rhialto Exp $

Avoid queue variable conflict.

--- common.c.orig	2020-07-30 07:45:50.000000000 +0000
+++ common.c
@@ -338,7 +338,7 @@ int connect_addr(struct connection *cnx,
 }
 
 /* Store some data to write to the queue later */
-int defer_write(struct queue *q, void* data, int data_size)
+int defer_write(struct sslhqueue *q, void* data, int data_size)
 {
     char *p;
     ptrdiff_t data_offset = q->deferred_data - q->begin_deferred_data;
@@ -361,7 +361,7 @@ int defer_write(struct queue *q, void* d
  * Upon success, the number of bytes written is returned.
  * Upon failure, -1 returned (e.g. connexion closed)
  * */
-int flush_deferred(struct queue *q)
+int flush_deferred(struct sslhqueue *q)
 {
     int n;
 
@@ -413,7 +413,7 @@ void dump_connection(struct connection *
  * returns FD_STALLED if data was read, could not be written, and has been
  * stored in temporary buffer.
  */
-int fd2fd(struct queue *target_q, struct queue *from_q)
+int fd2fd(struct sslhqueue *target_q, struct sslhqueue *from_q)
 {
    char buffer[BUFSIZ];
    int target, from, size_r, size_w;
@@ -738,7 +738,7 @@ void setup_syslog(const char* bin_name) 
     }
 
     name1 = strdup(bin_name);
-    res = asprintf(&name2, "%s[%d]", basename(name1), getpid());
+    res = asprintf(&name2, "%s[%d]", basename(name1), (int)getpid());
     CHECK_RES_DIE(res, "asprintf");
 
     for (fn = 0; facilitynames[fn].c_val != -1; fn++)
@@ -861,7 +861,7 @@ void write_pid_file(const char* pidfile)
         exit(3);
     }
 
-    fprintf(f, "%d\n", getpid());
+    fprintf(f, "%d\n", (int)getpid());
     fclose(f);
 }
 
