# $NetBSD: Makefile,v 1.11 2005/12/05 20:49:51 rillig Exp $

DISTNAME=	ttcp
PKGNAME=	${DISTNAME}-1.12
PKGREVISION=	2
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.ccci.com/tools/ttcp/
COMMENT=	TCP testing and performance measuring tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}	\
		MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED_IF_MANZ=	YES

.if (${OPSYS} == Darwin)
MAKE_FLAGS+=	CFLAGS="-Din_addr_t=\"unsigned long\""
.endif

INSTALLATION_DIRS=	bin man/cat1 man/man1

.if (${OPSYS} == SunOS)
do-build:
	cd ${WRKSRC} && \
	${CC} ttcp.c ${CFLAGS} ${LDFLAGS} -lsocket -lnsl -o ttcp && \
	nroff -man ttcp.1 >ttcp.cat1
.endif

.include "../../mk/bsd.pkg.mk"
