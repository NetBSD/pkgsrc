# $NetBSD: Makefile,v 1.6 2003/07/17 21:24:36 grant Exp $

DISTNAME=	ttcp
PKGNAME=	${DISTNAME}-1.12
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	http://www.ccci.com/tools/ttcp/
COMMENT=	TCP testing and performance measuring tool

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
