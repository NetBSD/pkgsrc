# $NetBSD: pthread.builtin.mk,v 1.15 2013/11/23 09:10:14 obache Exp $

BUILTIN_PKG:=	pthread

BUILTIN_FIND_LIBS:=		pthread c_r rt
BUILTIN_FIND_HEADERS_VAR=	H_PTHREAD
BUILTIN_FIND_HEADERS.H_PTHREAD=	pthread.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.pthread)
IS_BUILTIN.pthread=	no
.  if empty(H_PTHREAD:M${LOCALBASE}/*) && exists(${H_PTHREAD})
IS_BUILTIN.pthread=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.pthread

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
#
# We ignore the value of PREFER_PKGSRC and PREFER_NATIVE.  Whether we
# prefer one or the other is dependent on the value of
# PREFER_NATIVE_PTHREADS, which is yes/no.
#
.if !defined(USE_BUILTIN.pthread)
USE_BUILTIN.pthread=	${IS_BUILTIN.pthread}
.  if !empty(PREFER_NATIVE_PTHREADS:M[nN][oO])
USE_BUILTIN.pthread=	no
.  endif
.endif
MAKEVARS+=	USE_BUILTIN.pthread

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.pthread?=	no
.if !empty(CHECK_BUILTIN.pthread:M[nN][oO])

.  if !empty(USE_BUILTIN.pthread:M[yY][eE][sS])
BUILDLINK_PREFIX.pthread=	/usr
.    if empty(H_PTHREAD:M__nonexistent__)
.      if!empty(H_PTHREAD:M/usr/*)
BUILDLINK_PREFIX.pthread=	/usr
.      else
BUILDLINK_PREFIX.pthread=	# empty
.      endif
.    endif
BUILDLINK_CFLAGS.pthread=	# empty
BUILDLINK_LDFLAGS.pthread=	# empty

# only pass -pthread on platforms known to support it.
# XXX
# XXX This should really be a check for GCC!
# XXX
BUILDLINK_OPSYS_SUPPORT_PTHREAD=	\
	DragonFly FreeBSD Linux MirBSD NetBSD OpenBSD SunOS
.    if !empty(BUILDLINK_OPSYS_SUPPORT_PTHREAD:M${OPSYS})
BUILDLINK_CFLAGS.pthread+=	-pthread
BUILDLINK_LDFLAGS.pthread+=	-pthread
.    elif ${OPSYS} == "OSF1"
BUILDLINK_CFLAGS.pthread+=	-pthread
CFLAGS+=			-D_REENTRANT
.    else
BUILDLINK_CPPFLAGS.pthread+=	-D_REENTRANT
.    endif
.    if ${OPSYS} == "FreeBSD"
BUILDLINK_CPPFLAGS.pthread+=	-D_THREAD_SAFE
.    endif

# Handle systems which have pthreads functions in libc_r such as
# FreeBSD 5.x, or fall back to libc if we don't find libc_r.
#
.    if ${OPSYS} == "NetBSD"
BUILDLINK_LIBS.pthread=		# empty
.    elif !empty(BUILTIN_LIB_FOUND.pthread:M[yY][eE][sS])
BUILDLINK_LIBS.pthread=		-lpthread
.      if !empty(BUILTIN_LIB_FOUND.rt:M[yY][eE][sS])
BUILDLINK_LIBS.pthread+=	-lrt
.      endif
.    elif !empty(BUILTIN_LIB_FOUND.c_r:M[yY][eE][sS])
BUILDLINK_LIBS.pthread=		-lc_r
.    else
BUILDLINK_LIBS.pthread=		# empty
.    endif
.  endif

.endif	# CHECK_BUILTIN.pthread
