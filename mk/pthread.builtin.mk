# $NetBSD: pthread.builtin.mk,v 1.7 2005/01/17 08:29:30 jlam Exp $

.for _lib_ in pthread c_r rt
.  if !defined(_BLNK_LIB_FOUND.${_lib_})
_BLNK_LIB_FOUND.${_lib_}!=	\
	if ${TEST} "`${ECHO} /usr/lib/lib${_lib_}.*`" != "/usr/lib/lib${_lib_}.*"; then \
		${ECHO} "yes";						\
	elif ${TEST} "`${ECHO} /lib/lib${_lib_}.*`" != "/lib/lib${_lib_}.*"; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
BUILDLINK_VARS+=	_BLNK_LIB_FOUND.${_lib_}
.  endif
.endfor
.undef _lib_

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
BUILDLINK_CFLAGS.pthread=	# empty
BUILDLINK_LDFLAGS.pthread=	# empty

# only pass -pthread on platforms known to support it.
# XXX
# XXX This should really be a check for GCC!
# XXX
BUILDLINK_OPSYS_SUPPORT_PTHREAD=	DragonFly FreeBSD Linux NetBSD
.  if !empty(BUILDLINK_OPSYS_SUPPORT_PTHREAD:M${OPSYS})
BUILDLINK_CFLAGS.pthread+=	-pthread
BUILDLINK_LDFLAGS.pthread+=	-pthread
.  elif ${OPSYS} == "OSF1"
BUILDLINK_CFLAGS.pthread+=	-pthread
.  else
BUILDLINK_CPPFLAGS.pthread+=	-D_REENTRANT
.  endif
.  if ${OPSYS} == "FreeBSD"
BUILDLINK_CPPFLAGS.pthread+=	-D_THREAD_SAFE
.  endif

# Handle systems which have pthreads functions in libc_r such as
# FreeBSD 5.x, or fall back to libc if we don't find libc_r.
#
.  if ${OPSYS} == "NetBSD"
BUILDLINK_LIBS.pthread=		# empty
.  elif !empty(_BLNK_LIB_FOUND.pthread:M[yY][eE][sS])
BUILDLINK_LIBS.pthread=		-lpthread
.    if !empty(_BLNK_LIB_FOUND.rt:M[yY][eE][sS])
BUILDLINK_LIBS.pthread+=	-lrt
.    endif
.  elif !empty(_BLNK_LIB_FOUND.c_r:M[yY][eE][sS])
BUILDLINK_LIBS.pthread=		-lc_r
.  else
BUILDLINK_LIBS.pthread=		# empty
.  endif
.endif	# USE_BUILTIN.pthread

.endif	# CHECK_BUILTIN.pthread
