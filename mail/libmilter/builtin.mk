# $NetBSD: builtin.mk,v 1.1 2004/06/30 13:48:55 tron Exp $

.if !defined(IS_BUILTIN.libmilter)
IS_BUILTIN.libmilter=	no
.  if exists(/usr/include/libmilter) && exists (/usr/lib/libmilter.a)
IS_BUILTIN.libmilter=	yes
.  endif
.endif	# IS_BUILTIN.libmilter

USE_BUILTIN.libmilter?=	${IS_BUILTIN.libmilter}
