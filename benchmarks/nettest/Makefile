# $NetBSD: Makefile,v 1.5 2007/01/07 09:13:48 rillig Exp $

DISTNAME=	nettest.92.11.09
PKGNAME=	nettest-92.11.09
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.cray.com/src/nettest/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ginsbach@cray.com
COMMENT=	Performs client and server functions for timing data throughput

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/nettest ${PREFIX:Q}/bin/nettest
	${INSTALL_PROGRAM} ${WRKSRC:Q}/nettestd ${PREFIX:Q}/bin/nettestd
	${INSTALL_MAN} ${WRKSRC:Q}/nettest.8 ${PREFIX:Q}/man/man8/nettest.8

.include "../../mk/bsd.pkg.mk"
