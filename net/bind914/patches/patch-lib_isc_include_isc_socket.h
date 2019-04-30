$NetBSD: patch-lib_isc_include_isc_socket.h,v 1.1 2019/04/30 03:34:34 taca Exp $

* fdwatch change from NetBSD base.

--- lib/isc/include/isc/socket.h.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/isc/include/isc/socket.h
@@ -243,7 +243,8 @@ typedef enum {
 	isc_sockettype_udp = 1,
 	isc_sockettype_tcp = 2,
 	isc_sockettype_unix = 3,
-	isc_sockettype_raw = 4
+	isc_sockettype_raw = 4,
+	isc_sockettype_fdwatch = 5
 } isc_sockettype_t;
 
 /*@{*/
@@ -1037,6 +1038,82 @@ isc_socketmgr_renderjson(isc_socketmgr_t
  */
 typedef isc_result_t
 (*isc_socketmgrcreatefunc_t)(isc_mem_t *mctx, isc_socketmgr_t **managerp);
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
+/*%<
+ * Create a new file descriptor watch socket managed by 'manager'.
+ *
+ * Note:
+ *
+ *\li   'fd' is the already-opened file descriptor (must be less
+ * 	than maxsockets).
+ *\li	This function is not available on Windows.
+ *\li	The callback function is called "in-line" - this means the function
+ *	needs to return as fast as possible, as all other I/O will be suspended
+ *	until the callback completes.
+ *
+ * Requires:
+ *
+ *\li	'manager' is a valid manager
+ *
+ *\li	'socketp' is a valid pointer, and *socketp == NULL
+ *
+ *\li	'fd' be opened.
+ *
+ * Ensures:
+ *
+ *	'*socketp' is attached to the newly created fdwatch socket
+ *
+ * Returns:
+ *
+ *\li	#ISC_R_SUCCESS
+ *\li	#ISC_R_NOMEMORY
+ *\li	#ISC_R_NORESOURCES
+ *\li	#ISC_R_UNEXPECTED
+ *\li	#ISC_R_RANGE
+ */
+
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
 
