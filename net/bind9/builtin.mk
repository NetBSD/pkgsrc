# $NetBSD: builtin.mk,v 1.6 2004/09/30 15:07:46 tron Exp $

.if !defined(IS_BUILTIN.bind)
IS_BUILTIN.bind=	no
.  if exists(/usr/sbin/named)
_BIND_VERSION!=${ECHO} 'vers ' && /usr/sbin/named -v | ${SED} -n 's/^BIND //p'
.  endif
.  if defined(_BIND_VERSION) && !empty(_BIND_VERSION:Nvers)
IS_BUILTIN.bind=	yes
BUILTIN_PKG.bind=	bind-${_BIND_VERSION:Nvers}
BUILDLINK_VARS+=	BUILTIN_PKG.bind
.  endif
.endif  # IS_BUILTIN.bind
BUILDLINK_VARS+=	IS_BUILTIN.bind

.if !defined(USE_BUILTIN.bind)
USE_BUILTIN.bind?=	${IS_BUILTIN.bind}
.  if defined(BUILTIN_PKG.bind)
.    for _depend_ in ${BUILDLINK_DEPENDS.bind}
.      if !empty(USE_BUILTIN.bind:M[yY][eE][sS])
USE_BUILTIN.bind!=							\
	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.bind}; then	\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.      endif
.    endfor
.  endif
.endif	# USE_BUILTIN.bind

.if !empty(USE_BUILTIN.bind:M[nN][oO])
BUILDLINK_LDADD.bind?=		-lbind
.endif
