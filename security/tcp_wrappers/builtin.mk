# $NetBSD: builtin.mk,v 1.5 2005/05/17 21:53:20 gavan Exp $

.if !defined(IS_BUILTIN.tcp_wrappers)
IS_BUILTIN.tcp_wrappers=	no
.  if exists(/usr/include/tcpd.h) && (exists(/usr/lib${ABI}/libwrap.so) || \
					exists(/usr/lib${ABI}/libwrap.a))
IS_BUILTIN.tcp_wrappers=	yes
.  endif
.endif	# IS_BUILTIN.tcp_wrappers

USE_BUILTIN.tcp_wrappers?=	${IS_BUILTIN.tcp_wrappers}
