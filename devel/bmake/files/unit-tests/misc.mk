# $Id: misc.mk,v 1.2 2015/05/19 22:01:19 joerg Exp $

.if !exists(${.CURDIR}/)
.warning ${.CURDIR}/ doesn't exist ?
.endif

.if !exists(${.CURDIR}/.)
.warning ${.CURDIR}/. doesn't exist ?
.endif

.if !exists(${.CURDIR}/..)
.warning ${.CURDIR}/.. doesn't exist ?
.endif

all:
	@: all is well
