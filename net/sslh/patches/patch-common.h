$NetBSD: patch-common.h,v 1.2 2021/06/13 12:04:21 rhialto Exp $

Avoid queue variable conflict.

--- common.h.orig	2020-07-30 07:45:50.000000000 +0000
+++ common.h
@@ -85,7 +85,7 @@ enum connection_state {
 
 /* A 'queue' is composed of a file descriptor (which can be read from or
  * written to), and a queue for deferred write data */
-struct queue {
+struct sslhqueue {
     int fd;
     void *begin_deferred_data;
     void *deferred_data;
@@ -100,7 +100,7 @@ struct connection {
     /* q[0]: queue for external connection (client);
      * q[1]: queue for internal connection (httpd or sshd);
      * */
-    struct queue q[2];
+    struct sslhqueue q[2];
 };
 
 #define FD_CNXCLOSED    0
@@ -118,7 +118,7 @@ struct connection_desc {
 /* common.c */
 void init_cnx(struct connection *cnx);
 int connect_addr(struct connection *cnx, int fd_from);
-int fd2fd(struct queue *target, struct queue *from);
+int fd2fd(struct sslhqueue *target, struct sslhqueue *from);
 char* sprintaddr(char* buf, size_t size, struct addrinfo *a);
 void resolve_name(struct addrinfo **out, char* fullname);
 int get_connection_desc(struct connection_desc* desc, const struct connection *cnx);
@@ -135,8 +135,8 @@ int resolve_split_name(struct addrinfo *
 
 int start_listen_sockets(int *sockfd[], struct addrinfo *addr_list);
 
-int defer_write(struct queue *q, void* data, int data_size);
-int flush_deferred(struct queue *q);
+int defer_write(struct sslhqueue *q, void* data, int data_size);
+int flush_deferred(struct sslhqueue *q);
 
 extern struct sslhcfg_item cfg;
 extern struct addrinfo *addr_listen;
