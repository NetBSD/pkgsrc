# $NetBSD: builtin.mk,v 1.1.1.1 2004/08/30 20:53:20 adrianp Exp $

.if !defined(IS_BUILTIN.libmilter)
IS_BUILTIN.libmilter=	no
.  if exists(/usr/include/libmilter) && exists (/usr/lib/libmilter.a)
IS_BUILTIN.libmilter=	yes
.  endif
.endif	# IS_BUILTIN.libmilter

.if !defined(USE_BUILTIN.libmilter)
USE_BUILTIN.libmilter?=	${IS_BUILTIN.libmilter}

.  if defined(BUILTIN_PKG.libmilter)
USE_BUILTIN.libmilter=	yes
.    for _depend_ in ${BUILDLINK_DEPENDS.libmilter}
.      if !empty(USE_BUILTIN.libmilter:M[yY][eE][sS])
USE_BUILTIN.libmilter!=	\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.libmilter}; then \
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.libmilter

