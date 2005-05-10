# $NetBSD: builtin.mk,v 1.3 2005/05/10 02:41:15 jschauma Exp $

.if !defined(IS_BUILTIN.tcp_wrappers)
IS_BUILTIN.tcp_wrappers=	no
.  if exists(/usr/include/tcpd.h) && exists(/usr/lib${ABI}/libwrap.so)
IS_BUILTIN.tcp_wrappers=	yes
.  endif
.endif	# IS_BUILTIN.tcp_wrappers

USE_BUILTIN.tcp_wrappers?=	${IS_BUILTIN.tcp_wrappers}
