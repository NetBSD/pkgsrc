# $NetBSD: Makefile,v 1.17 2001/02/17 18:19:48 wiz Exp $

DISTNAME=	ttcp
PKGNAME=	${DISTNAME}-1.12
CATEGORIES=	net benchmarks
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.ccci.com/tools/ttcp/
COMMENT=	TCP testing and performance measuring tool

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED_IF_MANZ=	YES
WRKSRC=			${WRKDIR}

.if (${OPSYS} == SunOS)
do-build:
	cd ${WRKSRC} && \
	${CC} ttcp.c ${CFLAGS} $(LDFLAGS) -lsocket -lnsl -o ttcp && \
	nroff -man ttcp.1 >ttcp.cat1
.endif

.include "../../mk/bsd.pkg.mk"
