# $NetBSD: Makefile,v 1.4 2003/03/19 13:12:22 tron Exp $

DISTNAME=	ttcp
PKGNAME=	${DISTNAME}-1.12
PKGREVISION=	1
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.ccci.com/tools/ttcp/
COMMENT=	TCP testing and performance measuring tool

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED_IF_MANZ=	YES
WRKSRC=			${WRKDIR}

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
