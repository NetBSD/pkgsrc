# $NetBSD: Makefile,v 1.16 2005/03/23 00:57:20 schmonz Exp $

DISTNAME=		cdb-0.75
CATEGORIES=		databases
MASTER_SITES=		http://cr.yp.to/cdb/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/cdb.html
COMMENT=		Creates and reads constant databases

DJB_RESTRICTED=		YES

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

INSTALLATION_DIRS=	bin include lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/cdb.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/cdb.a ${PREFIX}/lib/libcdb.a

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
