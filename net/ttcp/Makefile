# $NetBSD: Makefile,v 1.15 2001/01/13 12:37:25 tron Exp $

DISTNAME=	ttcp
PKGNAME=	${DISTNAME}-1.12
CATEGORIES=	net benchmarks
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.ccci.com/tools/ttcp/

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED_IF_MANZ=	YES
WRKSRC=			${WRKDIR}

do-build:
.if (${OPSYS} == SunOS)
	cd ${WRKSRC} && \
	${CC} ttcp.c ${CFLAGS} $(LDFLAGS) -lsocket -lnsl -o ttcp && \
	nroff -man ttcp.1 >ttcp.cat1
.endif

.include "../../mk/bsd.pkg.mk"
