$NetBSD: patch-common.h,v 1.1 2017/08/15 13:13:36 jperkin Exp $

Avoid queue variable conflict.

--- common.h.orig	2016-03-29 19:19:05.000000000 +0000
+++ common.h
@@ -69,7 +69,7 @@ enum connection_state {
 
 /* A 'queue' is composed of a file descriptor (which can be read from or
  * written to), and a queue for deferred write data */
-struct queue {
+struct sslhqueue {
     int fd;
     void *begin_deferred_data;
     void *deferred_data;
@@ -84,7 +84,7 @@ struct connection {
     /* q[0]: queue for external connection (client);
      * q[1]: queue for internal connection (httpd or sshd);
      * */
-    struct queue q[2];
+    struct sslhqueue q[2];
 };
 
 #define FD_CNXCLOSED    0
@@ -95,7 +95,7 @@ struct connection {
 /* common.c */
 void init_cnx(struct connection *cnx);
 int connect_addr(struct connection *cnx, int fd_from);
-int fd2fd(struct queue *target, struct queue *from);
+int fd2fd(struct sslhqueue *target, struct sslhqueue *from);
 char* sprintaddr(char* buf, size_t size, struct addrinfo *a);
 void resolve_name(struct addrinfo **out, char* fullname);
 void log_connection(struct connection *cnx);
@@ -110,8 +110,8 @@ int resolve_split_name(struct addrinfo *
 
 int start_listen_sockets(int *sockfd[], struct addrinfo *addr_list);
 
-int defer_write(struct queue *q, void* data, int data_size);
-int flush_deferred(struct queue *q);
+int defer_write(struct sslhqueue *q, void* data, int data_size);
+int flush_deferred(struct sslhqueue *q);
 
 extern int probing_timeout, verbose, inetd, foreground, 
        background, transparent, numeric;
