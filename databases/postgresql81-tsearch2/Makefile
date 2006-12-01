# $NetBSD: Makefile,v 1.2 2006/12/01 20:15:12 joerg Exp $

PKGNAME=	postgresql81-tsearch2-${BASE_VERS}
COMMENT=	Tsearch2 contrib module for fulltext indexing in PostgreSQL

DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

.include "../../databases/postgresql81/Makefile.common"

BUILD_DIRS=		${WRKSRC}/contrib/tsearch2/snowball ${WRKSRC}/contrib/tsearch2

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql81-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
