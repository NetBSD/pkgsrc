# $NetBSD: Makefile,v 1.2 2005/02/20 21:50:57 cube Exp $

SRCS=	if_tap_lkm.c if_tap.c if_tap_stub.c
KMOD=	tap
WARNS=	3

INCSDIR=	${PREFIX}/include/net
INCS=		if_tap.h

KMODDIR=	${PREFIX}/lkm
MANDIR=		${PREFIX}/man

.if defined(USE_BPF) && !empty(USE_BPF:M[Yy][Ee][Ss])
CPPFLAGS+=	-DNBPFILTER=1
.endif
.if defined(TAP_KERNEL_ENV) && !empty(TAP_KERNEL_ENV)
CPPFLAGS+=	${TAP_KERNEL_ENV}
.endif

install: install-postinstall

install-postinstall:
	${BSD_INSTALL_SCRIPT} tap_postinstall.sh ${PREFIX}/sbin/tap_postinstall

.include <bsd.kinc.mk>
.include <bsd.kmod.mk>
