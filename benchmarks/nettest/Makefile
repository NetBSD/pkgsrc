# $NetBSD: Makefile,v 1.6 2007/05/18 21:30:49 heinz Exp $

DISTNAME=	nettest.92.11.09
PKGNAME=	nettest-92.11.09
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.cray.com/src/nettest/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ginsbach@cray.com
COMMENT=	Performs client and server functions for timing data throughput

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/nettest ${DESTDIR:Q}${PREFIX:Q}/bin/nettest
	${INSTALL_PROGRAM} ${WRKSRC:Q}/nettestd ${DESTDIR:Q}${PREFIX:Q}/bin/nettestd
	${INSTALL_MAN} ${WRKSRC:Q}/nettest.8 ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man8/nettest.8

.include "../../mk/bsd.pkg.mk"
