# $NetBSD: builtin.mk,v 1.1 2004/04/20 08:32:13 xtraeme Exp $

.if !defined(_LIBEVENT_FOUND)
_LIBEVENT_FOUND!=							\
	if [ "`${ECHO} /usr/lib/libevent.*`" = "/usr/lib/libevent.*" ]; then \
		${ECHO} "no";						\
	else								\
		${ECHO} "yes";						\
	fi
BUILDLINK_VARS+=	_LIBEVENT_FOUND
.endif

_EVENT_H=	/usr/include/event.h

.if !defined(IS_BUILTIN.event)
IS_BUILTIN.event=	no
.  if exists(${_EVENT_H})
IS_BUILTIN.event=	yes
.  endif
.endif	# IS_BUILTIN.event

.if !defined(USE_BUILTIN.event)
USE_BUILTIN.event?=	${IS_BUILTIN.event}
PREFER.event?=		pkgsrc

.  if !empty(IS_BUILTIN.event:M[nN][oO]) || \
        (${PREFER.event} == "pkgsrc")
USE_BUILTIN.event=	no
.  endif
.endif	# USE_BUILTIN.event

CHECK_BUILTIN.event?=	no
.if !empty(CHECK_BUILTIN.event:M[nN][oO])
_LIBEVENT=		-levent
BUILDLINK_LDADD.event?=	${_LIBEVENT}
.endif	# CHECK_BUILTIN.event
