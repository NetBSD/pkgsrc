# $Id: misc.mk,v 1.1.1.1 2015/05/19 21:36:45 joerg Exp $

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
