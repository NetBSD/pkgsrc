# $NetBSD: Makefile,v 1.8 2004/02/04 13:33:36 grant Exp $

DISTNAME=		ElectricFence-2.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.perens.com/pub/ElectricFence/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.perens.com/FreeSoftware/
COMMENT=		Different kind of malloc() debugger

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "mipsel"
CFLAGS+=		-g -DPAGE_PROTECTION_VIOLATED_SIGNAL=SIGBUS
.else
CFLAGS+=		-g
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/libefence.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/libefence.3 ${PREFIX}/man/man3

.include "../../mk/bsd.pkg.mk"
