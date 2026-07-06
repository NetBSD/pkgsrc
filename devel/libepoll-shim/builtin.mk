# $NetBSD: builtin.mk,v 1.1 2026/07/06 18:26:17 bsiegert Exp $

BUILTIN_PKG:=	libepoll-shim

.if !defined(IS_BUILTIN.libepoll-shim)
IS_BUILTIN.libepoll-shim=	no
# epoll is built into the Linux kernel/glibc natively.
.  if ${OPSYS} == "Linux"
IS_BUILTIN.libepoll-shim=	yes
.  endif
.endif
MAKEVARS+=			IS_BUILTIN.libepoll-shim

.if !defined(BUILTIN_PKG.libepoll-shim)
.  if !empty(IS_BUILTIN.libepoll-shim:M[yY][eE][sS])
# Fake a high version number since native Linux epoll fulfills all needs.
BUILTIN_PKG.libepoll-shim=	libepoll-shim-99.99
.  endif
.endif
MAKEVARS+=			BUILTIN_PKG.libepoll-shim

.if !defined(USE_BUILTIN.libepoll-shim)
USE_BUILTIN.libepoll-shim=	${IS_BUILTIN.libepoll-shim}
.  if defined(BUILTIN_PKG.libepoll-shim)
.    for _depend_ in ${BUILDLINK_API_DEPENDS.libepoll-shim}
.      if !empty(USE_BUILTIN.libepoll-shim:M[yY][eE][sS])
USE_BUILTIN.libepoll-shim!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.libepoll-shim}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif
MAKEVARS+=			USE_BUILTIN.libepoll-shim

CHECK_BUILTIN.libepoll-shim?=	no
.if !empty(CHECK_BUILTIN.libepoll-shim:M[nN][oO])
.  if !empty(USE_BUILTIN.libepoll-shim:M[yY][eE][sS])
# On Linux, no extra compiler/linker flags are required for epoll.
BUILDLINK_TARGETS+=		libepoll-shim-builtin-noop

.phony: libepoll-shim-builtin-noop
libepoll-shim-builtin-noop:
	@${DO_NADA}
.  endif
.endif
