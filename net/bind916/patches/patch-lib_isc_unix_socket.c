$NetBSD: patch-lib_isc_unix_socket.c,v 1.8 2022/04/21 14:14:46 taca Exp $

* Apply fixes from NetBSD base system.
* Fix build on SunOS. In this special case, _XOPEN_SOURCE has to be only
  defined on SunOS.

--- lib/isc/unix/socket.c.orig	2022-04-11 15:28:12.000000000 +0000
+++ lib/isc/unix/socket.c
@@ -13,6 +13,15 @@
 
 /*! \file */
 
+/* needed for CMSG_DATA */
+#if defined(__sun)
+#if (__STDC_VERSION__ - 0 < 199901L)
+#define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
+#endif
+
 #include <inttypes.h>
 #include <stdbool.h>
 #include <sys/param.h>
@@ -362,6 +371,10 @@ struct isc_socket {
 	unsigned char overflow; /* used for MSG_TRUNC fake */
 #endif				/* ifdef ISC_PLATFORM_RECVOVERFLOW */
 
+	void			*fdwatcharg;
+	isc_sockfdwatch_t	fdwatchcb;
+	int			fdwatchflags;
+	isc_task_t              *fdwatchtask;
 	unsigned int dscp;
 };
 
@@ -471,6 +484,14 @@ static bool
 process_ctlfd(isc__socketthread_t *thread);
 static void
 setdscp(isc_socket_t *sock, isc_dscp_t dscp);
+static void
+dispatch_recv(isc_socket_t *sock);
+static void
+dispatch_send(isc_socket_t *sock);
+static void
+internal_fdwatch_read(isc_socket_t *sock);
+static void
+internal_fdwatch_write(isc_socket_t *sock);
 
 #define SELECT_POKE_SHUTDOWN (-1)
 #define SELECT_POKE_NOTHING  (-2)
@@ -1575,6 +1596,7 @@ doio_recv(isc_socket_t *sock, isc_socket
 	case isc_sockettype_udp:
 	case isc_sockettype_raw:
 		break;
+	case isc_sockettype_fdwatch:
 	default:
 		UNREACHABLE();
 	}
@@ -1782,9 +1804,26 @@ socketclose(isc__socketthread_t *thread,
 	 */
 	LOCK(&thread->fdlock[lockid]);
 	thread->fds[fd] = NULL;
+	if (sock->type == isc_sockettype_fdwatch)
+		thread->fdstate[fd] = CLOSED;
+	else
 	thread->fdstate[fd] = CLOSE_PENDING;
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
 
@@ -2191,6 +2230,13 @@ again:
 			}
 #endif /* if defined(PF_ROUTE) */
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
@@ -2440,6 +2486,7 @@ socket_create(isc_socketmgr_t *manager, 
 
 	REQUIRE(VALID_MANAGER(manager));
 	REQUIRE(socketp != NULL && *socketp == NULL);
+	REQUIRE(type != isc_sockettype_fdwatch);
 
 	result = allocate_socket(manager, type, &sock);
 	if (result != ISC_R_SUCCESS) {
@@ -2553,6 +2600,7 @@ isc_socket_open(isc_socket_t *sock) {
 	REQUIRE(isc_refcount_current(&sock->references) >= 1);
 	REQUIRE(sock->fd == -1);
 	REQUIRE(sock->threadid == -1);
+	REQUIRE(sock->type != isc_sockettype_fdwatch);
 
 	result = opensocket(sock->manager, sock, NULL);
 
@@ -2631,6 +2679,7 @@ isc_socket_close(isc_socket_t *sock) {
 
 	LOCK(&sock->lock);
 
+	REQUIRE(sock->type != isc_sockettype_fdwatch);
 	REQUIRE(sock->fd >= 0 && sock->fd < (int)sock->manager->maxsocks);
 
 	INSIST(!sock->connecting);
@@ -2661,6 +2710,24 @@ isc_socket_close(isc_socket_t *sock) {
 	return (ISC_R_SUCCESS);
 }
 
+static void
+dispatch_recv(isc_socket_t *sock) {
+	if (sock->type != isc_sockettype_fdwatch) {
+		internal_recv(sock);
+	} else {
+		internal_fdwatch_read(sock);
+	}
+}
+
+static void
+dispatch_send(isc_socket_t *sock) {
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
@@ -3101,6 +3168,58 @@ finish:
 	}
 }
 
+static void
+internal_fdwatch_write(isc_socket_t *sock)
+{
+	int more_data;
+
+	INSIST(VALID_SOCKET(sock));
+
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
+}
+
+static void
+internal_fdwatch_read(isc_socket_t *sock)
+{
+	int more_data;
+
+	INSIST(VALID_SOCKET(sock));
+
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
+}
+
 /*
  * Process read/writes on each fd here.  Avoid locking
  * and unlocking twice if both reads and writes are possible.
@@ -3148,7 +3267,7 @@ process_fd(isc__socketthread_t *thread, 
 		if (sock->connecting) {
 			internal_connect(sock);
 		} else {
-			internal_send(sock);
+			dispatch_send(sock);
 		}
 	}
 
@@ -3156,7 +3275,7 @@ process_fd(isc__socketthread_t *thread, 
 		if (sock->listener) {
 			internal_accept(sock); /* unlocks sock */
 		} else {
-			internal_recv(sock);
+			dispatch_recv(sock);
 			UNLOCK(&sock->lock);
 		}
 	} else {
@@ -3797,7 +3916,7 @@ isc_socketmgr_create2(isc_mem_t *mctx, i
 		isc_thread_create(netthread, &manager->threads[i],
 				  &manager->threads[i].thread);
 		char tname[1024];
-		sprintf(tname, "isc-socket-%d", i);
+		sprintf(tname, "socket-%d", i);
 		isc_thread_setname(manager->threads[i].thread, tname);
 	}
 
@@ -5218,7 +5337,7 @@ static isc_once_t hasreuseport_once = IS
 static bool hasreuseport = false;
 
 static void
-init_hasreuseport() {
+init_hasreuseport(void) {
 /*
  * SO_REUSEPORT works very differently on *BSD and on Linux (because why not).
  * We only want to use it on Linux, if it's available. On BSD we want to dup()
@@ -5272,6 +5391,8 @@ _socktype(isc_sockettype_t type) {
 		return ("tcp");
 	case isc_sockettype_unix:
 		return ("unix");
+	case isc_sockettype_fdwatch:
+		return ("fdwatch");
 	default:
 		return ("not-initialized");
 	}
@@ -5502,3 +5623,113 @@ error:
 	return (result);
 }
 #endif /* HAVE_JSON_C */
+
+/*
+ * Create a new 'type' socket managed by 'manager'.  Events
+ * will be posted to 'task' and when dispatched 'action' will be
+ * called with 'arg' as the arg value.  The new socket is returned
+ * in 'socketp'.
+ */
+isc_result_t
+isc_socket_fdwatchcreate(isc_socketmgr_t *manager, int fd, int flags,
+			 isc_sockfdwatch_t callback, void *cbarg,
+			 isc_task_t *task, isc_socket_t **socketp)
+{
+	isc_socket_t *sock = NULL;
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
+	manager->epoll_events[sock->fd] = 0;
+#endif
+#ifdef USE_DEVPOLL
+	INSIST(thread->fdpollinfo[sock->fd].want_read == 0 &&
+	       thread->fdpollinfo[sock->fd].want_write == 0);
+#endif /* ifdef USE_DEVPOLL */
+	UNLOCK(&thread->fdlock[lockid]);
+
+	LOCK(&manager->lock);
+	ISC_LIST_APPEND(manager->socklist, sock, link);
+#ifdef USE_SELECT
+	if (thread->maxfd < sock->fd)
+		thread->maxfd = sock->fd;
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
+isc_socket_fdwatchpoke(isc_socket_t *sock, int flags)
+{
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
