# $NetBSD: Makefile,v 1.1.1.1 2003/04/11 17:05:05 cjep Exp $

DISTNAME=	nettest.92.11.09
PKGNAME=	nettest-92.11.09
CATEGORIES=	benchmarks net
MASTER_SITES=   ftp://ftp.cray.com/src/nettest/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ginsbach@cray.com
COMMENT=	Performs client and server functions for timing data throughput

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nettest ${PREFIX}/bin/nettest
	${INSTALL_PROGRAM} ${WRKSRC}/nettestd ${PREFIX}/bin/nettestd
	${INSTALL_MAN} ${WRKSRC}/nettest.8 ${PREFIX}/man/man8/nettest.8

.include "../../mk/bsd.pkg.mk"
