# $NetBSD: Makefile,v 1.19 2006/01/07 06:45:45 schmonz Exp $

DISTNAME=		cdb-0.75
CATEGORIES=		databases
MASTER_SITES=		http://cr.yp.to/cdb/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/cdb.html
COMMENT=		Creates and reads constant databases

CONFLICTS+=		tinycdb-[0-9]*

DJB_RESTRICTED=		YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin include lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/cdb.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/cdb.a ${PREFIX}/lib/libcdb.a

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
