# $NetBSD: Makefile,v 1.9 2004/07/30 10:16:52 he Exp $

DISTNAME=	ttcp
PKGNAME=	${DISTNAME}-1.12
PKGREVISION=	2
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.ccci.com/tools/ttcp/
COMMENT=	TCP testing and performance measuring tool

WRKSRC=		${WRKDIR}
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}	\
		MANOWN=${MANOWN} MANGRP=${MANGRP}

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED_IF_MANZ=	YES

.if (${OPSYS} == Darwin)
MAKE_FLAGS=	CFLAGS="-Din_addr_t=\"unsigned long\""
.endif

.if (${OPSYS} == SunOS)
do-build:
	cd ${WRKSRC} && \
	${CC} ttcp.c ${CFLAGS} ${LDFLAGS} -lsocket -lnsl -o ttcp && \
	nroff -man ttcp.1 >ttcp.cat1
.endif

.include "../../mk/bsd.pkg.mk"
