$NetBSD: patch-common.h,v 1.3 2022/01/01 16:47:21 rhialto Exp $

Avoid queue variable conflict.

--- common.h.orig	2021-08-28 14:33:20.000000000 +0000
+++ common.h
@@ -88,7 +88,7 @@ enum connection_state {
 
 /* A 'queue' is composed of a file descriptor (which can be read from or
  * written to), and a queue for deferred write data */
-struct queue {
+struct sslhqueue {
     int fd;
     void *begin_deferred_data;
     void *deferred_data;
@@ -106,7 +106,7 @@ struct connection {
     /* q[0]: queue for external connection (client);
      * q[1]: queue for internal connection (httpd or sshd);
      * */
-    struct queue q[2];
+    struct sslhqueue q[2];
 
     /* SOCK_DGRAM */
     struct sockaddr client_addr; /* Contains the remote client address */
@@ -148,7 +148,7 @@ typedef enum {
 void init_cnx(struct connection *cnx);
 int set_nonblock(int fd);
 int connect_addr(struct connection *cnx, int fd_from, connect_blocking blocking);
-int fd2fd(struct queue *target, struct queue *from);
+int fd2fd(struct sslhqueue *target, struct sslhqueue *from);
 char* sprintaddr(char* buf, size_t size, struct addrinfo *a);
 void resolve_name(struct addrinfo **out, char* fullname);
 int get_connection_desc(struct connection_desc* desc, const struct connection *cnx);
@@ -166,8 +166,8 @@ int resolve_split_name(struct addrinfo *
 
 int start_listen_sockets(struct listen_endpoint *sockfd[]);
 
-int defer_write(struct queue *q, void* data, int data_size);
-int flush_deferred(struct queue *q);
+int defer_write(struct sslhqueue *q, void* data, int data_size);
+int flush_deferred(struct sslhqueue *q);
 
 extern struct sslhcfg_item cfg;
 extern struct addrinfo *addr_listen;
