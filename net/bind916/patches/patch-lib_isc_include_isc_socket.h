$NetBSD: patch-lib_isc_include_isc_socket.h,v 1.3 2022/07/20 15:14:14 taca Exp $

* Take from NetBSD base.

--- lib/isc/include/isc/socket.h.orig	2022-07-11 04:55:00.000000000 +0000
+++ lib/isc/include/isc/socket.h
@@ -162,7 +162,8 @@ typedef enum {
 	isc_sockettype_udp = 1,
 	isc_sockettype_tcp = 2,
 	isc_sockettype_unix = 3,
-	isc_sockettype_raw = 4
+	isc_sockettype_raw = 4,
+	isc_sockettype_fdwatch = 5
 } isc_sockettype_t;
 
 /*@{*/
@@ -903,12 +904,56 @@ isc_socketmgr_renderjson(isc_socketmgr_t
  */
 #endif /* HAVE_JSON_C */
 
+/*!
+ * Flags for fdwatchcreate.
+ */
+#define ISC_SOCKFDWATCH_READ	0x00000001	/*%< watch for readable */
+#define ISC_SOCKFDWATCH_WRITE	0x00000002	/*%< watch for writable */
+/*@}*/
+
+isc_result_t
+isc_socket_fdwatchcreate(isc_socketmgr_t *manager,
+			 int fd,
+			 int flags,
+			 isc_sockfdwatch_t callback,
+			 void *cbarg,
+			 isc_task_t *task,
+			 isc_socket_t **socketp);
+
 /*%<
  * See isc_socketmgr_create() above.
  */
 typedef isc_result_t (*isc_socketmgrcreatefunc_t)(isc_mem_t	   *mctx,
 						  isc_socketmgr_t **managerp);
 
+isc_result_t
+isc_socket_fdwatchpoke(isc_socket_t *sock,
+		       int flags);
+/*%<
+ * Poke a file descriptor watch socket informing the manager that it
+ * should restart watching the socket
+ *
+ * Note:
+ *
+ *\li   'sock' is the socket returned by isc_socket_fdwatchcreate
+ *
+ *\li   'flags' indicates what the manager should watch for on the socket
+ *      in addition to what it may already be watching.  It can be one or
+ *      both of ISC_SOCKFDWATCH_READ and ISC_SOCKFDWATCH_WRITE.  To
+ *      temporarily disable watching on a socket the value indicating
+ *      no more data should be returned from the call back routine.
+ *
+ *\li	This function is not available on Windows.
+ *
+ * Requires:
+ *
+ *\li	'sock' is a valid isc socket
+ *
+ *
+ * Returns:
+ *
+ *\li	#ISC_R_SUCCESS
+ */
 ISC_LANG_ENDDECLS
 
 #endif /* ISC_SOCKET_H */
