# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:00 wiz Exp $

DISTNAME=	nettest.92.11.09
PKGNAME=	nettest-92.11.09
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.cray.com/src/nettest/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ginsbach@cray.com
COMMENT=	Performs client and server functions for timing data throughput

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/nettest ${DESTDIR:Q}${PREFIX:Q}/bin/nettest
	${INSTALL_PROGRAM} ${WRKSRC:Q}/nettestd ${DESTDIR:Q}${PREFIX:Q}/bin/nettestd
	${INSTALL_MAN} ${WRKSRC:Q}/nettest.8 ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man8/nettest.8

.include "../../mk/bsd.pkg.mk"
