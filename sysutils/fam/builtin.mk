# $NetBSD: builtin.mk,v 1.1 2005/05/07 21:20:44 jschauma Exp $

.if !defined(IS_BUILTIN.fam)
IS_BUILTIN.fam=	no
.  if exists(/usr/include/fam.h)
IS_BUILTIN.fam=	yes
.  endif
.endif	# IS_BUILTIN.fam

USE_BUILTIN.fam?=	${IS_BUILTIN.fam}
