# $NetBSD: pthread.builtin.mk,v 1.1 2004/11/12 05:20:02 jlam Exp $

.if !defined(_BLNK_LIBPTHREAD_FOUND)
_BLNK_LIBPTHREAD_FOUND!=	\
	if ${TEST} "`${ECHO} /usr/lib/libpthread.*`" = "/usr/lib/libpthread.*"; then \
		${ECHO} "no";						\
	elif ${TEST} "`${ECHO} /lib/libpthread.*`" = "/lib/libpthread.*"; then \
		${ECHO} "no";						\
	else								\
		${ECHO} "yes";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIBPTHREAD_FOUND
.endif
.if !defined(_BLNK_LIBC_R_FOUND)
_BLNK_LIBC_R_FOUND!=	\
	if ${TEST} "`${ECHO} /usr/lib/libc_r.*`" = "/usr/lib/libc_r.*"; then \
		${ECHO} "no";						\
	else								\
		${ECHO} "yes";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIBC_R_FOUND
.endif

.if !defined(IS_BUILTIN.pthread)
IS_BUILTIN.pthread=	no
.  if exists(/usr/include/pthread.h)
IS_BUILTIN.pthread=	yes
.  endif
BUILDLINK_VARS+=	IS_BUILTIN.pthread
.endif	# IS_BUILTIN.pthread

# We ignore the value of PREFER_PKGSRC and PREFER_NATIVE.  Whether we
# prefer one or the other is dependent on the value of
# PREFER_NATIVE_PTHREADS, which is yes/no.
#
.if !empty(PREFER_NATIVE_PTHREADS:M[yY][eE][sS])
USE_BUILTIN.pthread=	${IS_BUILTIN.pthread}
.else
USE_BUILTIN.pthread=	no
.endif

CHECK_BUILTIN.pthread?=	no
.if !empty(CHECK_BUILTIN.pthread:M[nN][oO])

.if !empty(USE_BUILTIN.pthread:M[yY][eE][sS])
BUILDLINK_PREFIX.pthread=	/usr
BUILDLINK_LDFLAGS.pthread=	# empty

# only pass -pthread on platforms known to support it.
# XXX
# XXX This should really be a check for GCC!
# XXX
.  if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
BUILDLINK_CFLAGS.pthread+=	-pthread
BUILDLINK_LDFLAGS.pthread+=	-pthread
.  else
BUILDLINK_CPPFLAGS.pthread+=	-D_REENTRANT
.  endif

# Handle systems which have pthreads functions in libc_r such as
# FreeBSD 5.x, or fall back to libc if we don't find libc_r.
#
.  if ${OPSYS} == "NetBSD"
BUILDLINK_LIBS.pthread=		# empty
.  elif !empty(_BLNK_LIBPTHREAD_FOUND:M[yY][eE][sS])
BUILDLINK_LIBS.pthread=		-lpthread
.  elif !empty(_BLNK_LIBC_R_FOUND:M[yY][eE][sS])
BUILDLINK_LIBS.pthread=		-lc_r
.  else
BUILDLINK_LIBS.pthread=		# empty
.  endif
.endif	# USE_BUILTIN.pthread

.endif	# CHECK_BUILTIN.pthread
