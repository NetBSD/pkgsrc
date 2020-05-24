# $Id: misc.mk,v 1.3 2020/05/24 11:09:44 nia Exp $

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
