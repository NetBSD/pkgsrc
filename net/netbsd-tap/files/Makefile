# $NetBSD: Makefile,v 1.1.1.1 2005/01/20 18:02:40 cube Exp $

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

install: install-postinstall

install-postinstall:
	${BSD_INSTALL_SCRIPT} tap_postinstall.sh ${PREFIX}/sbin/tap_postinstall

.include <bsd.kinc.mk>
.include <bsd.kmod.mk>
