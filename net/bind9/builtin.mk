# $NetBSD: builtin.mk,v 1.4 2004/07/19 04:07:16 markd Exp $

.if !defined(IS_BUILTIN.bind)
IS_BUILTIN.bind=	no
.  if exists(/usr/sbin/named)
_BIND_VERSION!=${ECHO} 'vers ' && /usr/sbin/named -v | ${SED} -n 's/^BIND //p'
.  endif
.  if defined(_BIND_VERSION) && !empty(_BIND_VERSION:Nvers)
IS_BUILTIN.bind=	yes
BUILTIN_PKG.bind=	bind-${_BIND_VERSION}
BUILDLINK_VARS+=	BUILTIN_PKG.bind
.  endif
.endif  # IS_BUILTIN.bind
BUILDLINK_VARS+=	IS_BUILTIN.bind

USE_BUILTIN.bind?=	${IS_BUILTIN.bind}
