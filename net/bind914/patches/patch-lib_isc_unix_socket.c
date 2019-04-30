$NetBSD: patch-lib_isc_unix_socket.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Apply fixes from NetBSD base system.

--- lib/isc/unix/socket.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/isc/unix/socket.c
@@ -225,6 +225,7 @@ typedef enum { poll_idle, poll_active, p
 			 (e) == EWOULDBLOCK || \
 			 (e) == ENOBUFS || \
 			 (e) == EINTR || \
+			 (e) == ENOBUFS || \
 			 (e) == 0)
 
 #define DLVL(x) ISC_LOGCATEGORY_GENERAL, ISC_LOGMODULE_SOCKET, ISC_LOG_DEBUG(x)
@@ -366,6 +367,10 @@ struct isc__socket {
 	unsigned char		overflow; /* used for MSG_TRUNC fake */
 #endif
 
+	void			*fdwatcharg;
+	isc_sockfdwatch_t	fdwatchcb;
+	int			fdwatchflags;
+	isc_task_t              *fdwatchtask;
 	unsigned int		dscp;
 };
 
@@ -452,10 +457,14 @@ static void free_socket(isc__socket_t **
 static isc_result_t allocate_socket(isc__socketmgr_t *, isc_sockettype_t,
 				    isc__socket_t **);
 static void destroy(isc__socket_t **);
+#if 0
 static void internal_accept(isc__socket_t *);
+#endif
 static void internal_connect(isc__socket_t *);
 static void internal_recv(isc__socket_t *);
 static void internal_send(isc__socket_t *);
+static void internal_fdwatch_write(isc__socket_t *);
+static void internal_fdwatch_read(isc__socket_t *);
 static void process_cmsg(isc__socket_t *, struct msghdr *, isc_socketevent_t *);
 static void build_msghdr_send(isc__socket_t *, char *, isc_socketevent_t *,
 			      struct msghdr *, struct iovec *, size_t *);
@@ -1576,6 +1585,7 @@ doio_recv(isc__socket_t *sock, isc_socke
 	case isc_sockettype_udp:
 	case isc_sockettype_raw:
 		break;
+	case isc_sockettype_fdwatch:
 	default:
 		INSIST(0);
 		ISC_UNREACHABLE();
@@ -1778,9 +1788,26 @@ socketclose(isc__socketthread_t *thread,
 	 */
 	LOCK(&thread->fdlock[lockid]);
 	thread->fds[fd] = NULL;
-	thread->fdstate[fd] = CLOSE_PENDING;
+	if (sock->type == isc_sockettype_fdwatch)
+		thread->fdstate[fd] = CLOSED;
+	else
+		thread->fdstate[fd] = CLOSE_PENDING;
 	UNLOCK(&thread->fdlock[lockid]);
-	select_poke(thread->manager, thread->threadid, fd, SELECT_POKE_CLOSE);
+	if (sock->type == isc_sockettype_fdwatch) {
+		/*
+		 * The caller may close the socket once this function returns,
+		 * and `fd' may be reassigned for a new socket.  So we do
+		 * unwatch_fd() here, rather than defer it via select_poke().
+		 * Note: this may complicate data protection among threads and
+		 * may reduce performance due to additional locks.  One way to
+		 * solve this would be to dup() the watched descriptor, but we
+		 * take a simpler approach at this moment.
+		 */
+		(void)unwatch_fd(thread, fd, SELECT_POKE_READ);
+		(void)unwatch_fd(thread, fd, SELECT_POKE_WRITE);
+	} else
+		select_poke(thread->manager, thread->threadid, fd,
+		    SELECT_POKE_CLOSE);
 
 	inc_stats(thread->manager->stats, sock->statsindex[STATID_CLOSE]);
 	if (sock->active == 1) {
@@ -2187,6 +2214,13 @@ opensocket(isc__socketmgr_t *manager, is
 			}
 #endif
 			break;
+		case isc_sockettype_fdwatch:
+			/*
+			 * We should not be called for isc_sockettype_fdwatch
+			 * sockets.
+			 */
+			INSIST(0);
+			break;
 		}
 	} else {
 		sock->fd = dup(dup_socket->fd);
@@ -2485,6 +2519,7 @@ socket_create(isc_socketmgr_t *manager0,
 
 	REQUIRE(VALID_MANAGER(manager));
 	REQUIRE(socketp != NULL && *socketp == NULL);
+	REQUIRE(type != isc_sockettype_fdwatch);
 
 	result = allocate_socket(manager, type, &sock);
 	if (result != ISC_R_SUCCESS)
@@ -2605,6 +2640,7 @@ isc_socket_open(isc_socket_t *sock0) {
 	 */
 	REQUIRE(sock->fd == -1);
 	REQUIRE(sock->threadid == -1);
+	REQUIRE(sock->type != isc_sockettype_fdwatch);
 
 	result = opensocket(sock->manager, sock, NULL);
 	if (result != ISC_R_SUCCESS) {
@@ -2684,6 +2720,7 @@ isc_socket_close(isc_socket_t *sock0) {
 
 	LOCK(&sock->lock);
 
+	REQUIRE(sock->type != isc_sockettype_fdwatch);
 	REQUIRE(sock->fd >= 0 && sock->fd < (int)sock->manager->maxsocks);
 
 	INSIST(!sock->connecting);
@@ -2714,6 +2751,24 @@ isc_socket_close(isc_socket_t *sock0) {
 	return (ISC_R_SUCCESS);
 }
 
+static void
+dispatch_recv(isc__socket_t *sock) {
+	if (sock->type != isc_sockettype_fdwatch) {
+		internal_recv(sock);
+	} else {
+		internal_fdwatch_read(sock);
+	}
+}
+
+static void
+dispatch_send(isc__socket_t *sock) {
+	if (sock->type != isc_sockettype_fdwatch) {
+		internal_send(sock);
+	} else {
+		internal_fdwatch_write(sock);
+	}
+}
+
 /*
  * Dequeue an item off the given socket's read queue, set the result code
  * in the done event to the one provided, and send it to the task it was
@@ -2790,6 +2845,7 @@ send_connectdone_event(isc__socket_t *so
 	isc_task_sendtoanddetach(&task, (isc_event_t **)dev, sock->threadid);
 }
 
+#if 0
 /*
  * Call accept() on a socket, to get the new file descriptor.  The listen
  * socket is used as a prototype to create a new isc_socket_t.  The new
@@ -3048,6 +3104,7 @@ internal_accept(isc__socket_t *sock) {
 	inc_stats(manager->stats, sock->statsindex[STATID_ACCEPTFAIL]);
 	return;
 }
+#endif
 
 static void
 internal_recv(isc__socket_t *sock) {
@@ -3154,6 +3211,64 @@ internal_send(isc__socket_t *sock) {
 	UNLOCK(&sock->lock);
 }
 
+static void
+internal_fdwatch_write(isc__socket_t *sock)
+{
+	int more_data;
+
+	INSIST(VALID_SOCKET(sock));
+
+	LOCK(&sock->lock);
+	isc_refcount_increment(&sock->references);
+	UNLOCK(&sock->lock);
+
+	more_data = (sock->fdwatchcb)(sock->fdwatchtask, (isc_socket_t *)sock,
+				      sock->fdwatcharg, ISC_SOCKFDWATCH_WRITE);
+
+	LOCK(&sock->lock);
+
+	if (isc_refcount_decrement(&sock->references) == 0) {
+		UNLOCK(&sock->lock);
+		destroy(&sock);
+		return;
+	}
+
+	if (more_data)
+		select_poke(sock->manager, sock->threadid, sock->fd,
+		    SELECT_POKE_WRITE);
+
+	UNLOCK(&sock->lock);
+}
+
+static void
+internal_fdwatch_read(isc__socket_t *sock)
+{
+	int more_data;
+
+	INSIST(VALID_SOCKET(sock));
+
+	LOCK(&sock->lock);
+	isc_refcount_increment(&sock->references);
+	UNLOCK(&sock->lock);
+
+	more_data = (sock->fdwatchcb)(sock->fdwatchtask, (isc_socket_t *)sock,
+				      sock->fdwatcharg, ISC_SOCKFDWATCH_READ);
+
+	LOCK(&sock->lock);
+
+	if (isc_refcount_decrement(&sock->references) == 0) {
+		UNLOCK(&sock->lock);
+		destroy(&sock);
+		return;
+	}
+
+	if (more_data)
+		select_poke(sock->manager, sock->threadid, sock->fd,
+		    SELECT_POKE_READ);
+
+	UNLOCK(&sock->lock);
+}
+
 /*
  * Process read/writes on each fd here.  Avoid locking
  * and unlocking twice if both reads and writes are possible.
@@ -3194,7 +3309,7 @@ process_fd(isc__socketthread_t *thread, 
 
 	if (readable) {
 		if (sock->listener) {
-			internal_accept(sock);
+			dispatch_recv(sock);
 		} else {
 			internal_recv(sock);
 		}
@@ -3204,7 +3319,7 @@ process_fd(isc__socketthread_t *thread, 
 		if (sock->connecting) {
 			internal_connect(sock);
 		} else {
-			internal_send(sock);
+			dispatch_send(sock);
 		}
 	}
 
@@ -3858,8 +3973,8 @@ isc_socketmgr_create2(isc_mem_t *mctx, i
 						&manager->threads[i],
 						&manager->threads[i].thread)
 			      == ISC_R_SUCCESS);
-		char tname[1024];
-		sprintf(tname, "isc-socket-%d", i);
+		char tname[128];
+		snprintf(tname, sizeof(tname), "sock-%d", i);
 		isc_thread_setname(manager->threads[i].thread, tname);
 	}
 
@@ -5326,7 +5441,7 @@ static isc_once_t	hasreuseport_once = IS
 static bool		hasreuseport = false;
 
 static void
-init_hasreuseport() {
+init_hasreuseport(void) {
 /*
  * SO_REUSEPORT works very differently on *BSD and on Linux (because why not).
  * We only want to use it on Linux, if it's available. On BSD we want to dup()
@@ -5376,6 +5491,8 @@ _socktype(isc_sockettype_t type)
 		return ("tcp");
 	case isc_sockettype_unix:
 		return ("unix");
+	case isc_sockettype_fdwatch:
+		return ("fdwatch");
 	default:
 		return ("not-initialized");
 	}
@@ -5605,3 +5722,112 @@ isc_socketmgr_createinctx(isc_mem_t *mct
 
 	return (result);
 }
+
+/*
+ * Create a new 'type' socket managed by 'manager'.  Events
+ * will be posted to 'task' and when dispatched 'action' will be
+ * called with 'arg' as the arg value.  The new socket is returned
+ * in 'socketp'.
+ */
+isc_result_t
+isc_socket_fdwatchcreate(isc_socketmgr_t *manager0, int fd, int flags,
+			 isc_sockfdwatch_t callback, void *cbarg,
+			 isc_task_t *task, isc_socket_t **socketp)
+{
+	isc__socketmgr_t *manager = (isc__socketmgr_t *)manager0;
+	isc__socket_t *sock = NULL;
+	isc__socketthread_t *thread;
+	isc_result_t result;
+	int lockid;
+
+	REQUIRE(VALID_MANAGER(manager));
+	REQUIRE(socketp != NULL && *socketp == NULL);
+
+	if (fd < 0 || (unsigned int)fd >= manager->maxsocks)
+		return (ISC_R_RANGE);
+
+	result = allocate_socket(manager, isc_sockettype_fdwatch, &sock);
+	if (result != ISC_R_SUCCESS)
+		return (result);
+
+	sock->fd = fd;
+	sock->fdwatcharg = cbarg;
+	sock->fdwatchcb = callback;
+	sock->fdwatchflags = flags;
+	sock->fdwatchtask = task;
+
+	sock->threadid = gen_threadid(sock);
+	isc_refcount_init(&sock->references, 1);
+	thread = &manager->threads[sock->threadid];
+	*socketp = (isc_socket_t *)sock;
+
+	/*
+	 * Note we don't have to lock the socket like we normally would because
+	 * there are no external references to it yet.
+	 */
+
+	lockid = FDLOCK_ID(sock->fd);
+	LOCK(&thread->fdlock[lockid]);
+	thread->fds[sock->fd] = sock;
+	thread->fdstate[sock->fd] = MANAGED;
+
+#if defined(USE_EPOLL)
+	manager->threads->epoll_events[sock->fd] = 0;
+#endif
+	UNLOCK(&thread->fdlock[lockid]);
+
+	LOCK(&manager->lock);
+	ISC_LIST_APPEND(manager->socklist, sock, link);
+#ifdef USE_SELECT
+	if (manager->maxfd < sock->fd)
+		manager->maxfd = sock->fd;
+#endif
+	UNLOCK(&manager->lock);
+
+	sock->active = 1;
+	if (flags & ISC_SOCKFDWATCH_READ)
+		select_poke(sock->manager, sock->threadid, sock->fd,
+		    SELECT_POKE_READ);
+	if (flags & ISC_SOCKFDWATCH_WRITE)
+		select_poke(sock->manager, sock->threadid, sock->fd,
+		    SELECT_POKE_WRITE);
+
+	socket_log(sock, NULL, CREATION, "fdwatch-created");
+
+	return (ISC_R_SUCCESS);
+}
+
+/*
+ * Indicate to the manager that it should watch the socket again.
+ * This can be used to restart watching if the previous event handler
+ * didn't indicate there was more data to be processed.  Primarily
+ * it is for writing but could be used for reading if desired
+ */
+
+isc_result_t
+isc_socket_fdwatchpoke(isc_socket_t *sock0, int flags)
+{
+	isc__socket_t *sock = (isc__socket_t *)sock0;
+
+	REQUIRE(VALID_SOCKET(sock));
+
+	/*
+	 * We check both flags first to allow us to get the lock
+	 * once but only if we need it.
+	 */
+
+	if ((flags & (ISC_SOCKFDWATCH_READ | ISC_SOCKFDWATCH_WRITE)) != 0) {
+		LOCK(&sock->lock);
+		if ((flags & ISC_SOCKFDWATCH_READ) != 0)
+			select_poke(sock->manager, sock->threadid, sock->fd,
+				    SELECT_POKE_READ);
+		if ((flags & ISC_SOCKFDWATCH_WRITE) != 0)
+			select_poke(sock->manager, sock->threadid, sock->fd,
+				    SELECT_POKE_WRITE);
+		UNLOCK(&sock->lock);
+	}
+
+	socket_log(sock, NULL, TRACE, "fdwatch-poked flags: %d", flags);
+
+	return (ISC_R_SUCCESS);
+}
