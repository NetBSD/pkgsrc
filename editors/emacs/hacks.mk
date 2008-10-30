# $NetBSD: hacks.mk,v 1.1 2008/10/30 03:57:06 minskim Exp $

###
### Workaround for PR 39778
###
.if !empty(MACHINE_PLATFORM:MNetBSD-4.99.*-x86_64)
pre-build:
	${TOUCH} ${WRKSRC}/leim/quail/tsang-b5.el
.endif
