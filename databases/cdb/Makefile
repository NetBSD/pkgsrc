# $NetBSD: Makefile,v 1.22 2012/10/02 21:25:15 asau Exp $

DISTNAME=		cdb-0.75
CATEGORIES=		databases
MASTER_SITES=		http://cr.yp.to/cdb/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/cdb.html
COMMENT=		Creates and reads constant databases
LICENSE=		public-domain

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=		tinycdb-[0-9]*

DJB_RESTRICTED=		YES

INSTALLATION_DIRS=	bin include lib

do-install:
	for prog in cdbdump cdbget cdbmake cdbstats cdbtest; do \
	${INSTALL_PROGRAM} ${WRKSRC}/$$prog ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/cdbmake-12 ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cdbmake-sv ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cdb.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/cdb.a ${DESTDIR}${PREFIX}/lib/libcdb.a

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
