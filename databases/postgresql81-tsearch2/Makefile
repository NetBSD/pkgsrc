# $NetBSD: Makefile,v 1.3 2007/01/08 18:55:39 adam Exp $

PKGNAME=	postgresql81-tsearch2-${BASE_VERS}
COMMENT=	Tsearch2 contrib module for fulltext indexing in PostgreSQL

DEPENDS+=	postgresql81-server>=${BASE_VERS}:../../databases/postgresql81-server

.include "../../databases/postgresql81/Makefile.common"

BUILD_DIRS=		contrib/tsearch2/snowball
BUILD_DIRS+=		contrib/tsearch2

USE_LIBTOOL=		yes
PKG_LIBTOOL=		${PKG_SHLIBTOOL}

.include "../../databases/postgresql81-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
