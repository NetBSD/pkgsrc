# $NetBSD: hacks.mk,v 1.1 2026/06/18 15:11:26 nia Exp $

.if !defined(MICROPYTHON_HACKS_MK)
MICROPYTHON_HACKS_MK=	# defined

### [Thu Jun 18 17:04:43 CEST 2026 : nia]
### Older NetBSD versions do not define PTHREAD_STACK_MIN.
###
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 100000
PKG_HACKS+=		pthread-stack-min
CFLAGS.NetBSD+=		-DPTHREAD_STACK_MIN=4096
.endif

.endif
