# $NetBSD: builtin.mk,v 1.2 2004/04/20 08:43:33 xtraeme Exp $

.if !defined(IS_BUILTIN.libevent)
IS_BUILTIN.libevent=	no
.  if exists(/usr/include/event.h)
IS_BUILTIN.libevent=	yes
.  endif
.endif	# IS_BUILTIN.libevent

USE_BUILTIN.libevent?=	${IS_BUILTIN.libevent}
